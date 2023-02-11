#include <iostream>
#include <string.h>
//앞 뒤가 똑같은 수
using namespace std;
int main(){
    int cnt=0;
    string num;
    cin>>num;
    //짝수여도 서로 같을 수 있음
    while(1){
       
            for(int i=0;i<num.size()/2;i++){  
                //그냥 num.size가 아니라 2로 나눈 값까지 반복
            if(num[i]==num[num.size()-i-1]){
                cout<<"yes"<<endl;
                cnt=1;
                break;
               }
            }
            if(cnt==0){
                cout<<"no"<<endl
            }
        

    if(num=="0"){
        break;
    }
    }
}
/*
[string  STL]
꼴
string str="Test"

특징
1. 문자열 끝에 \0 없다
2. 마치 배열처럼 한 문자씩 다룰 수 있다
3. string 클래스끼리 문자열을 합치는 것이 + 연산자만으로도 가능하다

string의 인덱스 접근
1. 배열처럼 접근 str[0]
2. .at(index)로 접근 str.at(0)

문자열 맨 앞과 맨 끝 문자 반환
1. str.front(); 
2. str.back(); 

문자열의 길이 반환
1. str.size();
2. str.length();

숫자->문자열/ 문자열->숫자 전환
1. to_string(숫자); 이용 
2. int일 경우 stoi/ double일 경우 stob/ float, long int일 경우 stof

*/