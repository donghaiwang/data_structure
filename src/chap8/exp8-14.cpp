#include <iostream>
#include <cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXV 105 
int mat[MAXV][MAXV];
int U[MAXV];
int lowcost[MAXV];
int n;

int Prim()									//�ⷨ1��Prim�㷨�󶥵�1��������С��������Ȩֵ��
{	memset(U,0,sizeof(U));
	memset(lowcost,0x3f,sizeof(lowcost));
	int ans=0;								//��Ž��
	lowcost[1]=0;
	for(int i=1;i<=n;i++)
	{	int minc=INF,k=0;
		for(int j=1;j<=n;j++)					//��(V-U)���ҳ���U����Ķ���k
			if(!U[j] && lowcost[j]<minc)
			{	minc=lowcost[j];
				k=j;
			}
		ans+=minc;							//�ۼ���С�������ı�Ȩ
		U[k]=1;								//���k�Ѿ�����U
		for(int i=1;i<=n;i++)					//����
			if(U[i]==0 && lowcost[i]>mat[k][i])
				lowcost[i]=mat[k][i];
	}
	return ans;
}
//----���鼯���������㷨 
int parent[MAXV];							//���鼯�洢�ṹ
int rnk[MAXV];								//�洢������
void Init(int n)								//���鼯��ʼ��
{	for (int i=1;i<=n;i++)						//������1��n 
	{	parent[i]=i;
		rnk[i]=0;
	}
}
int Find(int x)								//���鼯�в���x���ĸ����
{	if (x!=parent[x])
		parent[x]=Find(parent[x]);			//·��ѹ��
	return parent[x];
}
void Union(int x,int y)						//���鼯��x��y���������ϵĺϲ�
{	int rx=Find(x);
	int ry=Find(y);
	if (rx==ry)								//x��y����ͬһ���������
		return;
	if (rnk[rx]<rnk[ry])
		parent[rx]=ry;						//rx�����Ϊry�ĺ��� 
	else
	{	if (rnk[rx]==rnk[ry])					//����ͬ���ϲ���rx������1
			rnk[rx]++;
		parent[ry]=rx;						//ry�����Ϊrx�ĺ���
	}
}
struct Edge								//������Ԫ������
{	int u;									//�ߵ���ʼ����
	int v;									//�ߵ���ֹ����
	int w;									//�ߵ�Ȩֵ
	Edge(int u,int v,int w)					//���캯��
	{	this->u=u;
		this->v=v;
		this->w=w;
	}
	bool operator<(const Edge &s) const		//����<�����
	{
		return w<s.w;						//���ڰ�w��������
	}
};
int Kruskal()								//�ⷨ2���Ľ���Kruskal�㷨����С��������Ȩֵ��
{	int ans=0;
	vector<Edge> E;							//����������бߵ�����E
	for (int i=1;i<=n;i++)						//��ͼ���ڽӾ���g����������E
		for (int j=1;j<=n;j++)
			if (i<j)
				E.push_back(Edge(i,j,mat[i][j]));
	sort(E.begin(),E.end());					//��E��Ȩֵ��������
	Init(n);									//���鼯��ʼ��
	int k=1;									//k��ʾ��ǰ�����������ĵڼ�����,��ֵΪ1
	int j=0;									//E�бߵ��±�,��ֵΪ0
	while (k<n)								//���ɵı���С��nʱѭ��
	{	int u1=E[j].u;
		int v1=E[j].v;						//ȡһ���ߵ���ʼ����ֹ����
		int sn1=Find(u1);
		int sn2=Find(v1);					//�ֱ�õ��������������ļ��ϱ��
		if (sn1!=sn2)							//���������ڲ�ͬ�ļ���,�ñ�����С��������һ����
		{	ans+=E[j].w;					//�ۼ���С�������ı�Ȩ
			k++;							//���ɱ�����1
			Union(sn1,sn2);					//�ϲ�
		}
		j++;									//ɨ����һ����
	}
	return ans;
}
int main()
{
	freopen("data14.txt","r",stdin);	//�����ض��� 
	scanf("%d",&n);
	printf("��ׯn=%d\n",n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&mat[i][j]);
	printf("�ڽӾ���\n"); 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%4d ",mat[i][j]);
		printf("\n");
	}
	int k;
	scanf("%d",&k);
	printf("�Ѿ���������%d����·\n",k);
	for(int i=0;i<k;i++)
	{	int a,b;
		scanf("%d%d",&a,&b);
		printf("  (%d,%d)\n",a,b);
		mat[a][b]=mat[b][a]=0;
	}
	printf("�����\n"); 
	printf("  �ⷨ1: %d\n",Prim());
	printf("  �ⷨ2: %d\n",Kruskal());
	return 0;
}

