#include <iostream>

using namespace std;

// 双向循环链表的存储结构
typedef struct DLNode {
    int data;
    DLNode* prior;
    DLNode* next;
} DLNode, * DLinkList;

// 初始化
void InitDoubleCircularList(DLinkList& L) {
    L = new DLNode;
    L->prior = L;
    L->next = L;
}

// 在第i个位置之后插入
void DoubleCircularListInsert(DLinkList& L, int i, int data) {
    if (i <= 0) {
        cout << "插入位置无效" << endl;
        return;
    }

    DLNode* p = L;
    int j = 0;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }

    if (!p || j > i) {
        cout << "插入位置无效" << endl;
        return;
    }

    DLNode* newNode = new DLNode;
    newNode->data = data;

    newNode->prior = p;
    newNode->next = p->next;
    p->next->prior = newNode;
    p->next = newNode;
}

// 删除第i个位置的元素
void DoubleCircularListDelete(DLinkList& L, int i) {
    if (i <= 0) {
        cout << "删除位置无效" << endl;
        return;
    }

    DLNode* p = L;
    int j = 0;
    while (p->next != L && j < i - 1)
    {
        p = p->next;
        j++;
    }

    if (p->next == L || j > i - 1) {
        cout << "删除位置无效" << endl;
        return;
    }

    DLNode* delNode = p->next;
    p->next = delNode->next;
    delNode->next->prior = p;
    delete delNode;
}

// 遍历
void Traverse(DLinkList& L) {
    if (L->next == L)
    {
        cout << "双向循环链表为空" << endl;
    }
    else
    {
        DLNode* current = L->next;
        cout << "双向循环链表: ";
        while (current != L) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

// 释放链表内存
void FreeDoubleCircularList(DLinkList& L) {
    DLNode* p = L->next;
    while (p != L) {
        DLNode* temp = p;
        p = p->next;
        delete temp;
    }
    delete L;
    L = NULL;
}

// 测试
int main() {
    DLinkList L;
    InitDoubleCircularList(L);

    DoubleCircularListInsert(L, 1, 5);
    DoubleCircularListInsert(L, 1, 9);

    Traverse(L);

    DoubleCircularListDelete(L, 2);

    Traverse(L);

    FreeDoubleCircularList(L);

    return 0;
}
