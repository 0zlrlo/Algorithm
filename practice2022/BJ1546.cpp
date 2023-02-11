#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
	int N, max = 0;
	int sum=0;
	cin>>N;
	int* score=new int[N];

	for (int i=0; i < N; i++) {
		cin >> score[i];
		if (max < score[i]) {
			max = score[i];
		}
	}
	for (int j = 0; j < N; j++) {
		sum+=(float)score[j] / max * 100;
	}
	cout << (float)sum/N;
	delete[] score;
	return 0;
}