#include <iostream>
using namespace std;
int main() {
	int N, X, input;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> input;

		if (X > input) {
			cout << input << " ";
		}
	}
	return 0;
}
//유의해야 할 점:입력을 받자마자 출력을 해야 한다
//반복문으로 10번 입력받고, 또 다른 반복문을 써서 10번 출력하면 안된다