#include <iostream>

using namespace std;

//快速排序
void QuickSort(int arr[], int left, int right) {
    if (left < right) {
        // 将数组划分为两部分

        int pivot = arr[left]; // 选择第一个元素作为枢轴
        int i = left;
        int j = right;

        while (i != j) // 一趟快排，为枢轴寻找最终位置
        {
            while (i < j && arr[j] >= pivot) // 从右向左扫描，找到第一个小于枢轴的元素
                j--;
            if (i < j)
                arr[i++] = arr[j]; // 将找到的小于枢轴的元素放入左边，然后将i指针向右移动
            while (i < j && arr[i] <= pivot) // 从左向右扫描，找到第一个大于枢轴的元素
                i++;
            if (i < j)
                arr[j--] = arr[i]; // 将找到的大于枢轴的元素放入右边，然后将j指针向左移动
        }
        
        // 将枢轴元素放入正确的位置
        arr[i] = pivot;

        // 递归对划分的两部分进行排序
        QuickSort(arr, left, i - 1);
        QuickSort(arr, i + 1, right);
    }
    else return; // 递归出口
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

    QuickSort(arr, 0, n - 1);

    printf("排序后的数组: ");
    printArray(arr, n);

    return 0;
}
