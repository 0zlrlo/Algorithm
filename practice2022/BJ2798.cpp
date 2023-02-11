#include <iostream>
using namespace std;

int main(){
    int N,M;
    int sum=0;
    int max=0;
    int card[100];

    cin>>N>>M;  //N장의 카드 중 3개 고름
    //그 3장의 카드의 합이 M을 넘으면 안됨

    for(int i=0;i<N;i++){
        cin>>card[i];
    }
//카드를 3개 뽑는다고 생각하면 됨
//카드 3개 뽑는다고 하면 N*(N-1)*(N-2) 잖아?
//그 개념 적용

    for(int i=0;i<N;i++){  //첫번째 수 선택하면 맨 앞으로 미룸
        for(int j=i+1;j<N;j++){  //첫번재 수 제외
            for(int k=j+1;k<N;k++){  //첫번째, 두번째 수 제외
                int sum=card[i]+card[j]+card[k];
                if(sum<=M&&sum>max)
                max=sum;  //갱신
            }
        }
    }
    cout<<max;

}