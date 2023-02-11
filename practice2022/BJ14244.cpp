#include <iostream>
using namespace std;
//이어진 것들: 노드
//노드들 중에 끝에 있는 것들: 리프
int main(){
    int n,m; //n: 노드, m: 리프
    cin>>n>>m;
    for(int i=0;i<m-1;i++){
        cout<<i<<' '<<m-1<<endl;
    }
    for(int i=m-1;i<n-1;i++){
        cout<<i<<' '<<i+1<<endl;
    }
    return 0;
}

//내가 했지만 잘 이해가 안되는 문제,,
