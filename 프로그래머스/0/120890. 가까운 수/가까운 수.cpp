#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

int solution(vector<int> array, int n) {
    int answer = array[0];
    int min = abs(n-array[0]);
    for(int i=0;i<array.size();i++){
        int diff = abs(n-array[i]);
        if(diff<min){
            min= diff;
            answer= array[i];
        }else if(diff==min&&array[i]<answer){
            answer= array[i];
        }
    }
    return answer;
}