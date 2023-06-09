#include <iostream>

using namespace std;

//顺序栈的存储结构
struct SeqStack
{
    int* top;
    int* base;
    int capacity;
};

//初始化
void InitStack(SeqStack& S, int capacity)
{
    //为顺序栈动态分配一个最大容量为capacity的数组空间，使base指向这段空间的基地址，即栈底。
    S.base = new int[capacity];
    //栈顶指针top初始为base,表示栈空。
    S.top = S.base;
    S.capacity = capacity;
}

//入栈
void Push(SeqStack& S, int e) 
{
    //栈满
    if (S.top - S.base == S.capacity)
    {
        return;
    }
    *S.top = e;
    S.top++;
}

//出栈
//删除S的栈顶元素，用e返回其值
void Pop(SeqStack& S, int& e) 
{
    //栈空
    if (S.top == S.base)
    {
        return;
    }
    S.top--;
    e = *S.top;
}

//取栈顶元素
int GetTop(SeqStack S) {
    //栈非空
    if (S.top != S.base)
    {
        return *(S.top - 1);
    }
    // 栈为空时的处理（例如可以返回一个特殊值表示栈为空）
    // 这里假设返回-1表示栈为空
    return -1;
}

int main()
{
    SeqStack S;
    int capacity = 5; // 栈的容量

    // 初始化栈
    InitStack(S, capacity);

    // 入栈测试
    cout << "Pushing elements onto the stack..." << endl;
    for (int i = 1; i <= capacity + 1; i++)
    {
        if (S.top - S.base != S.capacity)
        {
            Push(S, i);
            cout << "Pushed: " << i << endl;
        }
        else
        {
            cout << "Stack is full. Cannot push: " << i << endl;
        }
    }

    // 出栈测试
    cout << endl << "Popping elements from the stack..." << endl;
    int poppedElement;
    while (S.top != S.base)
    {
        Pop(S, poppedElement);
        cout << "Popped: " << poppedElement << endl;
    }

    // 取栈顶元素测试
    cout << endl << "Getting the top element of the stack..." << endl;
    int topElement = GetTop(S);
    if (topElement != -1)
    {
        cout << "Top element: " << topElement << endl;
    }
    else
    {
        cout << "Stack is empty. No top element." << endl;
    }

    // 释放栈空间
    delete[] S.base;

    return 0;
}
