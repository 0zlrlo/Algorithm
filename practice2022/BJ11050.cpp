#include <iostream>
using namespace std;
//이항계수 출력
int factorial(int A){
    if(A==0||A==1){
        return 1;
    }
    else{
    return A*factorial(A-1);
    }
}
int main(){
    int N,K;
    cin>>N>>K;  //자연수, 정수  
    cout<< factorial(N)/(factorial(K)*factorial(N-K));  //괄호 잘 표시하기!

    return 0;
}