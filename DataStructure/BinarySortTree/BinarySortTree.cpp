#include <iostream>

using namespace std;

//二叉排序树的存储结构
typedef struct BSTNode {
    int data; // 数据
    struct BSTNode* lchild, * rchild; // 左子树和右子树的指针
} BSTNode, * BSTree;

// 中序遍历二叉树
void InOrderTraverse(BSTree T) {
    if (T == NULL) {
        return;
    }
    InOrderTraverse(T->lchild); // 遍历左子树
    cout << T->data<<' '; // 输出节点数据
    InOrderTraverse(T->rchild); // 遍历右子树
}

//查找
BSTree SearchBST(BSTree T, int key) {
    if (!T || T->data == key) return T;
    else if (T->data > key) return SearchBST(T->lchild, key);
    else return SearchBST(T->rchild, key);
}

//插入节点
void InsertBST(BSTree& T, int key)
{
    if (!T)
    {
        T = new BSTNode;
        T->data = key;
        T->lchild = T->rchild = NULL;
    }
    else if (T->data > key)
        InsertBST(T->lchild, key);
    else if (T->data < key)
        InsertBST(T->rchild, key);
    else return;    //T->data = key 关键字不唯一，错误
}

//创建
void CreateBST(BSTree& T) {
    //T = NULL;//初始化为空树
    int data;
    cin >> data;
    if (data!=-1)
    {
        InsertBST(T, data);
        CreateBST(T);
    }
}

//删除
//待删除结点为叶子结点：直接删除即可。
//待删除结点有一个孩子：将待删除结点的孩子与其父结点相连即可。
//待删除结点有两个孩子：找到待删除结点的中序遍历的前驱或后继结点，将其值复制到待删除结点中，再删除前驱或后继结点。
// 二叉排序树的删除操作
void DeleteBST(BSTree &T, int key) {

    BSTree p = T;
    BSTree parent = NULL;
    while (p) { 
        if (p->data == key)
            break; //退出循环此时p指向要删除节点
        else if (key < p->data) {
            parent = p; //通过比较key值定位要删除节点
            p = p->lchild;
        }
        else {
            parent = p;
            p = p->rchild;
        }
    }
    //若循环结束则直接return，说明没找key
    if (!p) {
        return;
    }
    //当控制来到此行时，说明p指向了要删除的节点
    BSTNode* pfree = NULL;
    BSTNode* node = NULL;
    if (p->lchild && p->rchild) { //第一种情况 p的左右子树不为空
        BSTNode* prior = p->lchild; // p的直接前驱一定在p的左子树上，所以prior = p的左孩子
        BSTNode* parent_prior = p; //需要一个节点来定位prior的双亲结点
        while (prior->rchild) { //在右分支上寻找要删除节点p的直接前驱
            parent_prior = prior;
            prior = prior->rchild;
        }
        p->data = prior->data; //把前驱节点的值赋给要删除节点
        //此时问题转化成了：在保持序列顺序的前提下，如何链接二叉排序树
        if (parent_prior != p) {
            parent_prior->rchild = prior->lchild;
        }
        else { //此种情况p的直接前驱为p的左孩子，
            parent_prior->lchild = prior->lchild;
        }
        free(prior);
        return;
    }
    //p只有左子树或右子树
    else if (!p->lchild) {
        pfree = p; // pfree用于存放 要删除节点的地址
        node = p->rchild; // node存放需要链接节点的地址
    }
    else if (!p->rchild) {
        pfree = p;
        node = p->lchild;
    }
    //当控制来到此行时，pfree保存要删除节点的地址，node存放需要连接的节点地址
    if (!parent) { //如果parent域仍然为空，说明要删除的节点为根节点
        T = node;

    }
    else if (parent->rchild == p) {
        parent->rchild = node;
    }
    else {
        parent->lchild = node;
    }
    free(pfree);
}

int main()
{
    BSTree T = NULL;
    CreateBST(T);
    //12 7 17 11 16 2 13 9 21 4 -1
    InOrderTraverse(T);
    cout << "\n";
    DeleteBST(T, 12);
    InOrderTraverse(T);
}
