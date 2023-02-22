#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void compare(int arr[], int len, int index)
{
    int left = 2 * index + 1;//代表index节点的左孩子
    int right = 2 * index + 2;//代表index节点的右孩子
    int maxIdx = index;//父节点
    if (left<len && arr[left] > arr[maxIdx]) 
    {
        maxIdx = left;
    }
    if (right<len && arr[right] > arr[maxIdx])
    {
        maxIdx = right;  // maxIdx是3个数中最大数的下标
    }
    if (maxIdx != index)// 如果maxIdx的值有更新
    {
      swap(arr[maxIdx], arr[index]);
      compare(arr, len, maxIdx);// 父节点改变导致其堆中大小关系需要重新调整，故递归调整其不满足堆性质的部分
    }
}
void locating(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)  // 对每一个非叶结点进行堆调整(从最后一个非叶结点开始)
    {
        compare(arr, size, i);
    }
    for (int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);// 将当前最大的放置到数组末尾
        compare(arr, i, 0);// 将未完成排序的部分继续进行堆排序，且无需调整最后一个数字
    }
}
int main()
{
    int i;
    cout << "请输入数组长度:";
    cin >> i;
    cout << endl;
    int* array = new int[i];
    for (int m = 0; m < i; m++)
    {
        cout << "请输入第" << m + 1 << "项数字:";
        cin >> array[m];
        cout << endl;
    }//手动创建数组
    locating(array, i);
    for (int n = 0; n < i ; n++)
    {
        cout << array[n] << " ";
    }
    return 0;
}