#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    int T,n;  //전체 개수, 받을 수들 개수
    string fun;  //함수
    string que;  //받을 수들

    cin>>T;

    for(int i=0;i<T;i++){
    cin>>fun;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>que;
    }
    }
    for(int i=0;i<fun.size();i++){
    if(fun[i]=='R'){
        reverse(que.begin(),que.end());
    }
    else {
        if(que.empty()){
            cout<<"error"<<endl;
        }
        else{
        que.erase(que.begin());
        }
    }
        cout<<que<<endl;
    }

}