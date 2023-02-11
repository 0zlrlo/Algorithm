#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
//front에 위치한 것을 한 번 버림
//새로운 front원소를 가장 마지막에 넣음
//이걸 카드 1장만 남을 때까지 반복
int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        q.push(i);
    }
    while(q.size()!=1){
        q.pop();
        q.push(q.front());
        q.pop();   //앞에 있던 수 고대로 뒤에 복붙하고 앞에 있던 수 삭제
    }
    cout<<q.front();
    return 0;
}
/*[queue STL]
선입선출 구조
큐의 기본함수에는 push, pop, empty, front, back, swap 등이 있다
front 원소와 back 원소에 접근할 수 있다

Enqueue: 큐 맨 뒤에 데이터 추가
Dequeue: 제일 먼저 들어간 데이터 삭제

사용법
1. #include <queue>
2. queue <데이터타입> 이름;   //queue 선언

3. 큐이름.push(데이터)    //새로운 데이터 추가
4. 큐이름.pop()     //제일 먼저 들어간 데이터 삭제
5. 큐이름.front()    //제일 먼저 들어간 데이터 출력
6. 큐이름.back()    //제일 나중에 들어간 데이터 출력
7. 큐이름. size()    //큐의 현재 사이즈 반환
8. 큐이름. empty()    //큐가 비어있는지 확인
9. swap(큐이름1, 큐이름2)   //두 큐의 내용을 바꾸고 싶을 때

*/