#include <iostream>
using namespace std;

int maxdigits(int arr[],int n)
{
    int a, b, i;
    a = 1; b = 10; i = 0;
    while (i<n)
    {
        if (arr[i] > b)
        {
            a++;
            b = b * 10;
            i = 0;
        }
        else i++;
    }
    return a;
}

void radixsort(int data[], int n)
{
    int d = maxdigits(data, n);
    int* tmp = new int[n];//���붯̬�ڴ�
    int k = 0;
    int count[10];
    int radix = 1;
    for (int i = 1; i <= d; i++) //����d������
    {
        for (int j = 0; j < 10; j++)
        {
          count[j] = 0; //��ռ�����
        }
        for (int j = 0; j < n; j++)
        {
           k = (data[j] / radix) % 10;
           count[k]++; //ͳ�ƶ�ӦͰ�к��е����ָ���
        }
        for (int j = 1; j < 10; j++)
        {
          count[j] = count[j - 1] + count[j]; //��tmp�е�λ�����η����ÿ��Ͱ����ȷ��ÿ��Ͱ�����һ������tmp�е�λ��
        }
        for (int j = n - 1; j >= 0; j--) 
        {
          k = (data[j] / radix) % 10;//ȷ������
          tmp[count[k] - 1] = data[j];//��������
          count[k]--;//��ǰ��һλ
        }
        for (int j = 0; j < n; j++) //����ʱ��������ݸ��Ƶ�data��
        {
          data[j] = tmp[j];
        }
        radix = radix * 10;
    }
    delete tmp;
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
    maxdigits(array, i);
    radixsort(array, i);
    for (int n = 0; n < i; n++)
    {
        cout << array[n] << " ";
    }
    return 0;
}