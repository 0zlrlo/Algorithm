#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    //map stl 사용
    //https://cplusplus.com/reference/map/map/find/
    int N,M;
    string a,b,c;
    map<string,string> map;

    cin>>N>>M;

    for(int i=0;i<N;i++){
        cin>>a>>b;
        map[a]=b;
    }
    for(int i=0;i<M;i++){
        cin>>c;
        //map.find(c)!=map.end()){
        cout<<map[c]<<'\n';
        //}
    }

}