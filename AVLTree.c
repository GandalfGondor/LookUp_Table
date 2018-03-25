#include<iostream>
#include<queue>
using namespace std;

#define LH 1
#define EH 0
#define RH -1

class BitNode
{
public:
	int data;
	int bf;
	BitNode *lchild,*rchild;
};

void R_rotate(BitNode **p)
{
	BitNode *L;
	L = (*p)->lchild;
	(*p)->lchild = L->rchild;
	L->rchild = *p;
	*p = L;
}
void L_rotate(BitNode **p)
{
	BitNode *L;
	L = (*p)->rchild;
	(*p)->rchild = L->lchild;
	L->lchild = *p;
	*p = L;
}

void LeftBalance(BitNode **T)
{
	BitNode *L;
	BitNode *Lr;
	L = (*T)->lchild;
	switch(L->bf)
	{
		case LH:
			(*T)->bf = EH;
			L->bf = EH;
			R_rotate(T);
			break;
		case RH:
			Lr = L->rchild;
			switch(Lr->bf)
			{
				case LH:
					(*T)->bf = RH;
					L->bf = EH;
					break;
				case EH:
					(*T)->bf = EH;
					L->bf = EH;
					break;
				case RH:
					(*T)->bf = EH;
					L->bf = LH;
					break;
			}
			Lr->bf = EH;
			L_rotate(&(*T)->lchild);
			R_rotate(T);
	}
}
void RightBalance(BitNode **T)
{
	BitNode* R;
	BitNode* Rl;
	R = (*T)->rchild;
	switch(R->bf)
	{
		case RH:
			(*T)->bf = EH;
			R->bf = EH;
			L_rotate(T);
			break;
		case LH:
			Rl = R->lchild;
			switch(Rl->bf)
			{
				case LH:
					(*T)->bf = EH;
	
				R->bf = RH;
					break;
				case EH:
					(*T)->bf = EH;
					R->bf = EH;
					break;
				case RH:
					(*T)->bf = LH;
					R->bf = EH;
			}
			R_rotate(&(*T)->rchild);
			L_rotate(T);
	}
	
}

int  InsertAVL(BitNode** T,int e,int *taller)
{
	if(!(*T))
	{
		*T = new BitNode;
		(*T)->data = e;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = 1;
	}
	else
	{
		if(e==(*T)->data)
		{
			*taller = 0;
			return 0;
		}
		if(e<(*T)->data)
		{
			if(!InsertAVL(&(*T)->lchild,e,taller))
				return 0;
			if(*taller)
			{
				switch((*T)->bf)
				{
					case LH:
						LeftBalance(T);
						*taller = 0;
						break;
					case EH:
						(*T)->bf = LH;
						*taller = 1;
						break;
					case RH:
						(*T)->bf = EH;
						*taller = 0;
						break;
				}
			}
		}
		else
		{
			if(!InsertAVL(&(*T)->rchild,e,taller))
				return 0;
			if(*taller)
			{
				switch((*T)->bf)
				{
					case LH:
						(*T)->bf = EH;
						*taller = 0;
						break;
					case EH:
						(*T)->bf = RH;
						*taller = 1;
						break;
					case RH:
						RightBalance(T);
						*taller = 0;
						break;
				}
			}
		}
	}
	return 1;
}

int main()
{
	int i;
	int insert[10] = {1,2,3,4,5,6,7,8,9,10};
	BitNode **T;
	*T = NULL;
	int taller=0;
	for(i=0;i<10;i++)
	{
		InsertAVL(T,insert[i],&taller);	
	}	
	queue<BitNode*> q;
	q.push(*T);
	cout<<"BitTree is (level traversal) :"<<endl;
	while(!q.empty())
	{
		BitNode *temp = q.front();
		cout<<temp->data<<" ";
		q.pop();
		if(temp->lchild != NULL)
			q.push(temp->lchild);
		if(temp->rchild != NULL)
			q.push(temp->rchild);
	
	}
	cout<<"traverse is over!"<<endl;
	return 1;
}
