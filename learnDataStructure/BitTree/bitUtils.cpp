#include <iostream>
#include <stack>
#include <queue>
#include <math.h>
#include "bitUtils.h"
using namespace std;

int emptyFlag=0;
int InitBitTree(bitTree &T){
    if(T){
        cout<<"the binary tree is existed\n";
        return 0;
    }
    T=new BitTree();
    T->elem=0;
    T->lchild=NULL;
    T->rchild=NULL;
    emptyFlag=0;
    if(T){
        return 1;
    }
}
void DestroyBitTree(bitTree &T){
    if(T){
        if(T->lchild){
            DestroyBitTree(T->lchild);
        }
        if(T->rchild){
            DestroyBitTree(T->rchild);
        }
        delete T;
        T=NULL;
    }
}
int ClearBitTree(bitTree &T){
    if(!T){
        cout<<"the bianry tree is not exist\n";
        return 0;
    }
    else{
        if(T->lchild){
            DestroyBitTree(T->lchild);
        }
        if (T->rchild){
            DestroyBitTree(T->rchild);
        }
        T->elem=0;
        emptyFlag=0;
        return 1;
    }
}
int insertNode(bitTree &T,int index,int value){
    int tmpIndex=0;
    bitTree curNode,parNode;
    if(!T){
        cout<<"the bianry tree is not exist\n";
        return 0;
    }
    tmpIndex=index/2;
    if(index==1){//插入根节点
        T->elem=value;
        emptyFlag=1;
        return 1;
    }
    /*
    if(pow(2,Depth(T))-1<index){
        cout<<"the parent node is not exist\n";
        return 0;
    }
    */
    if(findNode(T,curNode,parNode,tmpIndex)){
        if(index%2==0){
            //左孩子
            if(curNode->lchild){
                cout<<"the node which will be inserted is exist\n";
                return 0;
            }
            else{
                curNode->lchild=new BitTree();
                curNode->lchild->elem=value;
                emptyFlag=1;
                return 1;
            }
        }
        else{
            //右孩子
            if(curNode->rchild){
                cout<<"the node which will be inserted is exist\n";
                return 0;
            }
            else{
                curNode->rchild=new BitTree();
                curNode->rchild->elem=value;
                emptyFlag=1;
                return 1;
            }
        }
    }
}
int BitTreeEmpty(bitTree T){
    if(!T){
        cout<<"the bianry tree is not exist\n";
        return 0;
    }
    else{
        if(!emptyFlag){
            return 1;
        }
        else{
            return -1;
        }
    }
}
int BitTreeDepth(bitTree T){
    if(!T){
        cout<<"the bianry tree is not exist\n";
        return -1;
    }
    else{
        if(!emptyFlag){
            return 0;
        }
        //二叉树的深度为左子树和右子树中较深的那一棵的深度，再加上父节点，也就是深度加1
        else{
            return Depth(T);
        }
    }
}
int Root(bitTree T,int &e){
    int flag=0;
    if(!T){
        cout<<"the bianry tree is not exist\n";
    }
    else{
        if(!emptyFlag){
            cout<<"the binary tree is empty\n";
        }
        else{
            e=T->elem;
            flag=1;
        }
    }
    return flag;
}
int Value(bitTree T,int index,int &e){
    int flag=0;
    bitTree curNode,parNode;
    if(!T){
        cout<<"the bianry tree is not exist\n";
    }
    else{
        if(!emptyFlag){
            cout<<"the binary tree is empty\n";
        }
        else{
            if(pow(2,Depth(T))-1<index){
                cout<<"the wrong index overflow the size of the binary tree\n";
            }
            else{
                if(findNode(T,curNode,parNode,index)){
                    flag=1;
                    e=curNode->elem;
                }
            }
        }
    }
    return flag;
}
int Assign(bitTree &T,int index,int value){
    int flag=0;
    bitTree curNode,parNode;
    if(!T){
        cout<<"the bianry tree is not exist\n";
    }
    else{
        if(!emptyFlag){
            cout<<"the binary tree is empty\n";
        }
        else{
            if(pow(2,Depth(T))-1<index){
                cout<<"the wrong index overflow the size of the binary tree\n";
            }
            else{
                if(findNode(T,curNode,parNode,index)){
                    flag=1;
                    curNode->elem=value;
                }
            }
        }
    }
    return flag;
}
bitTree Parent(bitTree T,int index){
    bitTree curNode,parNode;
    if(!T){
        cout<<"the bianry tree is not exist\n";
    }
    else{
        if(!emptyFlag){
            cout<<"the binary tree is empty\n";
        }
        else{
            if (index==1){
                cout<<"the root node don't have a parent node\n";
                return NULL;
            }
            else{
                if(pow(2,Depth(T))-1<index){
                    cout<<"the wrong index\n";
                    return NULL;
                }
                else{
                    if (findNode(T,curNode,parNode,index)){
                        return parNode;
                    }
                    else{
                        return NULL;
                    }
                }
            }
        }
    }
    return NULL;
}

