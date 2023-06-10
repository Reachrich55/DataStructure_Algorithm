#include <iostream>

using namespace std;

//存储结构
typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

//初始化
void InitList(LinkList& L)
{   
    //构造一个空的单链表L
    L = new Node;
    L->next = NULL;
}

//取值
int GetElem(LinkList L,int i)
{
    Node* p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i) return -1;
    else return p->data;
}

//查找
Node* LocateElem(LinkList L, int e) 
{
    Node* p = L->next;
    while (p && p->data!=e)
    {
        p = p->next;
    }
    return p;   //查找成功返回含e结点的地址，查找失败返回NULL
}

//插入（任意位置）
void ListInsert(LinkList& L, int i, int data)
{   
    //在带头结点的单链表L中第i个位置插入值为data的新结点
    Node* p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1) return;  //插入失败
    Node *new_Node = new Node;
    new_Node->data = data;
    new_Node->next = p->next;
    p->next = new_Node;
    return;   //插入成功
}

//删除
void ListDelete(LinkList& L, int i)
{
    //在带头结点的单链表L中，删除第i个元素
    Node* p = L;
    int j = 0;
    while (p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p->next || j > i - 1) return;  //删除失败
    Node* q = p->next;  //临时保存被删结点的地址以备释放
    p->next = q->next;  //改变删除结点前驱结点的指针域
    delete q;
    return; //删除成功
}

//前插
void AddNode_H(LinkList& L, int data)
{
    Node* new_Node = new Node;
    new_Node->data = data;

    //Node* new_Node = (struct Node*)malloc(sizeof(struct Node));
    //new_Node->data = data;
    
    new_Node->next = L->next;
    L->next = new_Node;
}

//前插法创建单链表
void CreateList_H(LinkList& L, int n) 
{
    //逆位序输入n个元素的值，建立带头结点的单链表L

    //构造一个空的单链表L
    //L = new Node;
    //L->next = NULL;
    InitList(L);
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        Node* new_Node = new Node;
        new_Node->data = data;
        new_Node->next = L->next;
        L->next = new_Node;
    }
}
//后插
void AddNode_R(LinkList& L, int data)
{
    Node* tail;    //尾指针
    tail = L;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    Node* new_Node = new Node;
    new_Node->data = data;
    new_Node->next = NULL;

    tail->next = new_Node;
    tail = new_Node;
}

//后插法创建单链表
void CreateList_R(LinkList& L, int n) 
{
    //正位序输入n个元素的值，建立带头结点的单链表L
    InitList(L);
    Node* tail;    //尾指针
    tail = L;      //尾指针指向头结点
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        Node* new_Node = new Node;
        new_Node->data = data;
        new_Node->next = NULL;

        tail->next = new_Node;  //将新结点插入到尾结点之后
        tail = new_Node;        //尾指针指向新的尾结点
    }
}

//打印单链表
void Traverse(LinkList L)
{
    Node* current_node = L->next;
    while (current_node)
    {
        cout << current_node->data<<" ";
        current_node = current_node->next;
    }
    cout << endl;
}

int main() {
    //测试代码
    LinkList L;
    InitList(L);
    CreateList_R(L, 3);
    Traverse(L);
    AddNode_R(L, 0);
    Traverse(L);
    return 0;
}
