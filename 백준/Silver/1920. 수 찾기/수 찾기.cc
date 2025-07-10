#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
cin.tie(NULL);
    int N, M;

    cin >> N;
    unordered_set<int> nTemp;
    for (int i = 0; i < N; i++) {
        int num;
        cin>>num;
        nTemp.insert(num);
    }

    cin >> M;
    
    for (int i = 0; i < M; i++) {
        int num;
        cin>>num;
        if(nTemp.find(num)!=nTemp.end()){
            cout<<1<<'\n';
        }else{
            cout<<0<<'\n';
        }
    }


    return 0;
}