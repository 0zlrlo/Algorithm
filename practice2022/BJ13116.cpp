#include <iostream>
using namespace std;
//공통된 부모노드를 찾아라

int main(){
    int T,a,b;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>a>>b;
    }
    while(a!=b){
        if(a>b){
            a=a/2;
        }
        else if(a<b){
            b=b/2;
        }
        else{
            a=a/2;
            b=b/2;
        } 
        cout<<a*10<<endl;  //b*10 해도 된다

    }

}