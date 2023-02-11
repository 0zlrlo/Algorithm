//Singly Linked 연결리스트 구현
//함수 따로 안 만들고 메인에 만든 version
#include <iostream>
#include <string.h>
using namespace std;

class Node{
    public:
        int data;   //데이터 저장
        struct Node* next;    //노드의 주소를 저장
    };

class HeadNode{
    public:
    Node*head=NULL;
};


int main(){
    //노드 추가
    Node*head=(Node*)malloc(sizeof(Node));   
    //malloc 함수로 sizrof(Node) 크기만큼도 동적할당
    head->next=NULL; 

    Node*Node1=(Node*)malloc(sizeof(Node));
    //Node1이라는 노드 새로 할당
    //NULL과 머리노드 사이에 Node1이라는 새로운 노드 추가
    Node1->data=10;
    Node1->next=head->next;
    //Node1의 다음 주소는 머리노드가 가리키던 다음주소인 NULL을 저장
    head->next=Node1;

    Node*Node2=(Node*)malloc(sizeof(Node));
    Node2->data=20;
    Node2->next=head->next;
    //Node2의 다음 주소는 head가 가리키던 주소인 Node1
    head->next=Node2;
    //head다음에 Node2, 그 다음에 Node1, 그러고 NULL

    //데이터 출력
    //머리노드는 데이터를 안 가짐
    Node*curr=head->next;  //순회용 포인터 변수
    //curr은 Node2의 주소를 대입받은 상태
    while(curr !=NULL){  //현재 curr에는 Node2의 주소가 저장되어 있기에 반복
        cout<<curr->data<<endl;  //출력: 20
        curr=curr->next;  //이제 curr이 Node1이 됨
    }

    free(head);
    free(Node1);
    free(Node2);



    return 0;
 }
