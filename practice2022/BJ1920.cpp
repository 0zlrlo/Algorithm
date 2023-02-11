#include <iostream>
#include <string.h>

using namespace std;
int A[100000];

int main() {
	int N, M,temp;
	int key;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	
	//오름차순 정렬	
	for (int i = 0; i < N-1; i++) {
		for (int j =i+1;j<N;j++ ) {
			if (A[i] > A[j]) {
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
	
	scanf("%d", &M);
	for (int j = 0; j < M; j++) {
		scanf("%d", &key);
	}

	return 0;
}

void BinarySearch(int N,int key){

    int first = 0;
	int end=N-1;
	while(first<=end){
		int mid=(first+end)/2;   //계속 mid는 바뀌기 때문에 이렇게 사용
		if(key==A[mid]){
			printf("1\n");
		}
		else if(key<A[mid]){
			end=mid-1;
		}
		else{
			first=mid+1;
		}
	}
		printf("0\n");
	    
}
	

//ctrl+alt+n: 컴파일, 실행