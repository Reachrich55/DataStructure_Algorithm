#include <iostream>

using namespace std;

//二叉树的链式存储结构
typedef struct BiTNode {
    char data; // 数据
    struct BiTNode* lchild, * rchild; // 左子树和右子树的指针
} BiTNode, * BiTree;

// 先序创建二叉树
void PreCreateBiTree(BiTree& T) 
{
    char data;
    cin >> data;
    if (data == '#') 
    { 
        //根据输出字符识别空结点，'#' 代表空结点
        T = NULL;//设置空结点
    }
    else 
    {
        T = new BiTNode; // 分配内存
        T->data = data; // 存储数据
        PreCreateBiTree(T->lchild); // 递归创建左子树
        PreCreateBiTree(T->rchild); // 递归创建右子树
    }
}

// 先序遍历二叉树
void PreOrderTraverse(BiTree T) 
{
    if (T == NULL) 
    {
        return;
    }
    cout<< T->data; // 输出节点数据
    PreOrderTraverse(T->lchild); // 遍历左子树
    PreOrderTraverse(T->rchild); // 遍历右子树
}

// 中序遍历二叉树(递归）
void InOrderTraverse1(BiTree T) {
    if (T == NULL) {
        return;
    }
    InOrderTraverse1(T->lchild); // 遍历左子树
    cout << T->data; // 输出节点数据
    InOrderTraverse1(T->rchild); // 遍历右子树
}

// 中序遍历二叉树(非递归)
// 初始化栈：在开始之前，你需要创建一个空栈，并确保栈为空。
// 遍历过程：从根节点开始，将当前节点及其左子树的所有左孩子依次入栈，直到左孩子为空。
// 弹出节点并访问：从栈中弹出一个节点，并访问该节点的数据。
// 处理右子树：如果该节点存在右子树，将右子树作为当前节点，并将其左子树及其左孩子入栈，重复步骤3。
// 重复操作：重复上两个步骤，直到栈为空且当前节点为NULL。
void InOrderTraverse2(BiTree T) {
    SeqStack S;
    InitStack(S, 5);
    BiTree p = T;
    BiTNode* q;
    while (p || S.top != S.base)
    {
        if (p) 
        {
            Push(S, p);
            p = p->lchild;
        }
        else
        {
            Pop(S, q);
            cout << q->data;
            p = q->rchild;
        }
    }
    cout << endl;
}

// 后序遍历二叉树
void PostOrderTraverse(BiTree T) 
{
    if (T == NULL)
    {
        return;
    }
    PostOrderTraverse(T->lchild); // 遍历左子树
    PostOrderTraverse(T->rchild); // 遍历右子树
    cout << T->data; // 输出节点数据
}

int main() {
    BiTree T = NULL;
    //ABC##DE#G##F###
    PreCreateBiTree(T);
    InOrderTraverse1(T);
    return 0;
}
