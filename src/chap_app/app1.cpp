#include <stdio.h>
#include<string.h>
#define N 5
int grid[N][N];	
int dx[]={-2,-1,1,2,2,1,-1,-2};			//x�����ƫ���� 
int dy[]={1,2,2,1,-1,-2,-2,-1};			//y�����ƫ����
int cnt=0;
void DFS(int i,int j,int step)			//��(i,j)���ӿ�ʼ���� 
{
	int ni,nj;
	if(step>=N*N)						//�ҵ�һ��·�� 
	{	cnt++;
		if(cnt<=3)
		{	printf("��%d����\n",cnt); 
			for(int i=0;i<N;i++)
			{ 
				for(int j=0;j<N;j++)
					printf("  %2d", grid[i][j]);
				printf("\n");
			}
		}
		return;
	}
	for(int di=0;di<8;di++)
	{
		ni=i+dx[di];						//di��λ�����ڸ�����(ni,nj) 
		nj=j+dy[di];
		if(ni<0 || nj<0 || ni>=N || nj>=N) 
			continue;						//����Ǳ߽��򲻿���
		if(grid[ni][nj]==0)					//��������λ����
		{
			grid[ni][nj]=step+1;			//��(i,j)�ߵ�(ni,nj) 
			DFS(ni,nj,step+1);				//�ݹ���ã���������ȥ 
			grid[ni][nj]=0;					//��(ni,nj)���� 
		}
	}
}
int main()
{
	int sx, sy;
	memset(grid,0,sizeof(grid));			//��ʼʱgrid����Ԫ��Ϊ0 
	printf("������ʼ�㣺");
	scanf("%d %d", &sx, &sy);
	if(sx<0 || sx>=N || sy<0 || sy>=N)
	{
		printf("  ��ʼλ�ô���!\n");
		return 0;
	}
	printf("\n��(%d,%d)����������\n",sx,sy);
	grid[sx][sy]=1;							//(sx,sy)�����ǵ�1�� 
	DFS(sx, sy,1);
	printf(".\n\.\n");
	printf("��%d����\n",cnt); 
	return 1;
}

