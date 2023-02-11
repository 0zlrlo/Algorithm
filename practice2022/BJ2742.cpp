#include <iostream>
#include <string.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cout << N - i;
		cout << endl;
	}

	return 0;
}
//백준에서는 시간초과가 남 
//endl 을 \n으로 바꿨는데 컴파일에러 남..