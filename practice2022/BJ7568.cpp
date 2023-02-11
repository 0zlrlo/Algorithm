#include <iostream>
using namespace std;
//덩치 등수
int main(){
    int N;
    int x[201];
    int y[201];

    for(int i=0;i<N;i++){
        cin>>N;
        cin>>x[i]>>y[i];
    }

    for(int i=0;i<N;i++){
            int k=1;  //i번쨰 사람과 j번째 사람의 몸무게와 키를 비교함
        for(int j=0;j<N;j++){
            if(x[i]<x[j]&&y[i]<y[j]){
                k++;
            }
        }
            cout<<k;
    }
    return 0;
}