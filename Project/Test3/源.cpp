#include<iostream>
#include<cstring>
using namespace std;

typedef struct {
	int weight;
	int parent, lchild, rchild;
}HTNode, * HuffmanTree;

typedef char** HuffmanCode;//动态分配数组存储哈夫曼编码

void select(HuffmanTree& a, int n, int& s1, int& s2)
{
	for (int i = 1; i = n; i++)
	{
		if (a[i].parent == 0)// 初始化s1,s1的双亲为0
		{
			s1 = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++)// s1为权值最小的下标
	{
		if (a[i].parent == 0 && a[s1].weight > a[i].weight)
			s1 = i;
	}
	for (int j = 1; j <= n; j++)
	{
		if (a[j].parent == 0 && j != s1)// 初始化s2,s2的双亲为0
		{
			s2 = j;
			break;
		}
	}
	for (int j = 1; j <= n; j++)// s2为另一个权值最小的结点
	{
		if (a[j].parent == 0 && a[s2].weight > a[j].weight && j != s1)   s2 = j;
	}
}


void CreateHuffmanTree(HuffmanTree& HT, int n)//构造哈夫曼树HT
{
	if (n <= 1) return;
	int m = 2 * n - 1; //数组共2n-1个元素 
	HT = new HTNode[2 * n];  //0号单元未用，HT[m]表示根结点 
	for (int i = 1; i <= m; ++i)  //将2n-1个元素的 lch、rch、parent置为0 
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (int i = 1; i <= n; ++i) //输入前n个元素的weight值 
	{
		cin >> HT[i].weight;
	}
	/* ---初始化结束，下面开始建立哈夫曼树---  */
	for (int i = n + 1; i <= m; ++i)  //合并产生n-1个结点——构造Huffman树 
	{
		int s1, s2;
		select(HT, i - 1, s1, s2);  //在HT[k](1≤k ≤i-1)中选择两个其双亲域为0，
								 //且权值最小的结点，并返回它们在HT中的序号s1和s2							 
		HT[s1].parent = i;
		HT[s2].parent = i;      //表示从F中删除s1，s2
		HT[i].lchild = s1;
		HT[i].rchild = s2;      //s1，s2分别作为i的左右孩子 
		HT[i].weight = HT[s1].weight + HT[s2].weight;	//i的权值为左右孩子权值之和 
	}
}

void CreatHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n)
{  //从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中 
	HC = new char* [n + 1];         //分配n个字符编码的头指针矢量 
	char* cd = new char[n];      //分配临时存放的编码的动态数组空间 
	cd[n - 1] = '\0';                //编码结束符 
	for (int i = 1; i <= n; ++i)   //逐个字符求哈夫曼编码 
	{
		int start = n - 1;
		int c = i;
		int f = HT[i].parent;    //f即为当前的双亲结点 
		while (f != 0)              //从叶子节点开始向上回溯，直到根结点 
		{
			--start;             //回溯一次start向前一个位置 
			if (HT[f].lchild == c) cd[start] = '0';  //结点c是f的左孩子，则生成代码0 
			else cd[start] = '1';    //结点c是f的右孩子，则生成代码1 
			c = f; f = HT[f].parent;  //继续向上回溯 
		}                           //求出第i个字符的编码 
		HC[i] = new char[n - start];   //为第i个字符串编码分配空间 
		strcpy(HC[i], &cd[start]);  // 将求得的编码从临时空间cd复制到HC的当前中 
	}
	delete cd;                      //释放临时空间 
}


void print(HuffmanTree HT, int n) // 打印哈夫曼树
{
	cout << "index weight parent lChild rChild" << endl;
	for (int i = 1; i <= n; ++i)
	{
		printf("%5d %6d %6d %6d %6d\n", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	}
}

int main()
{
	cout << "二叉树的应用——实现哈夫曼树以及哈夫曼编码" << endl << endl;
	//	int x[] = { 5,29,7,8,14,23,3,11 };        

	int n;
	cout << "请输入叶子结点的个数为：";
	cin >> n;
	HTNode* HT = new HTNode[2 * 8];    // 动态创建数组
	CreateHuffmanTree(HT, n);
	cout << "哈夫曼树表达：" << endl;
	print(HT, 2 * n - 1);

	HuffmanCode HC = NULL;//初始化编码表为空表
	CreatHuffmanCode(HT, HC, n);
	cout << "哈夫曼编码为：" << endl;
	cout << "结点i" << "\t" << "权值" << "\t" << "编码" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << i << "\t" << HT[i].weight << "\t" << HC[i] << endl;
	}
	cout << endl;


	system("pause");

	return 0;
}