bitTree LeftChild(bitTree T,int index){
    bitTree curNode,parNode;
    if(!T){
        cout<<"the bianry tree is not exist\n";
    }
    else{
        if(!emptyFlag){
            cout<<"the binary tree is empty\n";
        }
        else{
            if(pow(2,Depth(T))-1<index){
                    cout<<"the wrong index\n";
                    return NULL;
                }
                else{
                    if(findNode(T,curNode,parNode,index)){
                        if(curNode->lchild){
                            return curNode->lchild;
                        }
                        else{
                            return NULL;
                        }
                    }
                    else{
                        return NULL;
                    }
                }
        }
    }
    return NULL;
}

bitTree RightChild(bitTree T,int index){
    bitTree curNode,parNode;
    if(!T){
        cout<<"the bianry tree is not exist\n";
    }
    else{
        if(!emptyFlag){
            cout<<"the binary tree is empty\n";
        }
        else{
            if(pow(2,Depth(T))-1<index){
                    cout<<"the wrong index\n";
                    return NULL;
                }
                else{
                    if(findNode(T,curNode,parNode,index)){
                        if(curNode->rchild){
                            return curNode->rchild;
                        }
                        else{
                            return NULL;
                        }
                    }
                    else{
                        return NULL;
                    }
                }
        }
    }
    return NULL;
}

bitTree LeftSibling(bitTree T,int index){
    bitTree parNode=Parent(T,index);
    if(parNode){
        if(index%2==0){
            cout<<"the current node is the left child\n";
            return NULL;
        }
        else{
            if(parNode->rchild==NULL){
                cout<<"the current node is not exist\n";
                return NULL;
            }
            else{
                if(parNode->lchild){
                    return parNode->lchild;
                }
                else{
                    cout<<"the left sibling node is not exist\n";
                    return NULL;
                }
            }
        }
    }
    else{
        cout<<"the current node is not exist\n";
        return NULL;
    }
}

bitTree RightSibling(bitTree T,int index){
    bitTree parNode=Parent(T,index);
    if(parNode){
        if(index%2==1){
            cout<<"the current node is the right child\n";
            return NULL;
        }
        else{
            if(parNode->lchild==NULL){
                cout<<"the current node is not exist\n";
                return NULL;
            }
            else{
                if(parNode->rchild){
                    return parNode->rchild;
                }
                else{
                    cout<<"the right sibling node is not exist\n";
                    return NULL;
                }
            }
        }
    }
    else{
        cout<<"the current node is not exist\n";
        return NULL;
    }
}

