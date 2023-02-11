#include <iostream>
using namespace std;

int main(){
    int n;
    int arr;
    int cnt[100001]={0};  //={0}을 안해줘서 출력초과가 계속 떴음
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr);  //입력받는 것을 배열로 하면 시간초과
        cnt[arr]+=1; 
    }
    for(int j=1;j<100001;j++){ //입력받는 수들이 자연수이므로 j가 1부터 시작해야 한다.
        for(int k=0;k<cnt[j];k++){
            printf("%d\n",j);   //그 수만큼 값 출력해주기
        }
    }



    return 0;
}


//입력받은 숫자를 전부 다 입력받아서 고대로 출력하면 메모리를 초과해서
//안된다고 한다.
//그러기에 같은 수가 몇개 나오는지 카운트 하고 그만큼만 출력해주게끔 한다.