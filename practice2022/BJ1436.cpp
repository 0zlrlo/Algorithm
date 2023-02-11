#include <iostream>
using namespace std;
//종말의 숫자: 어떤 수에 6이 적어도 3개 이상 연속으로 들어가는 수
//666부터 시작, 숫자를 1부터 증가하여 매번 종말의 
//수인지 아닌지 판단
int main(){
//거꾸로 생각!

    int N,result,temp;  //N번째 영화, 답
    int cnt=0;  //666이 연속으로 들어가는 것일 때마다 count
    while(N!=cnt){
        result++;
        int temp=result;

        //수에 적어도 6이 3개 이상 들어가는지
        while(temp!=0){
            if(temp%1000==666){  //종말의 숫자
                cnt++;
                break;
            }
            else{
                temp/=10;  //일의 자리 수 하나씩 버리기
            }
        }

        //if(N==cnt){
        //    break; //N은 자연수
        //}
        cout<<result;
    }
    
}
/*
1 666
2 1666
3 2666
4 3666
5 4666
6 5666
7 6660
*/