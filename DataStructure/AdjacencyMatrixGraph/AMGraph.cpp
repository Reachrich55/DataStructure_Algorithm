#include <iostream>

using namespace std;

const int MVNum = 10;      // 最大顶点数
const int MaxWeight = 63;    //表示极大值 

// 图邻接矩阵表示法的存储结构
struct AMGraph {
    int vexNum;     // 顶点数
    int arcNum;     //边数
    char vexs[MVNum];      //顶点表
    int matrix[MVNum][MVNum];     // 邻接矩阵
};

//在图G中查找顶点x，返回x在顶点表中的下标
int searchVertex(AMGraph* G, char x) {
    int i = 0;
    for ( i = 0; i < G->vexNum; i++)
    {
        if (G->vexs[i] == x) break;
    }
    return i;
}

// 返回顶点的第一个邻接点的下标，若无则返回-1
int firstAdjVex(AMGraph G, int v) {
    for (int i = 0; i < G.vexNum; i++) {
        if (G.matrix[v][i] > 0 && G.matrix[v][i] < MaxWeight) {
            return i;
        }
    }
    return -1;
}

// 返回v相对于w的下一个邻接点的下标，若w是v的最后一个邻接点，则返回-1
int nextAdjVex(AMGraph G, int v, int w) {
    for (int i = w + 1; i < G.vexNum; i++) {
        if (G.matrix[v][i] > 0 && G.matrix[v][i] < MaxWeight) {
            return i;
        }
    }
    return -1;
}

// 创建无向图
void createUDG(AMGraph& G, int vexNum, int arcNum) {
    G.vexNum = vexNum;
    G.arcNum = arcNum;
    //输入顶点
    printf("Please input the name of vertices(just like A B C):");
    for (int i = 0; i < G.vexNum; i++) {
        cin >> G.vexs[i];
    }
    //把矩阵初始化
    for (int i = 0; i < G.vexNum; ++i)
        for (int j = 0; j < G.vexNum; ++j)
            if (i == j) G.matrix[i][j] = 0;
            else G.matrix[i][j] = MaxWeight;

    char v1, v2;
    int index_v1, index_v2;
    int weight = 1;
    //输入边
    for (int i = 0; i < G.arcNum; i++)
    {
        printf("Input  edges : v1, v2, weight\n");
        cin >> v1 >> v2 >> weight;
        index_v1 = searchVertex(&G, v1);
        index_v2 = searchVertex(&G, v2);
        
        G.matrix[index_v1][index_v2] = weight;
        G.matrix[index_v2][index_v1] = weight;
    }
    
}

// 创建有向图
void createDG(AMGraph& G, int vexNum, int arcNum) {
    G.vexNum = vexNum;
    G.arcNum = arcNum;
    //输入顶点
    printf("Please input the name of vertices(just like A B C):");
    for (int i = 0; i < G.vexNum; i++) {
        cin >> G.vexs[i];
    }
    //把矩阵初始化
    for (int i = 0; i < G.vexNum; ++i)
        for (int j = 0; j < G.vexNum; ++j)
            if (i == j) G.matrix[i][j] = 0;
            else G.matrix[i][j] = MaxWeight;

    char v1, v2;
    int index_v1, index_v2;
    int weight = 1;
    //输入边
    for (int i = 0; i < G.arcNum; i++)
    {
        printf("Input  edges : v1, v2, weight\n");
        cin >> v1 >> v2 >> weight;
        index_v1 = searchVertex(&G, v1);
        index_v2 = searchVertex(&G, v2);

        G.matrix[index_v1][index_v2] = weight;
    }
}

// 添加边
void addEdge(AMGraph& G, int u, int v, int w) {
    G.matrix[u][v] = w;
    G.matrix[v][u] = w;     // 无向图需要添加反向边
    G.arcNum += 1;
}

// 输出邻接矩阵
void printAM(AMGraph G) {
    for (int i = 0; i < G.vexNum; i++) {
        for (int j = 0; j < G.vexNum; j++) {
            cout << G.matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 测试代码
int main() {
    AMGraph G;
    createDG(G, 7, 11);  
    printAM(G);
    return 0;
}
