#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
    /*
1. 읽었는데 부호가 있으면 2번인 것. 끝까지 읽었는데 부호가 없으면 1번인 것.
2. 부호가 + 이면 minus 시스템콜 호출. - 이면 add 시스템콜 호출.
3. 공백 무시하게끔.
4. 음수, 정수, 실수 입력시 wrong input!
5. 아무것도 입력이 안되면 출력 종료하기.
6. 배열 다시 정수로 바꾸기
7. 여기서 input 받기 -> O
8. 123+-124 처리...
*/

/*
[2번]
1. 문자열이었던 걸 숫자로 바꿔서 계산할 수 있게끔 해주기
2. add 시스템콜, minus 시스템콜 각각 두개 만들기(vi ~ 이걸 두개 한다는 뜻)
*/

/*
	001 + 2421 =-2420
	0123456789 =9876543210
	abcde =wrong
	10_000_000 =wrong
	10a10 +100 =wrong
	1048+4920 =-3872
	9876543210 =0123456789
	10b102=wrong
	2030+130-29349=wrong
	1020384++1024=wrong
	1234 + 1234 - 1234 - 1234=wrong
	001           + 2=-1
	11    +3 =8
	1028 +a1204 + 192-10=wron g
	-23=wrong
	01234 +  - 1234	=wrong
	125 +=wrong
	1.24 + 3.134=wrong
    21 +=wrong
	120+0=wrong
*/

// 123       + 49
// 123 + 49 -> 숫자 부호 끊어서 저장. 
// 123을 다른 곳에 저장. 애초에 다 바꾸기
// 부호가 나오면 바꾸고, 부호 다음에 부호가 나오면 

// 123-+49
// 123 - + 49
// 1번
long reverse_number(char __user* number, char __user* result) {
    char str[100];
    char rev[100];

    // number를 사용자 공간에서 커널 공간으로 복사
     if (copy_from_user(str, number, 100)) {
        return -EFAULT; // 복사 오류 처리
    }

    int len = strlen(str); 

    int i;
    for (i = 0; i < len; i++) {
        rev[i] = str[len - 1 - i];
    }
    rev[len] = '\0'; 

    // 결과를 사용자 공간으로 복사 (길이에 1을 더해야 함)
    if (copy_to_user(result, rev, len + 1)) {
        return -EFAULT; // 복사 오 류 처리
    }

    printk("Output: %s\n", rev);
    return 0;
}
// 2번 - 덧셈 함수
long add(int num1, int num2) {
    return num1 + num2;
}

// 2번 - 뺄셈 함수
long minus(int num1, int num2) {
    return num1 - num2;
}

// test.c
char **split(char *arr2) {
    if (arr2 == NULL) {
        return NULL;
    }

    char **splitnum = (char **)malloc(sizeof(char *) * 3);

    if (splitnum == NULL) {
        return NULL; // 동적 메모리 할당 실패
    }

    char *number1 = NULL;
    char operator[2]; // 연산자를 문자열로 저장
    char *number2 = NULL;

    for (int i = 0; arr2[i] != '\0'; i++) {
        if (arr2[i] == '+' || arr2[i] == '-') {
            operator[0] = arr2[i];
            operator[1] = '\0'; // 문자열의 끝을 나타내는 널 문자
            break;
        }
    }

    // 연산자를 찾지 못한 경우 처리
    if (operator[0] == '\0') {
        free(splitnum);
        return NULL;
    }

    number1 = strndup(arr2, strchr(arr2, operator[0]) - arr2); 
    number2 = strdup(strchr(arr2, operator[0]) + 1);

    // 숫자2에 '+' 또는 '-' 연산자가 있는 경우 처리
    for (int i = 0; number2[i] != '\0'; i++) {
        if (number2[i] == '+' || number2[i] == '-') {
            printf("Wrong Input!\n");
            free(number1);
            free(number2);
            free(splitnum);
            return NULL;
        }
    }
    // 결과 배열에 숫자와 연산자를 저장
    splitnum[0] = number1;
    splitnum[1] = operator; // 연산자를 문자열로 저장
    splitnum[2] = number2;

    // 숫자 문자열을 double로 변환
    int num1 = atoi(splitnum[0]);
    int num2 = atoi(splitnum[2]);
    long result = 0;

    if(num1==0||num2==0){
        printf("Wrong Input!\n");
    }else{
        // 연산자에 따라 연산 수행
        if (strcmp(operator, "+") == 0) {
            if (strcmp(operator, "+") == 0) {
                if (num1 < num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
        result = num1-num2;
        printf("Output:-%ld\n",result);
    }else{
            result = syscall(450, num1, num2);  // minus 시스템 콜 호출
            printf("Output: %ld\n",result);
    }

        } else if (strcmp(operator, "-") == 0) {
            result = syscall(451,num1, num2);  // add 시스템 콜 호출
            printf("Output: %ld\n",result);
        } 
        }
    return 0;
}

// test.c
char *remove_space(char *arr) {
    char *result = NULL;
    int result_idx = 0;

    if (arr == NULL) {
        return NULL;
    }

    int arr_len = strlen(arr);

    // 계산할 문자열의 최대 길이는 입력 문자열의 길이와 같다.
    result = (char *)malloc(sizeof(char) * (arr_len + 1));

    if (result == NULL) {
        return NULL; // 동적 메모리 할당 실패
    }

    for (int i = 0; i < arr_len; i++) {
        if (arr[i] == ' ') {
            continue; // 공백은 무시
        } else if ((arr[i] >= '0' && arr[i] <= '9') || arr[i] == '+' || arr[i] == '-') {
            result[result_idx++] = arr[i];
        } else {
            free(result); // 메모리 해제
            printf("Wrong Input!\n");
            return NULL; // 유효하지 않은 문자가 발견됨
        }
    }

    result[result_idx] = '\0'; // 문자열 끝에 null 문자 추가

    return result;
}

int main() {
    while (1) {
        char input[1000];
        char result_buffer[1000]; // 결과를 저장할 버퍼

        printf("Input: ");
        fgets(input, sizeof(input), stdin);

        // 개행 문자를 제거
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            break;
        }

        char *cleaned_input = remove_space(input);

        if (cleaned_input != NULL) {
            bool has_operator = false;

            // 부호 여부
            for (int i = 0; cleaned_input[i] != '\0'; i++) {
                if (cleaned_input[i] == '+' || cleaned_input[i] == '-') {
                    has_operator = true;
                    break;
                }
            }

            if (!has_operator) {
                // 부호가 없는 경우
                int num = atoi(cleaned_input); // cleaned_input을 정수로 변환
                if (num == 0) {
                    printf("Wrong Input!\n");
                } else {
                    long result_value = syscall(449, cleaned_input, result_buffer);
                    if (result_value == 0) {
                        printf("Output: %s\n", result_buffer);
                    } else {
                        printf("Wrong Input!\n");
                    }
                }
            } else {
                // 부호가 있는 경우
                split(cleaned_input);
            }
        }
        free(cleaned_input);
    }
    return 0;
}