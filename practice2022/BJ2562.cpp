#include <iostream>
using namespace std;
int main() {
	int input[9];
	int max, count=0;
	for (int i = 0; i < 9; i++) {
		cin >> input[i];
	}
	max = input[0];
	for (int j = 0; j < 9; j++) {
		if (max<input[j]) {
			max = input[j];
			count = j + 1;
		}
	}
	cout << max<<endl;
	cout << count;
	
	return 0;
}