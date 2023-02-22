#include<iostream>
#include<cstring>
using namespace std;

typedef struct {
	int weight;
	int parent, lchild, rchild;
}HTNode, * HuffmanTree;

typedef char** HuffmanCode;//��̬��������洢����������

void select(HuffmanTree& a, int n, int& s1, int& s2)
{
	for (int i = 1; i = n; i++)
	{
		if (a[i].parent == 0)// ��ʼ��s1,s1��˫��Ϊ0
		{
			s1 = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++)// s1ΪȨֵ��С���±�
	{
		if (a[i].parent == 0 && a[s1].weight > a[i].weight)
			s1 = i;
	}
	for (int j = 1; j <= n; j++)
	{
		if (a[j].parent == 0 && j != s1)// ��ʼ��s2,s2��˫��Ϊ0
		{
			s2 = j;
			break;
		}
	}
	for (int j = 1; j <= n; j++)// s2Ϊ��һ��Ȩֵ��С�Ľ��
	{
		if (a[j].parent == 0 && a[s2].weight > a[j].weight && j != s1)   s2 = j;
	}
}


void CreateHuffmanTree(HuffmanTree& HT, int n)//�����������HT
{
	if (n <= 1) return;
	int m = 2 * n - 1; //���鹲2n-1��Ԫ�� 
	HT = new HTNode[2 * n];  //0�ŵ�Ԫδ�ã�HT[m]��ʾ����� 
	for (int i = 1; i <= m; ++i)  //��2n-1��Ԫ�ص� lch��rch��parent��Ϊ0 
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (int i = 1; i <= n; ++i) //����ǰn��Ԫ�ص�weightֵ 
	{
		cin >> HT[i].weight;
	}
	/* ---��ʼ�����������濪ʼ������������---  */
	for (int i = n + 1; i <= m; ++i)  //�ϲ�����n-1����㡪������Huffman�� 
	{
		int s1, s2;
		select(HT, i - 1, s1, s2);  //��HT[k](1��k ��i-1)��ѡ��������˫����Ϊ0��
								 //��Ȩֵ��С�Ľ�㣬������������HT�е����s1��s2							 
		HT[s1].parent = i;
		HT[s2].parent = i;      //��ʾ��F��ɾ��s1��s2
		HT[i].lchild = s1;
		HT[i].rchild = s2;      //s1��s2�ֱ���Ϊi�����Һ��� 
		HT[i].weight = HT[s1].weight + HT[s2].weight;	//i��ȨֵΪ���Һ���Ȩֵ֮�� 
	}
}

void CreatHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n)
{  //��Ҷ�ӵ���������ÿ���ַ��Ĺ��������룬�洢�ڱ����HC�� 
	HC = new char* [n + 1];         //����n���ַ������ͷָ��ʸ�� 
	char* cd = new char[n];      //������ʱ��ŵı���Ķ�̬����ռ� 
	cd[n - 1] = '\0';                //��������� 
	for (int i = 1; i <= n; ++i)   //����ַ������������ 
	{
		int start = n - 1;
		int c = i;
		int f = HT[i].parent;    //f��Ϊ��ǰ��˫�׽�� 
		while (f != 0)              //��Ҷ�ӽڵ㿪ʼ���ϻ��ݣ�ֱ������� 
		{
			--start;             //����һ��start��ǰһ��λ�� 
			if (HT[f].lchild == c) cd[start] = '0';  //���c��f�����ӣ������ɴ���0 
			else cd[start] = '1';    //���c��f���Һ��ӣ������ɴ���1 
			c = f; f = HT[f].parent;  //�������ϻ��� 
		}                           //�����i���ַ��ı��� 
		HC[i] = new char[n - start];   //Ϊ��i���ַ����������ռ� 
		strcpy(HC[i], &cd[start]);  // ����õı������ʱ�ռ�cd���Ƶ�HC�ĵ�ǰ�� 
	}
	delete cd;                      //�ͷ���ʱ�ռ� 
}


void print(HuffmanTree HT, int n) // ��ӡ��������
{
	cout << "index weight parent lChild rChild" << endl;
	for (int i = 1; i <= n; ++i)
	{
		printf("%5d %6d %6d %6d %6d\n", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	}
}

int main()
{
	cout << "��������Ӧ�á���ʵ�ֹ��������Լ�����������" << endl << endl;
	//	int x[] = { 5,29,7,8,14,23,3,11 };        

	int n;
	cout << "������Ҷ�ӽ��ĸ���Ϊ��";
	cin >> n;
	HTNode* HT = new HTNode[2 * 8];    // ��̬��������
	CreateHuffmanTree(HT, n);
	cout << "����������" << endl;
	print(HT, 2 * n - 1);

	HuffmanCode HC = NULL;//��ʼ�������Ϊ�ձ�
	CreatHuffmanCode(HT, HC, n);
	cout << "����������Ϊ��" << endl;
	cout << "���i" << "\t" << "Ȩֵ" << "\t" << "����" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << i << "\t" << HT[i].weight << "\t" << HC[i] << endl;
	}
	cout << endl;


	system("pause");

	return 0;
}
