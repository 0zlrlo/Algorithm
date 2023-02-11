#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int A,B,V;
    int cnt=0;
    int sum=0;
    cin>>A>>B>>V;
    while(sum<V){
    if(sum<V){
        sum+=A;
        cnt++;
        if(sum>=V){
            break;
        }
        sum-=B;
    }
    else{
        break;
    }
    }
    cout<<cnt;
}