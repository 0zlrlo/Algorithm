#include <iostream>
#include <algorithm>
using namespace std;
//나이와 이름이 주어지고
//회원들은 나이가 증가하는 순으로, 
//나이가 같으면 먼저 가입한 사람이 먼저
struct Person{
    int age, index;
    char name;
};

bool compare(const Person& begin, const Person& last ){  //인자로 넘겨받는 게 person이 아니라 Person!
    if(begin.age!=last.age){
        return begin.age<last.age;
    }
    else{
        return begin.index<last.index;  //오름차순 정렬을 뜻함
    }
}


int main(){
    int N;
    Person person[101];
    cin>>N;  //온라인 저지 회원의 수
    for(int i=0;i<N;i++){
        cin>>person[i].age>>person[i].name;
        person[i].index=i;
    }
    sort(person, person+N,compare);

    for(int i=0;i<N;i++){
        cout<<person[i].age<<person[i].name<<endl;
    } 
    return 0;  
}
/*[Sort() 사용법과 compare함수 사용]
첫번째 인자: 정렬을 시작할 부분
두번째 인자: 정렬을 마칠 부분
세번째 인자: 정렬을 어떤 식으로 할 것인지 알려주는 함수

중요한 점은 [begin, end) 범위로 정렬한다
즉, 0-10번 인덱스까지 정렬한다고 하면,
첫번째 인자에는 배열의 시작 주소인 a를 넣고
두번째 인자에는 a+9가 아니라 a+10을 넣어야 한다(마지막 주소+1).


함수의 인자로는 두개의 값을 넣어줘야 한다
또한 인자에 const(상수)를 사용함으로써 
compare 함수를 이용하면서 값을 바꾸지 않고 값을 참조만 하겠다는 것을
나타내기 위해서이다
이 함수에서 대소 비교한 결과를 return 하고 싶으면 bool 함수로 하면 된다

만약 내림차순으로 정렬하기를 원한다면
sort(start, end, greater<자료형>()) 이렇게 쓰면 된다
Ex) sort(i, i+10, greater<int>()) 이런식
*/

/*[구조체 배열]
struct 구조체이름 변수이름[크기];

구조체 배열에서 각 요소에 접근하기 위해서는 
배열 뒤에 대괄호를 사용하여 대괄호 안에 인덱스를 지정해주기
이 상태에서 멤버 접근하려면 . 사용

구조체 배열 선언과 동시에 초기화 하는 법
struct 구조체이름 변수이름[크기]={{.멤버이름1=값1, .멤버이름2=값2}  이게 크기만큼 있으면 됨}
*/