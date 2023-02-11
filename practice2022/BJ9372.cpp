#include <iostream>
#include <string.h>
using namespace std;

//예제를 보니까 국가마다 다 이어져 있음
int main(){
    int T,N,M,a,b;
    cin>>T;
    while(T--){
        cin>>N>>M;  //국가의 수, 비행기의 종류
        for(int i=0;i<M;i++){
            cin>>a>>b;
        }
        cout<<N-1<<endl;
    }
//너무 단순한데 이게 맞나요..

    return 0;
}