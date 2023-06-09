#include <iostream>

using namespace std;

//队列的存储结构
struct Queue
{
    int front;
    int rear;
    int capacity;
    int* base;  //存储空间的基地址
};

//队列的初始化
void InitQueue(Queue& Q,int capacity) 
{
    Q.base = new int[capacity];
    Q.capacity = capacity;
    Q.front = Q.rear = 0;
}

//判断队列是否为空
bool IsEmpty(Queue Q)
{
    return Q.front == Q.rear;
}

//判断队列是否已满
bool IsFull(Queue Q)
{
    return Q.rear == Q.capacity;
}

//求队列长度
int QueueLength(Queue Q)
{
    return Q.rear - Q.front;
}

//入队操作
void EnQueue(Queue& Q, int element)
{
    if (IsFull(Q))
    {
        cout << "队列已满，无法插入元素" << endl;
        return;
    }
    else
    {
        cout << element << "已插入队列" << endl;
        Q.base[Q.rear] = element;
        Q.rear++;
    }
}

//出队操作
void DeQueue(Queue& Q)
{
    if (IsEmpty(Q))
    {
        cout << "队列为空，无法删除元素" << endl;
        return;
    }
    int i = Q.front;
    cout << Q.base[i] << "已出队" << endl;
    Q.front++;
}

//取队头元素
int GetHead(Queue Q) 
{
    if (!IsEmpty(Q))
    {
        return Q.base[Q.front];
    }
}

//打印队列元素
void PrintQueue(Queue Q)
{
    if (IsEmpty(Q))
    {
        cout << "队列为空" << endl;
        return;
    }

    cout << "队列元素: ";
    for (int i = Q.front; i < Q.rear; i++)
    {
        cout << Q.base[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue Q;
    int capacity = 5;
    InitQueue(Q, capacity);

    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    EnQueue(Q, 6);  // 队列已满，无法插入元素

    PrintQueue(Q);  // 队列元素: 1 2 3 4 5

    DeQueue(Q);
    DeQueue(Q);

    PrintQueue(Q);  // 队列元素: 3 4 5

    return 0;
}
