#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <cstdlib> 

using namespace std;
struct compare{
    bool operator()(const string&a, const string&b) const{
        if(a.length()==b.length()){
            return a<b;
        }
        return a.size()<b.size();
    }
};

int main() {
    int N;
    cin>>N;
    set<string, compare>temp;
    for(int i=0;i<N;i++){
        string word;
        cin>>word;
        temp.insert(word);
    }
    for(const string& word:temp){
        cout<<word<<'\n';
    }
    return 0;
}