#include <iostream>
using namespace std;
typedef struct node     /*����ṹ��*/
{
	int factor;  //ϵ��
	int indice;  //��
	struct node* next;
}node, * LinkList;

void CreateLink(LinkList& L, int n)
{
	LinkList p, s;
	int i;

	L = (LinkList)malloc(sizeof(node));  //ͷ���
	L->next = NULL;

	p = L;
	for (i = 0; i < n; i++)    //β�巨������
	{
		s = (LinkList)malloc(sizeof(node));
		cout << "�������" << i + 1 << "���ϵ�����ݣ�" ;
		cin >> s->factor >> s->indice;
		s->next = NULL;
		p->next = s;
		p = s;
	}
}

void AddList(LinkList List1, LinkList List2, LinkList& L)
{
	LinkList p1, p2, list, s;

	L = (LinkList)malloc(sizeof(node));  //���ϲ����������ͷ���
	L->next = NULL;

	list = L;
	p1 = List1->next;
	p2 = List2->next;

	while (p1 && p2)  //p1,p2����������ʱѭ��
	{
		if (p1->indice < p2->indice)  //p1����С��p2���ݣ���p2�����뵽list������
		{
			s = p2->next;       //�ҵ�Ҫ�Ͽ����ĺ�̽��
			list->next = p2;    //����
			list = p2;
			list->next = NULL;  //�Ͽ�
			p2 = s;
		}
		else if (p1->indice == p2->indice)  //p1���ݵ���p2����
		{
			p1->factor = p1->factor + p2->factor;

			if (p1->factor != 0)//ϵ���Ͳ�Ϊ0  
			{
				s = p1->next;
				list->next = p1;
				list = p1;
				list->next = NULL;
				p1 = s;

				p2 = p2->next;
			}
			else //ϵ����Ϊ0�����������
			{
				p1 = p1->next;
				p2 = p2->next;
			}
		}
		else      //p1���ݴ���p2���ݣ���p1�����뵽list������
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
	cout << "�����һ������ʽ�ڵ����:";
	cin >> num;
	CreateLink(List1, num);
	cout << "��һ������ʽΪ��";
	VisitList(List1);

	cout << "����ڶ�������ʽ�ڵ����:";
	cin >> num;
	CreateLink(List2, num);
	cout << "�ڶ�������ʽΪ��";
	VisitList(List2);

	cout << "����ʽ�ϲ����Ϊ��";
	AddList(List1, List2,L);
	VisitList(L);
	system("pause");
	return 0;
}