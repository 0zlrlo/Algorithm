#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>

// 페이지 교체 알고리즘에 필요한 FIFO 큐 구현
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

bool isFull(struct Queue* queue) {
    return (queue->size == (int)queue->capacity);
}

bool isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// FIFO 페이지 교체 알고리즘 구현
void fifoPageReplacement(int pageSize, int referenceString[], int referenceLength, int totalFrame, FILE* outputFile) {
    struct Queue* queue = createQueue(totalFrame);
    int frames[totalFrame]; // 프레임 배열 초기화
    for (int i = 0; i < totalFrame; i++) {
        frames[i] = -1; // -1은 프레임이 비어있음을 나타냅니다.
    }
    // 페이지와 프레임 번호를 추적할 매핑
    int pageToFrameMap[referenceLength];
    for (int i = 0; i < referenceLength; i++) {
        pageToFrameMap[i] = -1;  // 초기화
    }

    int currentPage;
    int pageNumber, frameNumber = 0;
    int pageFaults = 0;
    bool isPageFault;

    for (int i = 0; i < referenceLength; i++) {
        currentPage = referenceString[i];
        pageNumber = currentPage / pageSize;
        isPageFault = true;

        // 프레임에서 현재 페이지가 이미 있는지 확인합니다.
        for (int j = 0; j < totalFrame; j++) {
            if (frames[j] == pageNumber) {
                isPageFault = false; // 페이지 히트 발생
                break;
            }
        }

        // 페이지 폴트가 발생했으면 새 페이지를 프레임에 할당합니다.
        if (isPageFault) {
            // 큐가 가득 찼는지 확인합니다. 가득 찼으면, 가장 오래된 페이지를 제거합니다.
            if (isFull(queue)) {
                int dequeuedPage = dequeue(queue); // 가장 오래된 페이지를 큐에서 제거
                for (frameNumber = 0; frameNumber < totalFrame; frameNumber++) {
                    if (frames[frameNumber] == dequeuedPage) {
                        frames[frameNumber] = pageNumber; // 새 페이지로 교체
                        break;
                    }
                }
            } else {
                for (frameNumber = 0; frameNumber < totalFrame; frameNumber++) {
                    if (frames[frameNumber] == -1) { // 빈 프레임을 찾음
                        frames[frameNumber] = pageNumber;
                        pageToFrameMap[pageNumber] = frameNumber;
                        break;
                    }
                }
            }
            enqueue(queue, pageNumber); // 새 페이지를 큐에 추가
            pageFaults++;
        }
        else {
            frameNumber = pageToFrameMap[pageNumber];  // 히트시 기존 프레임 인덱스 사용
        }

        int physicalAddress = frameNumber * pageSize + (currentPage % pageSize);

        // 결과를 출력 파일에 기록합니다.
        fprintf(outputFile, "No. %d     V.A. %d     Page No. %d     Frame No. %d        P.A. %d     Page Fault %s\n",
                i + 1,
                currentPage,
                pageNumber, 
                frameNumber, // 히트시 0, 폴트시 새 프레임 번호
                physicalAddress, // 물리 주소도 간소화된 예입니다.
                isPageFault ? "F" : "H");
    }

    // 총 페이지 폴트 수를 출력합니다.
    fprintf(outputFile, "Total Number of Page Faults: %d\n", pageFaults);

    // 큐 메모리 해제
    free(queue->array);
    free(queue);
}

int main(){
    int virtualAddressLength;
    int pageSize;
    int physicalMemorySize;
    int algo;
    int inputMethod;

    int referenceLength = 5000; // 참조 스트링의 길이
    int referenceString[referenceLength]; // 참조 스트링 배열
    char fileName[100] = "input.in"; // 파일 이름
    FILE *file; // 파일 포인터

    printf("A. Simulation에 사용할 가상주소의 길이를 선택하시오 (1. 18bits  2. 19bits  3. 20bits):");
    scanf("%d", &virtualAddressLength);
    printf("B. Simulation에 사용할 페이지(프레임)의 크기를 선택하시오 (1. 1KB  2. 2KB  3. 4KB):");
    scanf("%d", &pageSize);
    printf("C. Simulation에 사용할 물리 메모리의 크기를 선택하시오 (1. 32KB  2. 64KB):");
    scanf("%d", &physicalMemorySize);
    printf("D. Simulation에 적용할 Page Replacement 알고리즘을 선택하시오\n (1. Optimal  2. FIFO  3. LRU  4. Second-Chance):");
    scanf("%d", &algo);
    printf("E. 가상주소 스트링 입력방식을 선택하시오\n(1. input.in 자동 생성  2. 기존 파일 사용):");
    scanf("%d",&inputMethod);

    if(inputMethod ==2){
    printf("F. 입력 파일 이름을 입력하시오: ");
    scanf("%s", fileName); // 파일 이름 입력 받기

        FILE *file = fopen(fileName, "r"); // 파일 열기
        if (file == NULL) {
            perror("파일을 열 수 없습니다");
            exit(EXIT_FAILURE);
        }
        // 참조 스트링을 파일로부터 읽어 배열에 저장
        for (int i = 0; i < referenceLength && fscanf(file, "%d", &referenceString[i]) != EOF; i++) {
            // 파일에서 참조 스트링을 읽음
        }

        fclose(file); // 파일 닫기
    }
    if (inputMethod == 1) {
        // 랜덤 참조 스트링 생성 및 input.in 파일에 저장
        file = fopen(fileName, "w"); // 파일 쓰기 모드로 열기
        if (file == NULL) {
            perror("파일을 열 수 없습니다");
            exit(EXIT_FAILURE);
        }
        srand(time(NULL)); // 난수 생성기 초기화
        for (int i = 0; i < referenceLength; i++) {
            int virtualAddress = rand(); // 랜덤 가상 주소 생성
            fprintf(file, "%d\n", virtualAddress); // 파일에 한 줄씩 쓰기
        }

        // input.in 파일에서 참조 스트링 읽기
        file = fopen(fileName, "r"); // 파일 읽기 모드로 열기
        for (int i = 0; i < referenceLength && fscanf(file, "%d", &referenceString[i]) != EOF; i++) {
            // 파일에서 참조 스트링을 읽음
        }
        fclose(file); // 파일 닫기
    }

    // FIFO 페이지 교체 알고리즘 실행 및 결과 출력
    if (algo == 2) {
        FILE* outputFile = fopen("output.fifo", "w");
        if (!outputFile) {
            perror("output.fifo 파일을 열 수 없습니다");
            exit(EXIT_FAILURE);
        }

        fifoPageReplacement(pageSize, referenceString, referenceLength, physicalMemorySize / pageSize, outputFile);

        fclose(outputFile);
    }
    if(algo ==1){
        FILE* outputFile = fopen("output.opt", "w");
        if (!outputFile) {
            perror("output.opt 파일을 열 수 없습니다");
            exit(EXIT_FAILURE);
        }
       // 코드 넣기
        fclose(outputFile);
    }

    return 0;
}
