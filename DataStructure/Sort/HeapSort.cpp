#include <iostream>

using namespace std;

//堆排序
void HeapAdjust(int arr[], int n, int i) {
    int largest = i;    // 根节点
    int left = 2 * i + 1;    // 左子节点
    int right = 2 * i + 2;    // 右子节点

    // 如果左子节点大于根节点
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点大于根节点
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是根节点，则交换并对受影响的子树进行堆化
    if (largest != i) {
        swap(arr[i], arr[largest]);
        HeapAdjust(arr, n, largest);
    }
}

void HeapSort(int arr[], int n) {
    // 构建最大堆（初始状态）
    for (int i = n / 2 - 1; i >= 0; i--)
        HeapAdjust(arr, n, i);

    // 逐个将最大值移动到数组末尾，并对剩余部分重新构建最大堆
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        HeapAdjust(arr, i, 0);
    }
}

//打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 49,38,65,97,76,13,27,49 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组: ");
    printArray(arr, n);

    HeapSort(arr, n);

    printf("排序后的数组: ");
    printArray(arr, n);

    return 0;
}
