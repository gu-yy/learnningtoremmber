#include <iostream>
/**
 * cout<<"======================================================\n";
        cout<<"1:InitBitTree                2:DestroyBitTree\n";
        cout<<"3:CreateBitTree              4:ClearBitTree\n";
        cout<<"5:BitTreeEmpty               6:BitTreeDepth\n";
        cout<<"7:Root                       8:Value\n";
        cout<<"9:Assign                     10:Parent\n";
        cout<<"11:LeftChild                 12:RightChild\n";
        cout<<"13:LeftSibling               14:RightSibling\n";
        cout<<"15:InsertChild               16:DeleteChild\n";
        cout<<"17:PreOrderTraverse          18:InOrderTraverse\n";
        cout<<"19:PosetOrderTraverse        20:LevelOrderTraverse\n";
        cout<<"======================================================\n";
 */
typedef struct BitTree{
    int elem=0;
    struct BitTree *lchild=NULL,*rchild=NULL;
}BitTree,*bitTree;
extern int emptyFlag;
int InitBitTree(bitTree &T);
void DestroyBitTree(bitTree &T);
int insertNode(bitTree &T,int index,int value);
int ClearBitTree(bitTree &T);
int BitTreeEmpty(bitTree T);
int BitTreeDepth(bitTree T);
int Root(bitTree T,int &e);
int Value(bitTree T,int index,int &e);
int Assign(bitTree &T,int index,int value);
bitTree Parent(bitTree T,int index);
bitTree LeftChild(bitTree T,int index);
bitTree RightChild(bitTree T,int index);
bitTree LeftSibling(bitTree T,int index);
bitTree RightSibling(bitTree T,int index);
int InsertChild(bitTree &T,int index,int LR,bitTree C);
int DeleteChild(bitTree &T,int index,int LR);
void PreOrderTraverse(bitTree T);
void InOrderTraverse(bitTree T);
void PostOrderTraverse(bitTree T);
void LevelOrderTraverse(bitTree T);
int Depth(bitTree T);
int findNode(bitTree T,bitTree &curNode,bitTree &parNode,int index);