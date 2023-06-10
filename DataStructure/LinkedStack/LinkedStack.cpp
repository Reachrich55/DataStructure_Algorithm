#include <iostream>

using namespace std;

//链栈的存储结构
typedef struct StackNode
{
	int data;
	struct StackNode* next;
}StackNode, * LinkStack;

//链栈的初始化
void InitStack(LinkStack& S)
{//构造一个空栈S，栈顶指针置空
	S = NULL;
}

//入栈
void Push(LinkStack& S, int e)
{// 在栈顶插入元素e

	StackNode *p = new StackNode;//生成新节点
	p->data = e;//将新节点数据域置为e
	p->next = S;//将新节点插入栈顶
	S = p;//修改栈顶指针p
}

//出栈
int Pop(LinkStack& S)
{//删除S的栈顶元素，用e返回其值 
	if (S == NULL)
	{
		cout<<"栈空"<<endl;//栈空 
		return -1;
	}
	int e = S->data;//将栈顶元素赋给e 
	StackNode *p = S;//用p临时保存栈顶元素空间，以备释放 
	S = S->next;//修改栈顶指针 
	delete p;//释放原栈顶元素的空间 
	return e;
}

//取栈顶元素
int GetTop(LinkStack S)
{//返回S的栈顶元素，不修改栈顶指针 
	if (S != NULL)//栈非空 
		return S->data;
	else
	{
		cout << "栈空" << endl;
		return -1;
	}
}

//遍历链栈
void Traverse(LinkStack S) 
{
	cout << "Stack: ";
	while (S != NULL) {
		cout << S->data << " ";
		S = S->next;
	}
	cout << endl;
}

int main()
{
	LinkStack S;
	InitStack(S);
	Push(S, 1);
	Push(S, 2);
	Push(S, 3);
	Traverse(S);
	cout << "Top element: " << GetTop(S) << endl;
	cout << "Pop element: " << Pop(S) << endl;
	cout << "Pop element: " << Pop(S) << endl;
	Traverse(S);
	cout << "Top element: " << GetTop(S) << endl;
	return 0;
}
