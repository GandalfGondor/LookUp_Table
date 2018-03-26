#include<iostream>

#define SUCCESS 1
#define UNSUCCESS -1
#define HASHSIZE 12
#define NULLKEY -32768

int m;

class HashTable
{
public:
	int* elem;
	int count;
};

void InitHashTable(HashTable *H)
{
	int i;
	m = HASHSIZE;
	H->count = m;
	H->elem = new int;
	for(i=0;i<m;i++)
		H->elem[i]=NULLKEY;
	return 1;
}

int Hash(int key)
{
	return key%m;
}

void InsertHash(HashTable *H,int key)
{
	int addr = Hash(key);
	while(H->elem[addr]!=NULLKEY)
		addr =(addr +1)%m;
	H->elem[addr] = key;
}

int search(HashTable *H,int key,int *addr)
{
	*addr = Hash(key);
	while(H.elem[*addr]!=key)
	{
		*addr = (*addr+1)%m;
		if(H.elem[*addr] == NULLKEY)
		{
			return UNSUCCESS;
		}
	}
	return SUCCESS;
}
