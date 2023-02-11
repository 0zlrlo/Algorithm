#include <iostream>
#include <string.h>
#include <cmath>
//50점
using namespace std;
int main(){
    int L,result;
    string hash;
    char c;

    cin>>L;  //문자열 길이
    cin>>hash;

    for(int i=0;i<L;i++){
        c=hash[i]; 
        //각각 지정
        result+=(c-96)*pow(31,i);
    }
    cout<<result;

    return 0;
}
/*
mod 성질
1. (a + b) mod n = {(a mod n) + (b mod n)} mod n
2. (a - b) mod n = {(a mod n) - (b mod n)} mod n
3. (a * b) mod n = {(a mod n) * (b mod n)} mod n

https://codejin.tistory.com/68
*/
/*
[math STL]
1. 헤더파일: #include <cmath>  
수학함수를 가지고 있는 헤더파일
2. 헤더파일: #include <algorithm>
min(), max()를 가지고있는 헤더파일

3. 기능
-ceil(x) : x를 사장 가까운 정수로 올림/ double 값으로 반환
-floor(x) : x를 가장 가까운 정수로 내림/ double 값으로 반환
-abs(x) : x의 절대값을 반환
-min(x,y) : x, y 중의 최소값을 반환
-max(x,y) : x, y 중의 최대값을 반환

4. 기능
-pow(a,b) : a의 b제곱값(a^b)을 반환
-sqaurt(x) : x의 제곱근(루트값)을 반환
-log(x) : x의 자연로그값을 반환
-log10(x) : x의 상용로그값을 반환

5. 기능
-sin(radians) : 입력된 라디안 값의 사인 값을 반환
-cos(radians) : 입력된 라디안 값의 코사인 값을 반환
-tan(radians) : 입력된 라디안값의 탄젠트 값을 반환
-asin(a) : 입력된 사인 값의 라디안값을 반환
-acos(a) : 입력된 코사인 값의 라디안값을 반환
-atan(a) : 입력된 탄젠트 값의 라디안값을 반환

*/