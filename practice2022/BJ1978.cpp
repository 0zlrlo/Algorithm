#include <iostream>
using namespace std;
int main(){
    //소수가 몇 개인지 찾아서 출력
    //소수는 1과 자기 자신으로만 나누어 지는 1보다 큰 정수
    int N,k;   //수의 개수
    int result=0;

    cin>>N;

    for(int i=0;i<N;i++){
        int cnt=0;  //이걸 무조건 안에서 선언!
        //그래야지 숫자 하나 당 cnt가 다시 초기화됨. 
        cin>>k;

        if(k==1){  //1이면 소수가 아니다
            continue;
        }

        for(int j=2;j<k;j++){  //소수는 1과 자기 자신으로만 나누어 지므로
        //1과 자기 자신 빼고 반복문 돌기 
            if(k%j==0){  //약수를 가지게 되는 것임
                cnt++;
                break;
            }
        }

        if(cnt==0){  //cnt가 0이 되려면 1도 아니고 자기 자신으로만 나눠지게 되는 경우
            result++;
        }
    }
    cout<<result;

    return 0;
}

    
/*
    for(int j=0;j<N;j++){
        if(k==1){
            continue;
        }
        else if(k==2||k==3||k==5||k==7){
            cnt++;
        }
    else if(k%2!=0|| k%3!=0|| k%5!=0|| k%7!=0){
        cnt++;
    }

    else{
        cnt++;

    }
    cout<<cnt;

*/
