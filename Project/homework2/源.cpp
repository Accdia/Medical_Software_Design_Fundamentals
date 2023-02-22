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
    int* tmp = new int[n];//申请动态内存
    int k = 0;
    int count[10];
    int radix = 1;
    for (int i = 1; i <= d; i++) //进行d次排序
    {
        for (int j = 0; j < 10; j++)
        {
          count[j] = 0; //清空计数器
        }
        for (int j = 0; j < n; j++)
        {
           k = (data[j] / radix) % 10;
           count[k]++; //统计对应桶中含有的数字个数
        }
        for (int j = 1; j < 10; j++)
        {
          count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶，即确定每个桶中最后一个数在tmp中的位置
        }
        for (int j = n - 1; j >= 0; j--) 
        {
          k = (data[j] / radix) % 10;//确定基数
          tmp[count[k] - 1] = data[j];//放入数字
          count[k]--;//向前移一位
        }
        for (int j = 0; j < n; j++) //将临时数组的内容复制到data中
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
    maxdigits(array, i);
    radixsort(array, i);
    for (int n = 0; n < i; n++)
    {
        cout << array[n] << " ";
    }
    return 0;
}