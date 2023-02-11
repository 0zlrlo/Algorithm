#include <iostream>
#include <time.h>
using namespace std;

clock_t start, finish, used_time=0;
int n, arr[10000001];

//int list[8];

//병합(2개의 배열을 병합)
void combine(int arr[], int left, int mid, int right){
    int i=left;  //왼쪽 정렬된 리스트의 인덱스
    int j=mid+1;  //오른쪽 정렬된 리스트의 인덱스
    int index=left;  //정렬된 리스트의 인덱스
    int temp[100000];
    int k;

    while((i<=mid) && (j<=right))
    {
        if(arr[i]<arr[j]){
            temp[index]=arr[i];
            i=i+1;
        }
        else{
            temp[index]=arr[j];
            j++;
        }
        index++;
    }
        if(i>mid){
        while(j<=right){
            temp[index]=arr[j];
            j++;
            index++;
        }
    }
    else{
        while(i<=mid){
            temp[index]=arr[i];
            i++;
            index++;
        }
    }
    for(k=left;k<index;k++){
        arr[k]=temp[k];
    }

}

//분할
void mergesort(int arr[],int left, int right){
    if(left>=right){
        return;
    }
    if(left<right){
        int mid=(left+right)/2;
        mergesort(arr,left, mid);
        mergesort(arr, mid+1, right);
        combine(arr,left,mid,right);
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin>>n;
    
    for(int i=0;i<n;i++){
        arr[i]=rand();
    }
    //int arr[8]={37,10,22,30,35,13,25,24};
    start=clock();
    mergesort(arr, 0, n-1);  //합병정렬 수행
    finish=clock();

    used_time=finish-start;

    //for(int i=0;i<n;i++){
    //    cout<<arr[i]<<"\n";
    //}
    
    cout<<(double)used_time/CLOCKS_PER_SEC<<"sec"<<"\n";
    return 0;
}
//Segmentaion fault:11 오류 발생으로 다시 코드 갈아 엎고 하였다.
//그래도 코드 짠 게 아까워 남겨놓는다.
/*while(i<=mid && j<=right){  //왼쪽 리스트와 오른쪽 리스트의 값 비교
    //비교하면서 최종 list가 만들어지는 과정
        if(arr[i]<arr[j]){
            list[k]=arr[i];
            i++;
        }
        else{
            list[k]=arr[j];
            j++;
        }
    }

    if(i>mid){
        for(int f=j;j<=right;f++){
            list[k++]=arr[f];
        }
    }
    if(j>right){
        for(int f=i;f<=mid;f++){
            arr[f]=list[f];
        }
    }

    for(int i=left;i<=right;i++){
        arr[i]=list[i];  //정리된 list를 다시 arr로..
    }*/