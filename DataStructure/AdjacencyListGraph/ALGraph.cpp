#include <iostream>

using namespace std;

const int MVNum = 10;   // 最大节点数

// 边结点
struct ArcNode {
    int adjvex;   //该边所指向的顶点的位置
    int weight;
    ArcNode* next;
};

//顶点结点
struct VNode {
    char vex;
    ArcNode* head;
};

// 定义图的结构体
struct ALGraph {
    int vexNum;     // 顶点数
    int arcNum;     //边数
    VNode vexs[MVNum];      //邻接表
};

//在图G中查找顶点x，返回x在顶点表中的下标
int searchVertex(ALGraph* G, char x) {
    int i = 0;
    for (i = 0; i < G->vexNum; i++)
    {
        if (G->vexs[i].vex == x) break;
    }
    return i;
}

// 创建无向图
void createUDG(ALGraph& G, int vexNum, int arcNum) {
    G.vexNum = vexNum;
    G.arcNum = arcNum;
    //输入顶点,构造表头结点表
    printf("Please input the name of vertices(just like A B C):");
    for (int i = 0; i < G.vexNum; i++) {
        cin >> G.vexs[i].vex;
        G.vexs[i].head = NULL;
    }

    char v1, v2;
    int index_v1, index_v2;
    int weight = 1;
    //输入边，构造边表
    for (int i = 0; i < G.arcNum; i++)
    {
        printf("Input  edges : v1, v2, weight\n");
        cin >> v1 >> v2 >> weight;
        index_v1 = searchVertex(&G, v1);
        index_v2 = searchVertex(&G, v2);

        ArcNode* p1 = new ArcNode;
        ArcNode* p2 = new ArcNode;
        //邻接点
        p1->adjvex = index_v2;
        p2->adjvex = index_v1;
        p1->weight = p2->weight = weight;
        //头插法
        p1->next = G.vexs[index_v1].head;
        G.vexs[index_v1].head = p1;
        p2->next = G.vexs[index_v2].head;
        G.vexs[index_v2].head = p2;
    }
}

//创建有向图
void createDG(ALGraph& G, int vexNum, int arcNum) {
    G.vexNum = vexNum;
    G.arcNum = arcNum;
    //输入顶点,构造表头结点表
    printf("Please input the name of vertices(just like A B C):");
    for (int i = 0; i < G.vexNum; i++) {
        cin >> G.vexs[i].vex;
        G.vexs[i].head = NULL;
    }

    char v1, v2;
    int index_v1, index_v2;
    int weight = 1;
    //输入边，构造边表
    for (int i = 0; i < G.arcNum; i++)
    {
        printf("Input edge: v1, v2, weight\n");
        cin >> v1 >> v2 >> weight;
        index_v1 = searchVertex(&G, v1);
        index_v2 = searchVertex(&G, v2);

        ArcNode* p = new ArcNode;
        //邻接点
        p->adjvex = index_v2;
        p->weight = weight;
        //头插法
        p->next = G.vexs[index_v1].head;
        G.vexs[index_v1].head = p;
    }
}

// 输出邻接表
void printGraph(ALGraph& G) {
    for (int i = 0; i < G.vexNum; i++) {
        cout << "Vertex " << G.vexs[i].vex << ": ";
        ArcNode* p = G.vexs[i].head;
        while (p) {
            cout << G.vexs[p->adjvex].vex << "(" << p->weight << ") ";
            p = p->next;
        }
        cout << endl;
    }
    cout << endl;
  
  // 测试代码
int main() {
    ALGraph G;
    createUDG(G, 5, 4);
    printGraph(G);
    return 0;
}
