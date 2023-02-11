#include <iostream>
#include <string.h>
using namespace std;
int main() {
	int input[8];
	int a, d= 8;

	for (int i = 0; i < 8; i++) {
		cin >> input[i];
	}
	for (int j = 0; j < 8; j++) {
		if (input[j] == j + 1) {
			a--;
		}
		else if (input[j] == 8 - j) {
			d--;
		}
	}
	
	if (a == 0) {
		cout << "ascneding"<<endl;
	}
	else if (d == 0) {
		cout << "descending"<<endl;
	}
	else {
		cout << "mixed"<<endl;
	}
	return 0;
}