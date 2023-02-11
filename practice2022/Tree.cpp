//트리 구조 구현
//전위순회: root->left->right
#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node*left;
    struct Node*right;
}Node;

//루트 왼쪽 오른쪽 순
struct Node n1={1, NULL,NULL};
struct Node n2={4, &n1, NULL};
struct Node n3={16, NULL, NULL};
struct Node n4={25, NULL, NULL};
struct Node n5={20, &n3, &n4};
struct Node n6={15, &n2, &n5};
struct Node *current=&n6;    //current가 루트
//계속 오류가 났던 이유,,
//Struct Node에서 int data를 맨 마지막에 썼는데 맨 위에 썼어야 했다. 순서 주의

void Preorder(Node*current){
    if(current){
        cout<<current->data<<endl;
        Preorder(current->left);
        Preorder(current->right);
    }
}

int main(){

    cout<<"전위순회"<<endl;
    Preorder(current);
    return 0;
    //출력: 15-4-1-20-16-25
}