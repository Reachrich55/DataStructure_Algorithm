#include <iostream>

using namespace std;

//冒泡排序
void BubbleSort(int arr[], int n) {
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j]>arr[1+j])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 1;
            }
            if (flag == 0)
                break;
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

    BubbleSort(arr, n);

    printf("排序后的数组: ");
    printArray(arr, n);

    return 0;
}
