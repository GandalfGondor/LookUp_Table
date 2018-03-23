class BitNode
{
	int data;
	BitNode *lchild, *rchilde;
};

int SearchBTS(BitNode *T,int key,BitNode *F,BitNode **P)
{
	if(!T)
	{
		*P = F;
		return 0;
	}
	else if(key == T->data)
	{
		*P = T;
		return 1;
	}
	else if(key<T->data)
	{
		SearchBTS(T->lchild,key,T,P);
	}
	else if(key>T->data)
	{
		SearchBTS(T->rchild,key,T,P);
	}
}

int InsertBST(BiTree *T, int key)
{
	BiTree p,s;
	if(!SearchBST(*T,key,NULL,&p))
	{
		s = new BiTree;
		s->lchild = NULL;
		s->rchild = NULL;
		if(!p)
			*T = s;
		else if(key < p->data)
			p->lchild = s;
		else 
			p->rchild = s;
		return true;

	}
	else 
		return false;
}

int DeleteBST(BiTree **T,int key)
{
	if(!**T)
		return 0;
	else
	{
		if(key == (*T)->data)
			return Delete(T);
		else if(key<(*T)->data)
			return DeleteBST(&(*T)->lchild,key);
		else 
			return DeleteBST(&(*T)->rchild,key);
	}
}

int Delete(BiTree **T)
{
	BiTree *q,*s;
	if(T->rchild = NULL)
	{
		q = *T;
		*T = (*T)->lchild;
		delete q;
	}
	else if((*T)->lchild == NULL)
	{
		q = *T;
		*T = (*T)->rchild;
		delete q;
	}
	else
	{
		q = *T;
		s = (*T)->lchild;
		while(s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if(q!=*T)
			q->rchild = s->lchild;
		else 
			q->lchild = s->lchild;
		delete s;
	}
	return 1;
}


