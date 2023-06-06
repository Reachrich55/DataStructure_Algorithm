#include <iostream>

using namespace std;

const int MAXSIZE = 16;

// 判断质数
bool IsPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// 寻找最大质数
int GetMaxPrime(int n) {
    int max_prime = -1;
    for (int i = n; i >= 2; i--) {
        if (IsPrime(i)) {
            max_prime = i;
            break;
        }
    }
    return max_prime;
}

// 散列表的存储结构
struct HashTable {
    int key;
    //InfoType otherinfo 其他数据项
};

// 初始化散列表
void InitHashTable(HashTable* HT){
    HT[MAXSIZE];
    for (int i = 0; i < MAXSIZE; i++) {
    HT[i].key = 0;
    }
}

// 输出散列表
void PrintHashTable(HashTable* HT){
    for (int i = 0; i < MAXSIZE; i++) {
        if (HT[i].key != 0)
        {
            cout << i << ": " << HT[i].key << endl;
        }
    }
}

// 定义散列函数
int Hash(int key) {
    return key % GetMaxPrime(MAXSIZE);
}

// 线性探查法处理冲突
int LinearSearch(HashTable* HT, int hash_val, int key) {
    for (int i = 0; i < MAXSIZE; i++)
    {
        int index = (hash_val + i) % MAXSIZE;
        if (HT[index].key == 0) return -1;
        else if (HT[index].key == key) return index;
    }
    return -1;
}

// 添加键值对
void AddHash(HashTable* HT, int key) {
    int hash_val = Hash(key);
    int i = 0;
    while (true) {
        int index = (hash_val + i) % MAXSIZE;
        if (HT[index].key == 0) {
            HT[index].key = key;
            break;
        }
        i++;
        if (i == MAXSIZE) return;    //添加失败
    }
}

//查找关键字的地址
int HashSearch(HashTable* HT, int key) {
    int hash_val = Hash(key);
    int index = LinearSearch(HT, hash_val, key);
    return index;
}

int main() {
    
    HashTable HT[MAXSIZE];
    InitHashTable(HT);

    // 插入数据
    AddHash(HT, 19);
    AddHash(HT, 14);
    AddHash(HT, 23);
    AddHash(HT, 1);
    AddHash(HT, 68);
    AddHash(HT, 20);
    AddHash(HT, 84);
    AddHash(HT, 27);
    AddHash(HT, 55);
    AddHash(HT, 11);
    AddHash(HT, 10);
    AddHash(HT, 79);

    // 输出散列表
    PrintHashTable(HT);

    return 0;
}

