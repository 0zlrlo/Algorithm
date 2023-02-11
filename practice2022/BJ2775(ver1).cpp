#include <iostream>
using namespace std;
//a층 b호에 살려면 a-1층의 1호부터 b호까지 사람들의 수의 합만큼 사람들을 데려와야 함
//0층 1호부터 있음 
int people(int a, int b){
    if(a==0){
        return b;
    }
    if(b==1){
        return 1;  //1호일 경우 1 리턴
    }
    return people(a-1,b)+people(a,b-1); 
    
}
int main(){
    int T;  //test case 수
    int k,n;   //k층 n호

    cin>>T;
    for(int i=0;i<T;i++){
        cin>>k;
        cin>>n;
    }

    for(int i=0;i<T;i++){
    cout<<people(k,n)<<endl;
    }
    return 0;
}
//ver1