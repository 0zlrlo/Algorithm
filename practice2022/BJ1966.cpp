#include <iostream>
using namespace std;
//큰수 먼저 출력
//원형 큐 이용
int main(){
    int test, N, M;
    int que[101];

    cin>>test;  //testcase 수
    for(int i=0;i<test;i++){
        cin>>N>>M;  //문서의 개수, 몇번째에 놓여져 있는지
        int max=0;
        int front=0;
        int cnt=0;

        for(int j=0;j<N;j++){
            cin>>que[j];
        }

        while(cnt!=N){

        for(int k=0;k<N;k++){
            if(max>que[k]){
                max=que[k];
            }
        }
        while(que[front]!=max){
            front=(front+1)%N;  //우리가 찾는 값과 최댓값이 일치할 때까지 
            //한 칸 이동
            //원형 큐에서 포인터 증가 방식
        
        }
            if(front==M){
                break;  //최댓값이 우리가 찾는 것과 일치
            }

            que[front]=0;
            front=(front+1)%N;
            max=0;
            cnt++;
         }
    
    }
    return 0;
}
/*
맨 앞이 맥스가 되는 동안
1234 라고 하면
4가 맨 앞에 올때까지 돌아
근데 그 다음에 그 맨 앞의 맥스가 우리가 찾고자 하는 것과
일치할 때까지 함 만약에 일치하면 출력
근데 front를 옮겨주는 것임
*/