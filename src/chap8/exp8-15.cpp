//ʵ����15
//�ļ�:exp8-15.cpp 
#include <stdio.h>
#define MAXV 105
#define INF 0x3f3f3f3f
int N,M;
void Dijkstra(int g[MAXV][MAXV],int v,int dist[MAXV])	//Dijkstra�㷨
{
	int S[MAXV];					//S[i]=1��ʾ����i��S��, S[i]=0��ʾ����i��U��
	int mindist,i,j,u;
	for (i=1;i<=N;i++)
	{	dist[i]=g[v][i];			//�����ʼ��
		S[i]=0;						//S[]�ÿ�
	}
	S[v]=1;							//Դ����v����S��
	for (i=1;i<N;i++)				//ѭ��ֱ�����ж�������·�������
	{	mindist=INF;				//mindist����󳤶ȳ�ֵ
		for (j=1;j<=N;j++)			//ѡȡ����S�У���U�У�����С����Ķ���u
			if (S[j]==0 && dist[j]<mindist) 
			{	u=j;
				mindist=dist[j];
			}
		S[u]=1;						//����u����S��
		for (j=1;j<=N;j++)			//�޸Ĳ���S�У���U�У��Ķ�������·��
		{
			if (S[j]==0)
				if (g[u][j]<INF && dist[u]+g[u][j]<dist[j])
					dist[j]=dist[u]+g[u][j];
		}
	}
}
int solve()								//����㷨 
{
	freopen("data15.txt","r",stdin);	//�����ض��� 
	int A[MAXV][MAXV];					//�����ڽӾ���
	int B[MAXV][MAXV];					//�����ڽӾ���
	int dist1[MAXV],dist2[MAXV];
	int a,b,c;
	scanf("%d%d",&N,&M);
	printf("N=%d,M=%d\n",N,M);
	for (int i=1;i<=N;i++)				//��ʼ���ڽӾ��� 
		for(int j=1;j<=N;j++)
		{
			if(i==j)
				A[i][j]=A[i][j]=0;
			else
				A[i][j]=B[i][j]=INF;
		}
	for(int i=0;i<M;i++)
	{	scanf("%d%d%d",&a,&b,&c);		//����һ����<a,b>:c 
		printf("<%d,%d>:%d\n",a,b,c);
		A[a][b]=B[b][a]=c;
	}
	Dijkstra(A,1,dist1);
	printf("���dist1:  [");
	for(int i=2;i<=N;i++)
		printf("%4d",dist1[i]);
	printf("]\n");
	Dijkstra(B,1,dist2);
	printf("���dist2:  [");
	for(int i=2;i<=N;i++)
		printf("%4d",dist2[i]);
	printf("]\n");
	int ans=0;
	for(int i=1;i<=N;i++)
		ans+=(dist1[i]+dist2[i]);
	return ans;
}

int main()
{
	printf("ans=%d\n",solve());
	return 0;
}

