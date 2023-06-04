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

// 中序遍历二叉树
void InOrderTraverse(BiTree T) 
{
    if (T == NULL) 
    {
        return;
    }
    InOrderTraverse(T->lchild); // 遍历左子树
    cout << T->data; // 输出节点数据
    InOrderTraverse(T->rchild); // 遍历右子树
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
    InOrderTraverse(T);
    return 0;
}
