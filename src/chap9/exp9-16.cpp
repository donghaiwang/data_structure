//�ļ���:exp9-16.cpp
#include<stdio.h>
#define MaxSize 1005
int ht[MaxSize];				//��ϣ��
int a[MaxSize]; 
int n;
//-----��ϣ������㷨��ʼ-------
void insertht(int x,int no)		//��<x,no>���뵽��ϣ��ht�� 
{
	ht[x]=no;
}
void deleteht(int x)			//�ӹ�ϣ��ht��ɾ��<x,*> 
{
	ht[x]=-1;
}
//-----��ϣ������㷨����-------
void dispa()					//������� 
{
	printf("a: ");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void inserta(int x)				//����x 
{
	a[n]=x;						//��a��ĩβ���x 
	insertht(x,n); 				//��<x,n>���뵽��ϣ��ht�� 
	n++;	
}
void deletea(int x)				//ɾ��x
{
	int no=ht[x];				//������x�����no 
	deleteht(x);				//�ӹ�ϣ��ht��ɾ��x
	a[no]=a[n-1];				//��z��ĩβԪ���Ƶ�noλ��
	deleteht(a[n-1]); 			//�ӹ�ϣ��ht��ɾ��a[n-1]
	insertht(a[n-1],no); 		//��<a[n-1],no>���²��뵽��ϣ��ht�� 
	n--;
}
int search(int no)				//�������Ϊno������
{
	return a[no-1];
}
int main()
{
	int op[]={1,5,1,4,1,3,2,4,1,7,1,6,3,2,2,5,3,1,3,2};
	int m=sizeof(op)/sizeof(op[0]);		//��������Ϊm/2 
	for(int i=0;i<MaxSize;i++)		//��ʼ����ϣ��ht 
		ht[i]=-1;
	n=0;
	for(int i=0;i<m;i+=2)
	{
		switch(op[i])
		{
			case 1:					//������� 
				printf("����%d\t\t",op[i+1]); 
				inserta(op[i+1]);
				dispa();
				break;
			case 2:					//ɾ������	
				printf("ɾ��%d\t\t",op[i+1]); 
				deletea(op[i+1]);
				dispa();
				break;
			case 3:					//����ǰ��Ų��� 
				printf("���%d������: %d\n",op[i+1],search(op[i+1])); 
				break;
		}
	}		
	return 1;
}
