#include <string>
#include <vector>

using namespace std;
/*
조건을 만족하는 최대 정수 반환
*/
int factorial(int num){
    if(num<=1){
        return 1;
    }
    return num*factorial(num-1);
}
int solution(int n) {
    int answer = 0;
    // 1부터 10 사이가 결과
    for(int i=1;i<=10;i++){
        if(factorial(i)>n){
            answer = i-1;
            break;
        }else{
            answer = i;
        }
    }
    return answer;
}