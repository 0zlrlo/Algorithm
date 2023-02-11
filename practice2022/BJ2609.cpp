#include <iostream>
#include <string.h>

using namespace std;

int gcd(int a, int b){
    int tmp;
    if(b<a){
        while(tmp!=0){
        tmp=a%b;
        tmp=b%tmp;
        }
        return tmp;
    }
    else{
        while(tmp!=0){
            tmp=b%a;
            tmp=a%tmp;
        }
        return tmp;
    }
    }

int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}

int main(){

    int a, b;
    cin>>a>>b;
    cout<< gcd(a,b)<<"\n"<<lcm(a,b);
}
//런타임에러 발생,,


//최대공약수, 최소공배수 출력
//최대공약수 구하는 법-> 유클리드 호제법
/*
큰 숫자를 작은 숫자로 mod연산을 한다.
작은 숫자를 1번에서 구한 나머지 mod연산을 한다.
위 과정을 mod연산의 결과가 0이 나올때 까지 계속 반복한다.
이때 나누는 수로 사용된 수가 두 수의 최대공약수가 된다.
*/
//최소공배수 구하는 법-> 최대공약수* 최소공배수=두 수의 곱