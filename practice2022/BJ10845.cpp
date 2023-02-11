#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int main(){
    queue<int> q;
    int N;  

    cin>>N;
    for(int i=0;i<N;i++){
        string str;  
        cin>>str;
        if(str=="push"){
            int data;
            cin>>data;
            q.push(data);
        }
        else if(str=="pop"){
            if(q.size()==0){
                cout<<-1<<endl;
            }
            else{
                cout<<q.front()<<endl;
                q.pop();   
            }
        }
        else if(str=="size"){
            cout<<q.size()<<endl;
        }
        else if(str=="empty"){
            if(q.size()==0){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
        else if(str=="front"){
            if(q.size()==0){
                cout<<-1<<endl;
            }
            else{
                cout<<q.front()<<endl;
            }
        }
        else if(str=="back"){
            if(q.size()==0){
                cout<<-1<<endl;
            }
            else{
                cout<<q.back()<<endl;
            }           
        }
    }
    return 0;
}