# LookUp_Table
    AVLTree.c文件主要内容:
    向平衡二叉树进行插入操作，其中包括对二叉树的平衡性进行判断，对二叉树进行平衡，旋转等操作。对于指针的使用也是一个难点，需要充分理解函数参数是指针
时的意义。
例：
void Rotate(BitNode **p)
{
  BitNode *L;
  L = (*p)->lchild;
  (*p)->lchild = L->rchild;
  L->rchild = *p;
  *p = L;
}
p表示一个指针，它的内容是指向BitNode型指针的地址。这里保证指向BitNode型根节点的地址产生变化，但是指向该地址的指针不能发生变化，所以必须用双重指针。
