#include <stdio.h>
#include <string.h>
int main() {
	int cnt=0;
	char sen[1000010];
	scanf("%[^\n]s", sen);  //[^\n]s는 공백까지 포함하여 문자열을 입력받는 것
	//엔터가 나올 떄까지 문자열로 받는다
	if (strlen(sen)==1&& sen[0] != ' ') {
		cnt++;
	}
	for (int i = 1; i < strlen(sen); i++) {
		if (sen[i - 1] = ' ' && sen[i] != ' ') {
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
//첫번째 문자가 공백을 가진다고 생각