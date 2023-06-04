#include <iostream>

using namespace std;

//顺序表的存储结构
struct SeqList 
{
    int *data;  // 指向存储元素的数组
    int length; // 顺序表中元素的个数
    int capacity; // 顺序表的容量，即数组大小
};

//初始化顺序表
void InitList(SeqList& list, int capacity) 
{
    list.data = new int[capacity]; // 创建一个大小为capacity的数组
    list.length = 0; // 初始长度为0
    list.capacity = capacity; // 容量为capacity
}

//打印
void printf(SeqList& list)
{
    for (int i = 0; i < list.length; i++)
    {
        cout<<list.data[i] ; 
        cout << "\t";
    }
    cout << endl;
}

//取值
int GetElem(SeqList& list, int i) {
    if (i < 1 || i > list.length) { // 检查下标是否越界
        cout<<"下标越界"<<endl;
        return -1;
    }
    return list.data[i-1]; // 返回指定位置的元素
}

//查找
int LocateElem(SeqList& list, int e)
{
    for (int i = 0; i < list.length; i++)
    {
        if (list.data[i] == e) 
            return i + 1; //查找的是该元素位于线性表中的位置
    }
    cout << "查找失败" << endl;
}

//插入,在第I个位置
void ListInsert(SeqList& list, int element,int i) 
{
    if (list.length >= list.capacity) 
    { // 检查是否还有空间可用
        return ; // 没有空间可用，插入失败
    }
    //后移
    for (int j = list.length-1; j>=i-1; j--)
    {
        list.data[j + 1] = list.data[j];
    }
    list.data[i-1] = element; // 将元素插入第I个位置
    list.length++; // 更新长度
}

//删除,在第I个位置
void ListDelete(SeqList& list, int i) 
{
    //检验i合法
    if (i<1 || i>list.length) return;
    //前移覆盖
    for (int j = i; j <= list.length-1; j++)
    {
        list.data[j - 1] = list.data[j];
    }
    list.length--;
}

//销毁
void Destroy(SeqList& list) {
    delete[] list.data; // 释放数组内存
    list.length = 0; // 重置长度
    list.capacity = 0; // 重置容量
}

int main()
{
    SeqList L; //定义变量
    InitList(L, 10); //初始化
    //赋值
    int length;
    cout << "线性表长度：" << endl;
    cin >> length;
    L.length = length;
    cout << "线性表元素：" << endl;
    for (int i = 0; i < L.length; i++)
    {
        cin >> L.data[i];
    }
    cout << "原始线性表：" << endl;
    printf(L);
}
