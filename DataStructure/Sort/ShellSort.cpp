#include <iostream>

using namespace std;

//希尔排序
void ShellSort(int arr[], int n) {
    int gap, i, j, temp;

    // 设置初始间隔
    for (gap = n / 2; gap > 0; gap /= 2) {
        // 在每个间隔内进行插入排序
        for (i = gap; i < n; i++) {
            temp = arr[i];

            // 移动已排序元素，为当前元素腾出位置
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
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

    ShellSort(arr, n);

    printf("排序后的数组: ");
    printArray(arr, n);

    return 0;
}
