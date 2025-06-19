#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
using namespace std;
// 연속된 수는 하나의 숫자로 간주..
int solution(string my_string) {
    int answer = 0;
    string num = "";
    for(char c: my_string){
        if(isdigit(c)){
            num = num+c;
        }else{
            if(!num.empty()){
                answer = answer + stoi(num);
            }
            num = "";
        }
    }
    if (!num.empty()) {
        answer = answer + stoi(num);
    }
    return answer;
}