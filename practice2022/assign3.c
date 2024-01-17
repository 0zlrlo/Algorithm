#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/time.h>
#include <sched.h>
#include <string.h>
#include <sys/resource.h>
#include <time.h>
#include <mqueue.h>

#define NUM_PROCESSES 21
#define SIZE 100
#define MSG_QUEUE_NAME "/my_message_queue"
#define MSG_BUFFER_SIZE 64
mqd_t msg_queue;

char* timeConvert(struct timeval tv) {
    static char buffer[20];
    struct tm tm_info;
    time_t seconds = tv.tv_sec;
    int micros = tv.tv_usec;

    // struct timeval의 tv_usec은 마이크로초 (1/1,000,000 초) 단위이므로 초 단위로 변환
    seconds += micros / 1000000;
    micros %= 1000000;

    // struct tm 구조체 초기화
    gmtime_r(&seconds, &tm_info);

    // 시간 정보를 "HH:MM:SS.uuuuuu" 형식으로 문자열로 변환
    snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d.%06d", tm_info.tm_hour, tm_info.tm_min, tm_info.tm_sec, micros);
    
    return buffer;
}

double timeDiff(struct timeval start, struct timeval end) {
    return (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1e6;
}

// 배열 곱셈 함수
void matrixMultiplication() {
    // 배열 A와 B, 그리고 결과 배열 result 정의
    int A[SIZE][SIZE] = {0};
    int B[SIZE][SIZE] = {0};
    int result[SIZE][SIZE] = {0};
    int count = 0;
    while(count<100){
        for (int k = 0; k < SIZE; k++) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    result[k][j] += A[k][i] * B[i][j];
                        }
                    }
                }
            count++;
        }
}

// CFS_NICE 
void createCFSNiceProcesses() {
    int nice_values[] = {-20, -20, -20, -20, -20, -20, -20, 0, 0, 0, 0, 0, 0, 0, 19, 19, 19, 19, 19, 19, 19};
    for (int i = 0; i < NUM_PROCESSES; i++) {
        pid_t pid = fork(); // 자식 프로세스 생성
        if (pid == 0) {
            nice(nice_values[i]);
            
            struct timeval start, end;
            gettimeofday(&start, NULL);

            matrixMultiplication();
            sleep(1);
            gettimeofday(&end, NULL);

            double elapsed_time = timeDiff(start, end);
            char msg_buffer[MSG_BUFFER_SIZE];
            snprintf(msg_buffer, MSG_BUFFER_SIZE, "%f %d", elapsed_time, nice_values[i]); // NICE 값을 함께 저장

            mq_send(msg_queue, msg_buffer, strlen(msg_buffer), 0);

            // 프로세스 정보 출력
            printf("PID: %d | NICE: %d | Start time = %s | End time = %s | Elapsed time: %f\n", getpid(), nice_values[i], timeConvert(start), timeConvert(end), elapsed_time);

            exit(0);
        }
    }
}

// RT_RR 
void createRTRRProcesses(int real_choice, int timeslice) {
    struct sched_param sp;
    sp.sched_priority = sched_get_priority_max(real_choice);

    if (sched_setscheduler(0, real_choice, &sp) == -1) {
        perror("sched_setscheduler failed");
        exit(1);
    }

    // timeslice를 밀리초에서 마이크로초로 변환하여 설정
    struct timespec ts;
    ts.tv_sec = timeslice / 1000;
    ts.tv_nsec = (timeslice % 1000) * 1000000;

    if (sched_rr_get_interval(0, &ts) != 0) {
        perror("sched_rr_set_interval");
        exit(1);
    }
}

