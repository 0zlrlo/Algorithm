#include <iostream>
using namespace std;

int N, M;
int tree[1000001];

//적어도 M미터의 나무를 가져가야 함
int BinarySearch(){
    int first,end,mid,answer;  //answer은 정답 후보라는 뜻
    int sum=0;  //가져가게 될 나무들의 합

    while(first<=end){
        mid=(first+end)/2;
        for(int j=0;j<N;j++){
            if(mid<tree[j]){  //tree의 높이가 mid보다 크면 그 차이만큼 가져가기 가능
                answer=mid;   //일단4 7 mid가 지금 보다 더 클 수 있지만 아닐 수도 있기 떄문에 정답 후보지 
                sum+=tree[j]-mid;
            }
        }
        if(M<=sum){   //남은 부분들을 합친게 원래 나무길이보다 길면 ok 
           first=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return answer;
}

int main(){

    cin>>N>>M;    //나무의 개수와 나무의 길이
    for(int i=0;i<N;i++){
        cin>>tree[i];
        cout<<BinarySearch() <<endl;
    }


    return 0;
}


/*
중간 정도의 높이를 정해보고 상근이가 가져갈 수 있는 양이면 
점차적으로 높이를 늘리는 방식으로 접근

이진탐색 사용
*/
