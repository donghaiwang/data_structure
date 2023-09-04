//�ļ���:exp9-5.cpp
#include <stdio.h>
#define MaxSize 100			//��������ϣ����
#define NULLKEY -1			//����չؼ���ֵ
typedef int KeyType;		//�ؼ�������
typedef char InfoType;		//������������
typedef struct
{
	KeyType key;			//�ؼ�����
	InfoType data;			//����������
	int count;				//̽�������
} HashTable;				//��ϣ��Ԫ������
void InsertHT(HashTable ha[],int &n,int m,int p,KeyType k)  //���ؼ���k���뵽��ϣ����
{
	int cnt,adr;
	adr=k % p;					//�����ϣ����ֵ
	if (ha[adr].key==NULLKEY)	//k����ֱ�ӷ��ڹ�ϣ����
	{
		ha[adr].key=k;
		ha[adr].count=1;
	}
	else						//������ͻʱ��������̽�ⷨ�����ͻ
	{
		cnt=1;					//cnt��¼k������ͻ�Ĵ���
		do 
		{
			adr=(adr+1) % m;	//����̽��
			cnt++;
		} while (ha[adr].key!=NULLKEY);
		ha[adr].key=k;			//��adr������k
		ha[adr].count=cnt;		//����̽�����
	}
	n++;						//�ܹؼ��ָ�����1
}
void CreateHT(HashTable ha[],int &n,int m,int p,KeyType keys[],int total)  //��keys��total���ؼ��ִ�����ϣ��
{
	for (int i=0;i<m;i++)				//��ϣ���ÿյĳ�ֵ
    {
        ha[i].key=NULLKEY;
	    ha[i].count=0;
    }
	n=0;
	for (int i=0;i<total;i++)
		InsertHT(ha,n,m,p,keys[i]);		//����n���ؼ���
}
int SearchHT(HashTable ha[],int m,int p,KeyType k)  //�ڹ�ϣ���в��ҹؼ���k
{
	int adr=k % p;					//�����ϣ����ֵ
	while (ha[adr].key!=NULLKEY && ha[adr].key!=k)
		adr=(adr+1) % m;		//����̽��
	if (ha[adr].key==k)			//���ҳɹ�
		return adr;
	else						//����ʧ��
		return -1;
}
bool DeleteHT(HashTable ha[],int &n,int m,int p,KeyType k)	//ɾ����ϣ���йؼ���k
{
	int adr;
	adr=k % p;					//�����ϣ����ֵ
	while (ha[adr].key!=NULLKEY && ha[adr].key!=k)
		adr=(adr+1) % m;		//����̽��
	if (ha[adr].key==k)			//���ҳɹ�
	{	
		int j=(adr+1)%m;
		while (ha[j].key!=NULLKEY && ha[j].key%p==k%p)	//����adrλ�ú����ͬ���
		{
			ha[(j-1+m)%m].key=ha[j].key;				//��ͬ���ǰ�ƶ� 
			j=(j+1)%m;									//������̽ѭ�����λ�� 
		}
		ha[(j-1+m)%m].key=NULLKEY;						//ɾ�����һ��ͬ���
		ha[(j-1+m)%m].count=0;
		n--;											//��ϣ����Ԫ�ظ�������1
		return true;									//���ҳɹ�����true 
	}
	else												//����ʧ�ܵ���� 
		return false;									//����false
}
void DispHT(HashTable ha[],int n,int m)    //�����ϣ��
{
	float avg=0;
	int i;
	printf("    ��ϣ���ַ:   ");
	for (i=0;i<m;i++) 
		printf("%-4d",i);
	printf(" \n");
    printf("    ��ϣ��ؼ���: ");
	for (i=0;i<m;i++) 
		if (ha[i].key==NULLKEY)
			printf("    ");			//���3���ո�
		else
			printf("%-4d",ha[i].key);
	printf("\n");
	printf("    ̽�����:     ");
	for (i=0;i<m;i++)
		if (ha[i].key==NULLKEY)
			printf("    ");			//���3���ո�
		else
			printf("%-4d",ha[i].count);
	printf(" \n");
    for (i=0;i<m;i++)
		if (ha[i].key!=NULLKEY)
			avg=avg+ha[i].count;
	avg=avg/n;
	printf("    ƽ�����ҳ���ASL(%d)=%g\n",n,avg);
}
int main()
{
	int a[]={16,74,60,43,54,90,46,31,29,88,77};
	int total=sizeof(a)/sizeof(a[0]);
	int n,m=13,p=13;
	int k=29;
	HashTable ha[MaxSize];
	printf("(1)������ϣ��\n");
	CreateHT(ha,n,m,p,a,total);
	printf("(2)�����ϣ��:\n"); DispHT(ha,n,m);
	printf("(3)���ҹؼ���Ϊ%d�ļ�¼λ��\n",k);
	int i=SearchHT(ha,m,p,k);
	if (i!=-1)
		printf("   ha[%d].key=%d\n",i,k);
	else
		printf("   ��ʾ:δ�ҵ�%d\n",k);
	k=77;
	printf("(4)ɾ���ؼ���%d\n",k);
	DeleteHT(ha,n,m,p,k);
	printf("(5)ɾ����Ĺ�ϣ��\n"); DispHT(ha,n,m);
	printf("n=%d\n",n);
	printf("(6)���ҹؼ���Ϊ%d�ļ�¼λ��\n",k);
	i=SearchHT(ha,m,p,k);
	if (i!=-1)
		printf("   ha[%d].key=%d\n",i,k);
	else
		printf("   ��ʾ:δ�ҵ�%d\n",k);
	printf("(7)����ؼ���%d\n",k);
	InsertHT(ha,n,m,p,k);
	printf("(8)�����Ĺ�ϣ��\n"); DispHT(ha,n,m);
	return 1;
}