int main() {
    int choice;
    int real_choice;
    int timeslice;
    int core_id = 0;
    struct sched_param sp;
    struct mq_attr mq_attributes;

    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(core_id, &set);

    // 현재 프로세스에 CPU 코어 세트를 설정
    if (sched_setaffinity(0, sizeof(cpu_set_t), &set) == -1) {
        perror("sched_setaffinity");
        return 1;
    }

    mq_attributes.mq_maxmsg = 10;  // 최대 메시지 수
    mq_attributes.mq_msgsize = MSG_BUFFER_SIZE;  // 메시지 버퍼 크기
    msg_queue = mq_open(MSG_QUEUE_NAME, O_CREAT | O_RDWR, 0666, &mq_attributes);

    printf("Input the scheduling Policy to apply: \n");
    printf("1. CFS_DEFAULT\n");
    printf("2. CFS_NICE\n");
    printf("3. RT_FIFO\n");
    printf("4. RT_RR\n");
    printf("0. Exit\n");
    scanf("%d", &choice);
    
    if (choice < 0 || choice > 4) {
        printf("올바른 선택이 아닙니다.\n");
        return 1;
    }

    // 선택한 스케줄링 정책에 따라 프로세스 생성
    switch (choice) {
        case 0:
            // 프로그램 종료
            exit(0);
            break;
        case 1:
            real_choice = SCHED_OTHER;  // 기존의 리눅스에 있는 것들 이용
            break;
        case 2:
            real_choice = SCHED_OTHER;
            break;
        case 3:
            real_choice = SCHED_FIFO;
            break;
        case 4:
            real_choice = SCHED_RR;
            printf("Choose a time slice for RT_RR (ex) 10, 100, 1000 ms): ");
            scanf("%d", &timeslice);
            break;
        default:
            printf("올바른 선택이 아닙니다. 기본값인 CFS_DEFAULT를 사용합니다.\n");
            real_choice = SCHED_OTHER;
            choice = 1;
            break;
    }

    if (choice == 2) {
        createCFSNiceProcesses();
    }else{
        for (int i = 0; i < NUM_PROCESSES; i++) {
            pid_t pid = fork(); // 자식 프로세스 생성
            if(pid == 0){
                struct timeval start, end;
                gettimeofday(&start, NULL);
                if (choice == 4) {
                    createRTRRProcesses(real_choice, timeslice);
                } else {
                    sp.sched_priority = sched_get_priority_max(real_choice);
                }
                matrixMultiplication();
                sleep(1);
                gettimeofday(&end, NULL);

                double elapsed_time = timeDiff(start, end);
                char msg_buffer[MSG_BUFFER_SIZE];
                snprintf(msg_buffer, MSG_BUFFER_SIZE, "%f", elapsed_time);
                mq_send(msg_queue, msg_buffer, strlen(msg_buffer), 0);
                if (choice == 2) {
                    int nice_value = getpriority(PRIO_PROCESS, 0);
                    printf("PID: %d | NICE: %d | Start time:  %s | End time:  %s | Elapsed time: %f\n", getpid(), nice_value, timeConvert(start), timeConvert(end), elapsed_time);
                } else {
                    printf("PID: %d | Start time:  %s | End time:  %s | Elapsed time: %f\n", getpid(), timeConvert(start), timeConvert(end), elapsed_time);
                }
                exit(0);
                }
            }
        }

    double total_time = 0.0;
    double child_time;
    char msg_buffer[MSG_BUFFER_SIZE];

    for (int i = 0; i < NUM_PROCESSES; i++) {
        mq_receive(msg_queue, msg_buffer, MSG_BUFFER_SIZE, NULL);
        child_time = atof(msg_buffer);
        total_time += child_time;
        wait(NULL);
    }

    mq_close(msg_queue);
    mq_unlink(MSG_QUEUE_NAME);

    double average_time = total_time / NUM_PROCESSES;
    if (choice == 1){
        printf("Scheduling Policy: CFS_DEFAULT | ");
    }
    if (choice == 2){
        printf("Scheduling Policy: CFS_NICE | ");
    }
    if (choice == 3){
        printf("Scheduling Policy: RT_FIFO | ");
    }
    if (choice == 4){
        printf("Scheduling Policy: RT_RR | Time Quantum: %d ms | ", timeslice);
    }
    printf("Average elapsed time: %f\n", average_time);

    return 0;
    
}