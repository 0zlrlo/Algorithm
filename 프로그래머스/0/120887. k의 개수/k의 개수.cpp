#include <string>
#include <vector>
// 첫번째 예시에서 11에서 1이 두 번이기에 두 번 카운트 해줘야 함
using namespace std;
// i부터 j까지 k가 몇 번 등장하는지
int solution(int i, int j, int k) {
    int answer = 0;
    char box = k + '0';
    for(int temp=i; temp<=j;temp++){
        // 아래와 같이 하면 11에서 1이 두 번 카운트 되는 것이 아니라 한 번만 카운트된다.
        // if(to_string(temp).find(box)!= string::npos){
        //     answer++;
        // }
        // 애초에 순환하는 box를 char로 만들어서 string을 돌게끔 해야 한다
        for(char c: to_string(temp)){
            if(c==box){
                answer++;
            }
        }
    }
    return answer;
}