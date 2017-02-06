//дан список из n целых чисел a1, a2,...,an. ¬ывести на экран элементы списка в указанной последовательности:
//a1,a2,...,a(n/2),an,a(n-1),...,a(n/2+1), n-четное

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <iostream>
#include <math.h>

using namespace std;

struct List
{
	int info;
	List *pred, *next;
};



void CreadeList (List *&head, List *&tail, int n)
{
	head=new List;
	tail=new List;
	head->next=tail;
	tail->pred=head;
	for(int i=0;i<n;i++)
	{
		List *p;
		p=new List;
		p->info=rand()%20-10;
		p->next=tail;
		p->pred=tail->pred;
		p->pred->next=p;
		tail->pred=p;
		
	}
	
}

void PrintList(List *&head, List *&tail)
{
	List *p=head->next;
	while (p!=tail)
	{
		cout<<p->info<<" ";
		p=p->next;
	}
	cout<<endl;
	return;
}

void Reorder(List *&head, List *&tail, int n)
{
	List *p=head->next;
	int k=n/2;
	for(int i=0;i<k;i++)
	{
		cout<<p->info<<" ";
		p=p->next;
	}
	p=tail->pred;
	for(int i=k+1;i<n+1;i++)
    {
		cout<<p->info<<" ";
		p=p->pred;
	}
}

void FreeList(List *&head, List *&tail)
{
	List *p=head->next;
	while(p!=tail)
	{
		delete p->info;
	}
}

void main ()
{
	int n;
	setlocale(LC_CTYPE, "Russian");
	do
	{
		cout<<"¬едите n-четное: ";
		cin>> n;
	}
	while(!(n%2==0));

	List *head, *tail;
	CreadeList(head,tail, n);
	cout<<"исходный список"<<endl;
	PrintList(head,tail);
	
	cout<<"полученный список "<<endl;
	Reorder(head,tail, n);
	

	system("pause");
	
}