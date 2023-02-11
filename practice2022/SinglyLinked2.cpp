//Singly Linked 연결리스트 구현
//함수 따로 만든 version 1
//추가, 삭제
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

//머리노드 뒤에 추가
//머리노드 다음은 NULL인 상황
void AddNode(Node*head,int data){
    //새로운 노드에 대한 설정
    Node *NewNode=(Node*)malloc(sizeof(Node));
    NewNode->data=data;
    //추가했으니 새롭게 잇기
    NewNode->next=head->next;  
    //head->next는 NULL
    head->next=NewNode;  //이 코드와 바로 위 코드는 
    cout<<"머리노드 뒤에 새로운 노드 추가: "<<data;
}

//머리노드 뒤의 노드 삭제
void DeleteNode(Node*head){
    Node *deleteNode=head->next;
    head->next=deleteNode->next;
    free(deleteNode);  //할당을 했으면 해제를 해야 한다!
    cout<<"머리노드 뒤의 노드 삭제: ";
}


int main(){
    //노드 추가
    Node*head=(Node*)malloc(sizeof(Node));   
    //malloc 함수로 sizrof(Node) 크기만큼도 동적할당
    head->next=NULL; 

    AddNode(head,10);
    AddNode(head,20);
    AddNode(head,30);
    //head->30->20->10->NULL

    DeleteNode(head);
    //이렇게 되면 머리노드 뒤의 노드가 삭제가 되므로 
    //head->20->10 

    Node*curr=head->next;  //순회용 포인터 변수
    //curr은 Node2의 주소를 대입받은 상태
    while(curr !=NULL){  //현재 curr에는 Node2의 주소가 저장되어 있기에 반복
        cout<<curr->data<<endl;  //출력: 20
        curr=curr->next;  //이제 curr이 Node1이 됨
    }

    return 0;
 }