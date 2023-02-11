#include <iostream>
using namespace std;
int main(){
    int a,b,c;

    while(1){  
    cin>>a>>b>>c;  
    int k=a*a;
    int t=b*b;
    int g=c*c; 

    if(a==0&&b==0&&c==0){
        break;
    }
    //무조건 c가 제일 긴 변이라는 보장이 없기에
    //다 생각을 해 봐야 한다
    if(k+t==g||k+g==t||t+g==k){
        cout<<"right"<<endl;
    }
    else{
        cout<<"wrong"<<endl;
    }

    }
    return 0;
}
/*
[while(1), while(0)]
1은 참, 0은 거짓

while(1)은 항상 참이기 때문에 
while문 안에 있는 코드들이 무한루프를 돌게 된다

while(0)은 반대로 while문 안의 코드가 실행되지 않는다


*/