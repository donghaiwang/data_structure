#include <stdio.h>
#include<string.h>
#define N 8
int grid[N][N];	
int dx[]={-2,-1,1,2,2,1,-1,-2};			//x�����ƫ���� 
int dy[]={1,2,2,1,-1,-2,-2,-1};			//y�����ƫ����
bool DFS(int i,int j,int x,int y,int step)	//����(i,j)->(x,y)��·�� 
{
	int ni,nj;
	if(i==x && j==y)						//�ҵ�һ��·�� 
		return true;
	for(int di=0;di<8;di++)
	{
		ni=i+dx[di];						//di��λ�����ڸ�����(ni,nj) 
		nj=j+dy[di];
		if(ni<0 || nj<0 || ni>=N || nj>=N) 
			continue;						//����Ǳ߽��򲻿���
		if(grid[ni][nj]==0)					//��������λ����
		{
			grid[ni][nj]=step+1;			//��(i,j)�ߵ�(ni,nj) 
			if (DFS(ni,nj,x,y,step+1))			//�ݹ����
				return true; 
			grid[ni][nj]=0;					//��(ni,nj)���� 
		}
	}
	return false;
}
int main()
{
	int sx,sy,tx,ty;
	memset(grid,0,sizeof(grid));			//��ʼʱgrid����Ԫ��Ϊ0 
	printf("������ʼ�㣺");
	scanf("%d %d", &sx, &sy);
	if(sx<0 || sx>=N || sy<0 || sy>=N)
	{
		printf("  ��ʼλ�ô���!\n");
		return 0;
	}
	printf("������ֹ�㣺");
	scanf("%d %d", &tx, &ty);
	if(tx<0 || tx>=N || ty<0 || ty>=N)
	{
		printf("  ��ֹλ�ô���!\n");
		return 0;
	}
	printf("\n��(%d,%d)->(%d,%d)��·��\n",sx,sy,tx,ty);
	grid[sx][sy]=1;							//(sx,sy)�����ǵ�1�� 
	if (DFS(sx,sy,tx,ty,1))
	{	printf("�ҵ�һ��·������\n"); 
		for(int i=0;i<N;i++)
		{ 
			for(int j=0;j<N;j++)
				printf("  %2d", grid[i][j]);
			printf("\n");
		}
	}
	else
		printf("û���ҵ�������·��\n");
	return 1;
}
