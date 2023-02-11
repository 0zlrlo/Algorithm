//Singly Linked 연결리스트 구현
//함수 따로 만든 version 2
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

//검색
//검색함수는 출력함수에 들어가는 기능인 다음 주소가 NULL일 때까지 반복하는 것과
//노드의 값을 비교하는 기능이 추가적으로 들어가면 됨
Node*SearchNode(Node*head, int data){
    Node*curr=head->next;
    while(curr!=NULL){
        if(curr->data==data){
            return curr;  //참일 경우 해당 노드 반환-> 노드 주소를 반환하는 것임
        }
        curr=curr->next;
    }
    return NULL;  //없을 경우 NULL 반환
}

//출력
void PrintNode(Node*head){
    Node*curr=head->next;  //순회용 포인터 변수
    //curr은 Node2의 주소를 대입받은 상태
    while(curr !=NULL){  //현재 curr에는 Node2의 주소가 저장되어 있기에 반복
        cout<<curr->data<<endl;  //출력: 20
        curr=curr->next;  //이제 curr이 Node1이 됨
    }
}

//메모리해제
//앞 노드부터 메모리 공간 해제->head노드 공간부터 해제
//head 노드를 해제하기 전에 미리 다음 노드를 저장
void MemoryClear(Node*head){
    Node*ClearNode=head;
    Node*temp=ClearNode;  //ClearNode와 temp가 모두 head이다
    //그 이유는 while문 안에서 다음 노드 주소를 정할 것이기 때문에
    while(ClearNode!=NULL){
        temp=temp->next;  //다음 노드 주소를 미리 저장
        free(ClearNode);
        ClearNode=temp;  //이제는 해제할 노드가 temp 
    }


}


int main(){
    //노드 추가
    Node*head=(Node*)malloc(sizeof(Node));   
    //malloc 함수로 sizrof(Node) 크기만큼도 동적할당
    head->next=NULL; 

    AddNode(head,10);
    AddNode(head,20);
    AddNode(head,30);
    AddNode(head,40);
    AddNode(head,50);
    //head->30->20->10->NULL

    DeleteNode(head);
    //이렇게 되면 머리노드 뒤의 노드가 삭제가 되므로 
    //head->20->10 
    DeleteNode(head);

    cout<<"출력: ";
    PrintNode(head);

    Node*result=SearchNode(head,30);
    if(result !=NULL){
        cout<<"해당 노드 주소: "<<result<<endl;
        cout<<"해당 노드 주소 값: "<<result->data<<endl;
    }
    else{
        cout<<"노드를 찾을 수 없습니다"<<endl;
    }

    MemoryClear(head);
    return 0;
 }