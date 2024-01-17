#include <stdio.h>
#include <string.h>
int main(){
    int def = 64;
    int x;
    scanf("%d", x); 
    int k = x/2;
     /*
     x는 48.
     64 길이의 막대가 있음 
     이걸 2등분 하면 32 32임
     여기서 하나를 버리고 하나만 남기기
     그러면 64와 32 두개의 막대가 남게 되는데 이들을 합하면 48보다 큼
     그럼 한 번 더 자르기
     16 16
     16+32->48*/

    return 0;
}