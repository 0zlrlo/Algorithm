#include <string>
#include <vector>

using namespace std;
/*
옆옆 사람한테 공 던짐
k번째로 공 던지는 사람이 누구인가..
*/
int solution(vector<int> numbers, int k) {
    int location = 0;
    for (int i = 1; i < k; i++) {  
        location = (location + 2) % numbers.size();
    }
    return numbers[location];
}