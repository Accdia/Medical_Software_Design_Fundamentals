#include <iostream>
using namespace std;
typedef struct node     /*定义结构体*/
{
	int factor;  //系数
	int indice;  //幂
	struct node* next;
}node, * LinkList;

void CreateLink(LinkList& L, int n)
{
	LinkList p, s;
	int i;

	L = (LinkList)malloc(sizeof(node));  //头结点
	L->next = NULL;

	p = L;
	for (i = 0; i < n; i++)    //尾插法建链表
	{
		s = (LinkList)malloc(sizeof(node));
		cout << "请输入第" << i + 1 << "项的系数和幂：" ;
		cin >> s->factor >> s->indice;
		s->next = NULL;
		p->next = s;
		p = s;
	}
}

void AddList(LinkList List1, LinkList List2, LinkList& L)
{
	LinkList p1, p2, list, s;

	L = (LinkList)malloc(sizeof(node));  //建合并后新链表的头结点
	L->next = NULL;

	list = L;
	p1 = List1->next;
	p2 = List2->next;

	while (p1 && p2)  //p1,p2两个链表不空时循环
	{
		if (p1->indice < p2->indice)  //p1的幂小于p2的幂，将p2结点加入到list链表中
		{
			s = p2->next;       //找到要断开结点的后继结点
			list->next = p2;    //链入
			list = p2;
			list->next = NULL;  //断开
			p2 = s;
		}
		else if (p1->indice == p2->indice)  //p1的幂等于p2的幂
		{
			p1->factor = p1->factor + p2->factor;

			if (p1->factor != 0)//系数和不为0  
			{
				s = p1->next;
				list->next = p1;
				list = p1;
				list->next = NULL;
				p1 = s;

				p2 = p2->next;
			}
			else //系数和为0，继续向后找
			{
				p1 = p1->next;
				p2 = p2->next;
			}
		}
		else      //p1的幂大于p2的幂，将p1结点加入到list链表中
		{
			s = p1->next;
			list->next = p1;
			list = p1;
			list->next = NULL;
			p1 = s;
		}
	}
	if (p1 != NULL) list->next = p1;
	if (p2 != NULL) list->next = p2;
}

void VisitList(LinkList L)
{
	LinkList p;
	p = L->next;
	if (p == NULL)
	{
		cout << "0" << endl;
	}
	while (p)
	{
		cout << p->factor << "X^" << p->indice;
		p = p->next;
		if (p != NULL)
			cout << "+";
	}
	cout << endl;
}

int main()
{
	LinkList List1, List2, L;
	int num;
	cout << "输入第一个多项式节点个数:";
	cin >> num;
	CreateLink(List1, num);
	cout << "第一个多项式为：";
	VisitList(List1);

	cout << "输入第二个多项式节点个数:";
	cin >> num;
	CreateLink(List2, num);
	cout << "第二个多项式为：";
	VisitList(List2);

	cout << "多项式合并结果为：";
	AddList(List1, List2,L);
	VisitList(L);
	system("pause");
	return 0;
}