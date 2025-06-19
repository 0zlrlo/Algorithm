#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// sort한 후,  인덱스 +1, 그리고 다시 원위치..?
vector<int> solution(vector<int> emergency) {
    vector<int> answer(emergency.size());
    vector<int> sorted = emergency;

    // 내림차순 정렬
    sort(sorted.begin(), sorted.end(), greater<int>());

    // 순위 매기기
    for(int i=0;i<emergency.size();i++){
        for(int j = 0;j<emergency.size();j++){
            if(emergency[i]==sorted[j]){
                answer[i] = j+1;
                break;
            }
        }
    }
    return answer;
}