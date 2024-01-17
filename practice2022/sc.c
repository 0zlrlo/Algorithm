#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// 페이지가 있다면 secondChance 비트를 true로 변경
bool findAndUpdate(int x, int arr[], bool secondChance[], int frames) {
    for (int i = 0; i < frames; i++) {
        if (arr[i] == x) {
            secondChance[i] = true;
            // 페이지가 hit
            return true;
        }
    }
    return false;
}

// 메모리 안에 페이지를 업데이트, 업데이트한 포인터를 반환
int replaceAndUpdate(int x, int arr[], bool secondChance[], int frames, int *pointer) {
    int currentPointer = *pointer;
    while (true) {
        // SecondeChance 비트가 false, 즉 0이라면 페이지를 교체하고 포인터 반환
        if (!secondChance[currentPointer]) {
            arr[currentPointer] = x;

            *pointer = (currentPointer + 1) % frames;
            return *pointer;
        }

        // 기회가 두 번 있기에 SecondeChance 비트가 true라면 false로 바꿈
        secondChance[currentPointer] = false;

        currentPointer = (currentPointer + 1) % frames;
    }
}

void printHitsAndFaults(char *referenceString, int frames) {
    int pointer = 0;
    int pageFault = 0;
    int arr[frames];
    bool secondChance[frames];

    // 초기화
    for (int i = 0; i < frames; i++) {
        arr[i] = -1;
        secondChance[i] = false;
    }

    int x;
    char *token = strtok(referenceString, " ");
    int line_number = 1;
    while (token != NULL) {
        sscanf(token, "%d", &x);

        if (!findAndUpdate(x, arr, secondChance, frames)) { // miss라면 if문 조건문 만족
            replaceAndUpdate(x, arr, secondChance, frames, &pointer);
            pageFault++;
        }

        token = strtok(NULL, " ");
        printf("line_number %d, page no. %ld pointer: %d\n", line_number++, x, pointer);
        for (int i = 0; i < frames; i++) {
            printf("%d ", secondChance[i]);
        }
        printf("\n");
        for (int i = 0; i < frames; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }

    printf("Total page faults were %d\n", pageFault);
}

int main() {
    char referenceString[] = "1 2 3 3 5 3 1 3 3 7 100 3 6 1 100";
    int frames = 3;

    // 9번의 page fault
    printHitsAndFaults(referenceString, frames);

    return 0;
}