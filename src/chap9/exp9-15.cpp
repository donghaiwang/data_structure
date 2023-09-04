//�ļ���:exp9-15.cpp
//AVL�㷨
#include <stdio.h>
#include <malloc.h>
#define max(x,y) ((x)>(y)?(x):(y))
typedef struct node 
{	
	int key;                  		//�ؼ�����
	int ht;                       		//��ǰ���������߶�
    struct node *lchild,*rchild;		//���Һ���ָ��
} AVLNode;								//AVL���������
void DestroyAVL(AVLNode* r)				//�ͷ����еĽ��ռ�
{
	if (r!=NULL)
	{
		DestroyAVL(r->lchild);			//�ݹ��ͷ�������
		DestroyAVL(r->rchild);			//�ݹ��ͷ�������
		delete r;						//�ͷŸ����
	}
}
int getht(AVLNode* p)                 	//���ؽ��p�������߶�
{	if (p==NULL)
		return 0;
    return p->ht;
 }
AVLNode* right_rotate(AVLNode* A) 			//�Խ��AΪ��������ת
{	AVLNode* B=A->lchild;
	A->lchild=B->rchild;
	B->rchild=A;
	A->ht=max(getht(A->rchild),getht(A->lchild))+1;
	B->ht=max(getht(B->rchild),getht(B->lchild))+1;
	return B;
}
AVLNode* left_rotate(AVLNode* A)            //�Խ��AΪ��������ת
{	AVLNode* B=A->rchild;
	A->rchild=B->lchild;
	B->lchild=A;
	A->ht=max(getht(A->rchild),getht(A->lchild))+1;
	B->ht=max(getht(B->rchild),getht(B->lchild))+1;
	return B;
}
AVLNode* LL(AVLNode* A)                    	//LL�͵���
{
	return right_rotate(A);
}
AVLNode* RR(AVLNode* A)                     //RR�͵���
{
	return left_rotate(A);
}
AVLNode* LR(AVLNode* A)                     //LR�͵���
{	AVLNode* B=A->lchild;
	A->lchild=left_rotate(B);    			//���b����
	return right_rotate(A);     			//���a����
}
AVLNode* RL(AVLNode* A)                     //RL�͵���
{	AVLNode* B=A->rchild;
	A->rchild=right_rotate(B);   			//���b����
	return left_rotate(A);     				 //���a����
}
AVLNode* InsertAVL(AVLNode* r,int k)			//��AVL��r�в���ؼ���k 
{	if (r==NULL)                             		//����ʱ���������
	{   AVLNode* p=(AVLNode*)malloc(sizeof(AVLNode));
		p->key=k; p->ht=1;
		p->lchild=p->rchild=NULL;
        return p;
    }
	else if (k==r->key)								//�ҵ��ظ��ؼ���ʱ����			
         return r;
	else if (k<r->key)                           	//k<r->key�����
	{	r->lchild=InsertAVL(r->lchild,k);		 	//��k���뵽r����������
        if (getht(r->lchild)-getht(r->rchild)>=2)	//�ҵ�ʧ����r
        {	if (k<r->lchild->key)             		//k������r�����ӵ���������
                r=LL(r);               				//����LL�͵���
            else                           			//k������r�����ӵ���������
                r=LR(r);                			//����LR�͵���
        }
	}
	else                                   			//k>r->key�����
	{	r->rchild=InsertAVL(r->rchild,k);		 	//��k���뵽r����������
        if (getht(r->rchild)-getht(r->lchild)>=2)   //�ҵ�ʧ����r
        {	if (k>r->rchild->key)              		//k������r���Һ��ӵ���������
                r=RR(r);                			//����RR�͵���
            else                           			//k������r���Һ��ӵ���������
                r=RL(r);                			//����RL�͵���
        }
    }
    r->ht=max(getht(r->lchild),getht(r->rchild))+1;   //���½��r�ĸ߶�
	return r;
}
AVLNode* Deletemin(AVLNode* r,int &mine)		//ɾ��AVL��r�е���С��� 
{
	AVLNode *f=NULL,*p=r;
	while(p->lchild!=NULL)						//�Ҹ����r�������½��p
	{
		f=p;
		p=p->lchild;
	}
	if(f==NULL)									//���p�Ǹ����
		r=r->rchild;
	else										//���p���Ǹ����
		f->lchild=p->rchild;
	mine=p->key;
	free(p);
	return r;
}
AVLNode* Deletemax(AVLNode* r,int &maxe)			//ɾ��AVL��r�е������ 
{
	AVLNode *f=NULL,*p=r;
	while(p->rchild!=NULL)						//�Ҹ����r�������½��p
	{
		f=p;
		p=p->rchild;
	}
	if(f==NULL)									//���p�Ǹ����
		r=r->lchild;
	else										//���p���Ǹ����
		f->rchild=p->lchild;
	maxe=p->key;
	free(p);
	return r;
}
void inorder(AVLNode* r)                    //����������н��ֵ 
{
    if (r!=NULL)
    {	inorder(r->lchild);
        printf("%d ",r->key);
        inorder(r->rchild);
    }
}
void solve(int a[],int n)
{
	AVLNode *b=NULL;
	int mine,maxe;
	for(int i=0;i<n;i++)
	{
		if(a[i]==-1)						//ɾ����С����
		{
			b=Deletemin(b,mine);
			printf("ɾ����СԪ��%2d  ",mine);
			printf("����: "); inorder(b); printf("\n");
		}			 
		else if (a[i]==-2)					//ɾ���������
		{
			b=Deletemax(b,maxe); 
			printf("ɾ�����Ԫ��%2d  ",maxe);
			printf("����: "); inorder(b); printf("\n");
		}
		else								//����һ������ 
		{
			b=InsertAVL(b,a[i]);
			printf("����%d\t\t",a[i]);
			printf("����: "); inorder(b); printf("\n");
		}
	} 
	DestroyAVL(b);
}
int main()
{
	int a[]={3,5,-1,6,1,2,8,-2,-2,4};
	int n=sizeof(a)/sizeof(a[0]);
	solve(a,n);
	return 1;
}
