#include <iostream>
using namespace std;
int main() {
	int input;
	int add = 0;
	for (int i = 0; i < 5; i++) {
		cin >> input;
		add= add+ input * input;
	}
	int result = add % 10;
	cout << result;
	return 0;
}