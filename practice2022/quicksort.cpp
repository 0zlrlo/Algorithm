#include <iostream>
#include <time.h>
using namespace std;

int n, arr[10000001];
clock_t start, finish, used_time=0;

void quicksort(int arr[], int a, int b){
        
    if(a>=b){  //a가 맨 왼쪽, b가 맨 오른쪽
        return;  //시작부터 left가 right보다 뒤에 있으면 리턴
    }
    int pivot=a;  //피벗의 위치는 맨 왼쪽으로 설정하였다.
    int left=a+1;  //그러므로 left는 피벗 다음부터 시작
    int right=b;

    while(left<=right){  //퀵정렬 원리 적용 부분
        while(left<=b && arr[left]<=arr[pivot]){
            left++;
        }
        while(right>a && arr[right]>=arr[pivot]){
            right--;
        }

        if(left>right){  //left와 right이 엇갈리면
            swap(arr[pivot],arr[right]);  //피벗과 자리교환
        }
        else{  //그게 아니면
            swap(arr[left],arr[right]);  //정상적으로 left와 right 자리교환
        }
    }
        quicksort(arr,a,right-1);  //왼쪽 구역 재귀호출
        quicksort(arr,right+1,b);  //오른쪽 구역 재귀호출

}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n;

    for(int i=0;i<n;i++){
        arr[i]=rand();
    }

    //int arr[9]={5,1,3,7,9,2,4,6,8};
    start=clock();
    quicksort(arr,0,n-1);
    finish=clock();

    used_time=finish-start;

    //for(int i=0;i<n;i++){
    //    cout<<arr[i]<<"\n";
    //}
    cout<<(double)used_time/CLOCKS_PER_SEC<<"sec"<<"\n";

    return 0;
}