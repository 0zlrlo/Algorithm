/*
길이가 짧은 것부터
길이가 같으면 사전 순으로
같은 단어가 여러 번 입력된 경우 한 번만 출력
*/
#include <iostream>
#include <algorithm>
using namespace std;
string word[20001];

int cmp(string a, string b){
    if(a.length()==b.length()){  //길이가 같다면 사전 순
        return a<b;
    }
    else{
        return a.length()<b.length();  //길이가 다르면 짧은 순
    }
}


int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
         cin>>word[i];
    }

    sort(word, word+N, cmp);

    for(int i=0;i<N;i++){
        if(word[i]==word[i-1]){
            continue;
        }
        cout<<word[i]<<endl;
    }
    return 0;
}