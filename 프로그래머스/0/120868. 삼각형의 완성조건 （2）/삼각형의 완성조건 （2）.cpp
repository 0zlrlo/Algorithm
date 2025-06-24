#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 가장 긴 변 < 두 변의 길이의 합
/*
첫번째가 가장 긴 변 일 때,,
sides[0] < another + sides[1]
another <= sides[0] 
-> 결론적으로는.. 두 변 중 더 긴 변이 가장 긴 변이라면.. sides[0]-sides[1] < another < sides[0]
               나머지가 가장 긴 변이라면... another < sides[0] + sides[1]
*/
int solution(vector<int> sides) {
    int answer = 0;
    sort(sides.begin(), sides.end()); 
    for(int i=sides[1]-sides[0]+1;i<sides[0]+sides[1];i++){  
        answer++;
    }
    return answer;
}