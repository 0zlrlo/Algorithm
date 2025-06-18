#include <string>
#include <vector>
#include <map>

using namespace std;
// 한 번만 등장한 문자를 사전 순으로 정렬
string solution(string s) {
    string answer = "";
    map<char, int> m;
    for(int i=0;i<s.size();i++){
        m[s[i]]++;
    }
    for(auto i: m){
        if(i.second == 1){
            answer= answer+i.first;
        }
    }
    return answer;
}