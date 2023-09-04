#include <stdio.h>
#include<string.h>
#define N 8
int grid[N][N];	
int dx[8]={-2,-1,1,2,2,1,-1,-2};			//x�����ƫ���� 
int dy[8]={1,2,2,1,-1,-2,-2,-1};			//y�����ƫ����
bool DFS(int i,int j,int step)			//��(i,j)���ӿ�ʼ���� 
{
	if(step>=N*N) return true;
	int exists[8]={0};						//��¼ÿ����λ���ڵĳ�·��
	int nexti[8]={0};						//��¼ÿ����λ���ڵĸ��� 
	int nextj[8]={0};
	int ni,nj;
	int count, mindi;
	for(int di=0;di<8;di++)					//��ʼ��ÿ����λ���ڵĳ�·��Ϊ0 
		exists[di]=0;
	int total=0;							//(i,j)���ӵĳ�����Ϊtotal����ʼΪ0 
	for(int di=0;di<8;di++)					//��̽(i,j)���ӵ�8����λ
	{
		ni=i+dx[di];						//di��λ�����ڸ�����(ni,nj) 
		nj=j+dy[di];
		if(ni<0 || nj<0 || ni>=N || nj>=N) 
			continue;						//����Ǳ߽��򲻿���
		if(grid[ni][nj]==0)					//��������λ���ߣ���¼����
		{	nexti[total]=ni;				//(ni,nj)��(i,j)�ĵ�total�����ڿ��߸���
			nextj[total]=nj;
			total++;						//(i,j)���ӵĳ�������1
		}
	}
	if(total==0)							//���������Ϊ0�򷵻�
		return false;
	else if(total==1)						//���ֻ��һ�����ڣ�mindi��ʾ�ó���
		mindi=0;
	else
	{	
		for(int c=0;c<total;c++)			//��ÿ�����ڵĳ�����
			for(int di=0;di<8;di++)			//��̽ÿ����λ�����ڸ��� 
			{
				ni=nexti[c]+dx[di];
				nj=nextj[c]+dy[di];
				if(ni<0 || nj<0 || ni>=N || nj>=N)
					continue;
				if(grid[ni][nj]==0)			//(ni,nj)�����ǿ��ߵ� 
					exists[c]++;
			}
		int tmp=exists[0];
		mindi=0;
		for(int c=1;c<total;c++)		//�ڶ������������С�������ĳ���mindi
			if(exists[c]<tmp)
			{
				tmp=exists[c];
				mindi=c;
			}
	}
	grid[nexti[mindi]][nextj[mindi]]=step+1;
	if (DFS(nexti[mindi],nextj[mindi],step+1))
		return true;
	else
		return false;
}
int main(void)
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
	grid[sx][sy]=1;							//(sx,sy)�����ǵ�1�� 
	if(DFS(sx, sy,1))
	{
		printf("��(%d,%d)������������ɣ���������:\n",sx,sy);
		for(int i=0;i<N;i++)
		{ 
			for(int j=0;j<N;j++)
				printf("  %2d", grid[i][j]);
			printf("\n");
		}
	}
	else
		printf("����ʧ�ܣ�\n");
	return 1;
}

