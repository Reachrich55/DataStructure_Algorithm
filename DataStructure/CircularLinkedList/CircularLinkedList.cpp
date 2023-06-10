#include <iostream>

using namespace std;

//循环链表的存储结构
typedef struct Node {
    int data;
    struct Node* next;
}Node, * LinkList;

//初始化
Node* InitList(LinkList& L)
{
    L = new Node;
    L->next = L;
    return L;
}

//后插
void AddNode_R(LinkList &L,int value) {
    Node* newNode = new Node;
    newNode->data = value;
    Node* current = L;
    while (current->next != L) 
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = L;
}

//遍历
void Traverse(LinkList &L) {
    if (L->next == L) 
    {
        cout << "Circular Linked List is empty." << endl;
    }
    else 
    {
        Node* current = L->next;
        cout << "Circular Linked List: ";
        while (current != L) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

int main() {
    LinkList L;
    InitList(L);

    AddNode_R(L, 2);
    AddNode_R(L, 4);

    Traverse(L);

    return 0;
}
