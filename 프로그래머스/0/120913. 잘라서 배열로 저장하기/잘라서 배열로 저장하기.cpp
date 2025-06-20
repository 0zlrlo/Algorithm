#include <string>
#include <vector>

using namespace std;
// n씩 잘라서 저장
vector<string> solution(string my_str, int n) {
    vector<string> answer;
    int i=0;
    while(i<my_str.length()){
        answer.push_back(my_str.substr(i,n)); 
        i=i+n;
    }
    return answer;
}