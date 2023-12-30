#include <iostream>

using namespace std;

//二分插入排序
void BinaryInsertSort(int arr[], int n) {
    int i, j, tmp, left, mid, right;
    for ( i = 1; i < n; i++)
    {
        tmp = arr[i];
        left = 0;
        right = i - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (tmp < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        for (j = i - 1; j >= left; j--)   
            arr[j + 1] = arr[j];
        if (left != i)  
            arr[left] = tmp;
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

    BinaryInsertSort(arr, n);

    printf("排序后的数组: ");
    printArray(arr, n);

    return 0;
}
