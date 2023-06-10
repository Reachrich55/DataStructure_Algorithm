#include <iostream>

using namespace std;

//循环队列的存储结构
struct CircularQueue 
{
    int front;
    int rear;
    int capacity;
    int* base;  //存储空间的基地址
};

//循环队列的初始化
void InitCircularQueue(CircularQueue& CQ, int capacity)
{
    CQ.base = new int[capacity];
    CQ.capacity = capacity;
    CQ.front = CQ.rear = 0;
}

//判断空列
bool IsEmpty(CircularQueue& CQ) 
{
    return CQ.front == CQ.rear;
}

//判断队满
bool IsFull(CircularQueue& CQ) 
{
    //若尾指针在循环意义上+1后等于头指针，表明队满
    return (CQ.rear + 1) % CQ.capacity == CQ.front;
}

//求队列长度
int GetCircularQueueLength(CircularQueue CQ) 
{
    return (CQ.rear - CQ.front + CQ.capacity) % CQ.capacity;
}

//入队，在队尾插入一个新元素
void EnQueue(CircularQueue& CQ, int element) 
{
    if (IsFull(CQ)) 
    {
        cout << "Queue is full." << endl;
        return;
    }
    CQ.base[CQ.rear] = element;
    CQ.rear = (CQ.rear + 1) % CQ.capacity;
}

//出队，删除队头元素
void DeQueue(CircularQueue& CQ, int& x) 
{
    if (IsEmpty(CQ)) 
    {
        cout << "Queue is empty." << endl;
        return;
    }
    x = CQ.base[CQ.front];
    CQ.front = (CQ.front + 1) % CQ.capacity;
}

//打印队列
void PrintQueue(CircularQueue CQ) 
{
    if (IsEmpty(CQ)) 
    {
        cout << "Queue is empty." << endl;
        return;
    }
    int i = CQ.front;
    while (i != CQ.rear) 
    {
        cout << CQ.base[i] << " ";
        i = (i + 1) % CQ.capacity;
    }
    cout << endl;
}

int main()
{
    CircularQueue CQ;
    int capacity = 5;
    InitCircularQueue(CQ,capacity);
    EnQueue(CQ, 1);
    EnQueue(CQ, 2);
    EnQueue(CQ, 3);
    PrintQueue(CQ);
    int x;
    DeQueue(CQ, x);
    cout << "Dequeued element: " << x << endl;
    PrintQueue(CQ);
    delete[] CQ.base; // 释放动态分配的内存
    return 0;
}
