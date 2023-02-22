#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void compare(int arr[], int len, int index)
{
    int left = 2 * index + 1;//����index�ڵ������
    int right = 2 * index + 2;//����index�ڵ���Һ���
    int maxIdx = index;//���ڵ�
    if (left<len && arr[left] > arr[maxIdx]) 
    {
        maxIdx = left;
    }
    if (right<len && arr[right] > arr[maxIdx])
    {
        maxIdx = right;  // maxIdx��3��������������±�
    }
    if (maxIdx != index)// ���maxIdx��ֵ�и���
    {
      swap(arr[maxIdx], arr[index]);
      compare(arr, len, maxIdx);// ���ڵ�ı䵼������д�С��ϵ��Ҫ���µ������ʵݹ�����䲻��������ʵĲ���
    }
}
void locating(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)  // ��ÿһ����Ҷ�����жѵ���(�����һ����Ҷ��㿪ʼ)
    {
        compare(arr, size, i);
    }
    for (int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);// ����ǰ���ķ��õ�����ĩβ
        compare(arr, i, 0);// ��δ�������Ĳ��ּ������ж�����������������һ������
    }
}
int main()
{
    int i;
    cout << "���������鳤��:";
    cin >> i;
    cout << endl;
    int* array = new int[i];
    for (int m = 0; m < i; m++)
    {
        cout << "�������" << m + 1 << "������:";
        cin >> array[m];
        cout << endl;
    }//�ֶ���������
    locating(array, i);
    for (int n = 0; n < i ; n++)
    {
        cout << array[n] << " ";
    }
    return 0;
}