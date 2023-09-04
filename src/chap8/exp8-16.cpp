#include<stdio.h>
using namespace std;
#define MAXV 1010
#define INF 0x3f3f3f3f							//�����
int n,m;
int D[MAXV][MAXV],C[MAXV][MAXV];
int s,t;
void Dijkstra()								//�ҿ�˹�����㷨
{	int dist[MAXV];
	int cost[MAXV];
	int S[MAXV];
	int mindist,u;
	for(int i=1;i<=n;i++)							//dist��cost��S��ʼ��
	{	dist[i]=D[s][i];
		cost[i]=C[s][i];
		S[i]=0;
	}
	dist[s]=cost[s]=0;
	S[s]=1;
	for(int i=0;i<n-1;i++)
	{	mindist=INF;
		u=s;
		for(int j=1;j<=n;j++)						//����δ���ǵġ�������С�Ķ���u
		{	if (S[j]==0 && mindist>dist[j])
			{	mindist=dist[j];
				u=j;
			}
		}
		if (mindist==INF) break;					//�Ҳ�����ͨ�Ķ���
		S[u]=1;									//������u����S����
		for (int j=1;j<=n;j++)						//���Ƕ���u,��s��ÿ������j�����·�����Ⱥͻ���
		{	int d=mindist+D[u][j];				//d��¼��������u��·������
			int c=cost[u]+C[u][j];					//c��¼��������u�Ļ���
			if(S[j]==0 && d<dist[j])
			{	dist[j]=d;
				cost[j]=c;
			}
			else if(S[j]==0 && d==dist[j] && c<cost[j])
				cost[j]=c;						//�ж���������ͬ�����·��ʱ����С����
		}
		if(S[t]==1)								//�Ѿ����s��t�����·��
		{	printf("  ��̾���Ϊ%d������Ϊ%d\n",dist[t],cost[t]);
			return;
		}
	}
}
int main()
{
	freopen("data16.txt","r",stdin);	//�����ض��� 
	int a,b,d,p;
	printf("��������\n"); 
	scanf("%d%d",&n,&m); 
	printf("  n=%d,m=%d\n",n,m);
	for(int i=1;i<=n;i++)
	{	for(int j=1;j<=n;j++)
		{	D[i][j]=INF;
			C[i][j]=INF;
		}
	}
	int cnt=0;
	for(int i=0;i<m;i++)
	{	scanf("%d%d%d%d\n",&a,&b,&d,&p);
		printf("  ��%d����: (%d,%d),����:%d,����%d\n",++cnt,a,b,d,p); 
		if(D[a][b]>d)
		{	D[a][b]=D[b][a]=d;				//����ͼ�ı��ǶԳƵ�
			C[a][b]=C[b][a]=p;
		}
	}
	scanf("%d%d",&s,&t);
	printf("  ���:%d  �յ�:%d\n",s,t); 
	printf("�����\n"); 
	Dijkstra();
	return 0;
}