int InsertChild(bitTree &T,int index,int LR,bitTree C){
    //index：插入子树的位置
    //LR：插入的子树作为左子树还是右子树，0表示左子树，1表示右子树
    //C：插入的子树
    bitTree curNode,parNode;
    if(!T){
        cout<<"the bianry tree is not exist\n";
    }
    else{
        if(!emptyFlag){
            cout<<"the current binary tree is not exist\n";
        }
        else{
            if(pow(2,Depth(T))-1<index){
                cout<<"the current Node is not exist\n";
            }
            else{
                if(findNode(T,curNode,parNode,index)){
                    if(LR==0){
                        //插入后作为左子树，前提是当前节点没有左子树
                        if(curNode->lchild){
                            cout<<"the current Node already has a left child\n";
                        }
                        else{
                            curNode->lchild=C;
                            return 1;
                        }
                    }
                    else{
                        //插入后作为右子树，前提是当前节点没有右子树
                        if(curNode->rchild){
                            cout<<"the current Node already has a right child\n";
                        }
                        else{
                            curNode->rchild=C;
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int DeleteChild(bitTree &T,int index,int LR){
    bitTree curNode,parNode;
    if(!T){
        cout<<"the bianry tree is not exist\n";
    }
    else{
        if(!emptyFlag){
            cout<<"the bianry tree is empty\n";
        }
        else{
            if(pow(2,Depth(T))-1<index){
                cout<<"the current node is not exist\n";
            }
            else{
                if(findNode(T,curNode,parNode,index)){
                    if(LR==0){
                        if(!curNode->lchild){
                            cout<<"the current node don't  have a left child\n";
                        }
                        else{
                            DestroyBitTree(curNode->lchild);
                            return 1;
                        }
                    }
                    else{
                        if(!curNode->rchild){
                            cout<<"the current node don't  have a right child\n";
                        }
                        else{
                            DestroyBitTree(curNode->rchild);
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void PreOrderTraverse(bitTree T){
    if(T){
        if(!emptyFlag){
            cout<<"the binary is empty\n";
        }
        else{
            cout<<T->elem<<' ';
            PreOrderTraverse(T->lchild);
            PreOrderTraverse(T->rchild);
        }
    }
}
void InOrderTraverse(bitTree T){
    if(T){
        if(!emptyFlag){
            cout<<"the binary is empty\n";
        }
        else{
            InOrderTraverse(T->lchild);
            cout<<T->elem<<' ';
            InOrderTraverse(T->rchild);
        }
    }
}

void PostOrderTraverse(bitTree T){
    if(T){
        if(!emptyFlag){
            cout<<"the binary is empty\n";
        }
        else{
            PostOrderTraverse(T->lchild);
            PostOrderTraverse(T->rchild);
            cout<<T->elem<<' ';
        }
    }
}

void LevelOrderTraverse(bitTree T){
    queue <bitTree> parQueue,chiQueue;
    bitTree tmpNode=NULL;
    if(T){
        if(!emptyFlag){
            cout<<"the binary is empty\n";
        }
        else{
            chiQueue.push(T);
            while(!chiQueue.empty()){
                while(!chiQueue.empty()){
                    parQueue.push(chiQueue.front());
                    chiQueue.pop();
                }
                while(!parQueue.empty()){
                    tmpNode=parQueue.front();
                    parQueue.pop();
                    cout<<tmpNode->elem<<' ';
                    if(tmpNode->lchild){
                        chiQueue.push(tmpNode->lchild);
                    }
                    if(tmpNode->rchild){
                        chiQueue.push(tmpNode->rchild);
                    }
                }
            }
        }
    }
}
/*
    定义一个求存在的二叉树的深度函数
*/
int Depth(bitTree T){
    if(T->lchild&&T->rchild){
        int ldepth=Depth(T->lchild);
        int rdepth=Depth(T->rchild);
        return (ldepth>=rdepth?ldepth:rdepth)+1;
    }
    else if(T->lchild&&(!T->rchild)){
        return Depth(T->lchild)+1;
    }
    else if((!T->lchild)&&(T->rchild)){
        return Depth(T->rchild)+1;
    }
    else{
        return 1;
    }
}

int findNode(bitTree T,bitTree &curNode,bitTree &parNode,int index){
    stack <int> tmpStack;
    int flag=0,LR=0;
    while(index){
        tmpStack.push(index);
        index/=2;
    }
    curNode=T;
    parNode=NULL;
    while(!tmpStack.empty()){
        LR=tmpStack.top();
        tmpStack.pop();
        if(LR==1){
            continue;
        }
        else{
            parNode=curNode;
            if(LR%2==0){
                curNode=curNode->lchild;
            }
            else{
                curNode=curNode->rchild;
            }
        }
        if(!curNode){
            return 0;
        }
    }
    return 1;
}