#include <iostream>
using namespace std;
int main(){
    //상근이가 배달하는 봉지의 최소 개수 출력, N킬로그램을 정확히 만들 수 없으면 -1 출력
    int N, a, b, ans;
    N>=3&&N<=5000;
    cin>>N;  //N 입력받기
    while(N>=0){
        if(N%5==0){
            ans+=N/5; //N을 5로 나눈 몫 개수 더하기
            N=ans%5;
            cout<<ans; 
        }
        else{
            ans+=N/3;
        }
    }
    cout<<-1;
}