#include <iostream>
#include <string.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	for (int i = 1; i < N+1; i++) {
		for (int j = 1; j < N - i+1; j++) {
			cout << " ";
		}
		for (int k = 1; k < i+1; k++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}
//1: - - - - *
//2: - - - * *
//3: - - * * *