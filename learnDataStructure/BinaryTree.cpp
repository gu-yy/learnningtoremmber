#include <iostream>
#include "BitTree/bitUtils.h"
using namespace std;

//extern int InitBitTree(bitTree &T);
extern int emptyFlag;

int main(){
    int operation=1,index=0,value=0,tmp=0,e=0,LR=0,tmpEmptyFlag=0,tmpIndex=0;
    bitTree T=NULL,tmpNode=NULL,tmpTree=NULL;
    while(operation){
        system("clear");
        cout<<"======================================================\n";
        cout<<"1:InitBitTree                               2:DestroyBitTree\n";
        cout<<"3:insertNode                              4:ClearBitTree\n";
        cout<<"5:BitTreeEmpty                         6:BitTreeDepth\n";
        cout<<"7:Root                                            8:Value\n";
        cout<<"9:Assign                                        10:Parent\n";
        cout<<"11:LeftChild                                12:RightChild\n";
        cout<<"13:LeftSibling                             14:RightSibling\n";
        cout<<"15:InsertChild                            16:DeleteChild\n";
        cout<<"17:PreOrderTraverse               18:InOrderTraverse\n";
        cout<<"19:PosetOrderTraverse          20:LevelOrderTraverse\n";
        cout<<"0:exit";
        cout<<"======================================================\n";
        cout<<"input your operation:\n";
        cin>>operation;
        //if(InitBitTree(T))
        //    cout<<"init the binary succeed\n";
        //cout<<func(operation)<<endl;
        //cin>>operation;
        switch(operation){
            case 1:
                if(InitBitTree(T)){
                    cout<<"init the binary tree success\n";
                }
                getchar();
                getchar();
                break;
            case 2:
                DestroyBitTree(T);
                cout<<"destroy the binary tree success\n";
                getchar();
                getchar();
                break;
            case 3:
                cout<<"input the location where you insert the elem:\n";
                cin>>index;
                cout<<"input the value of the inserted elem:\n";
                cin>>value;
                if(insertNode(T,index,value)){
                    cout<<"insert the elem success\n";
                }
                getchar();
                getchar();
                break;
            case 4:
                if(ClearBitTree(T)){
                    cout<<"clear the binary tree success\n";
                }
                getchar();
                getchar();
                break;
            case 5:
                tmp=BitTreeEmpty(T);
                if(tmp==1){
                        cout<<"the binary  tree is empty\n";
                }
                if(tmp==-1){
                        cout<<"the binary  tree is not empty\n";
                }
                getchar();
                getchar();
                break;
            case 6:
                tmp=BitTreeDepth(T);
                if(tmp!=-1){
                    cout<<"the depth of the binary is:"<<tmp<<endl;
                }
                getchar();
                getchar();
                break;
            case 7:
                if(Root(T,e)){
                    cout<<"the elem of the root node is:"<<e<<endl;
                }
                getchar();
                getchar();
                break;
            case 8:
                cout<<"input the index of the node you want to look:\n";
                cin>>index;
                if(Value(T,index,e)){
                    cout<<"the elem of the node is:"<<e<<endl;
                }
                getchar();
                getchar();
                break;
            case 9:
                cout<<"input the index where you want to change a node:\n";
                cin>>index;
                cout<<"input the elem you want to change to:\n";
                cin>>e;
                if(Assign(T,index,e)){
                    cout<<"change success\n";
                }
                getchar();
                getchar();
                break;
            case 10:
                cout<<"input the index of the child node:\n";
                cin>>index;
                tmpNode=NULL;
                tmpNode=Parent(T,index);
                if(tmpNode){
                    cout<<"the elem of the parent node is:"<<tmpNode->elem<<endl;
                }
                getchar();
                getchar();
                break;
            case 11:
                cout<<"input the index of the parent node:\n";
                cin>>index;
                tmpNode=NULL;
                tmpNode=LeftChild(T,index);
                if(tmpNode){
                    cout<<"the elem of the left child node is:"<<tmpNode->elem<<endl;
                }
                else{
                    cout<<"the left child node is not exist\n";
                }
                getchar();
                getchar();
                break;
            case 12:
                cout<<"input the index of the parent node:\n";
                cin>>index;
                tmpNode=NULL;
                tmpNode=RightChild(T,index);
                if(tmpNode){
                    cout<<"the elem of the right child node is:"<<tmpNode->elem<<endl;
                }
                else{
                    cout<<"the right child node is not exist\n";
                }
                getchar();
                getchar();
                break;
            case 13:
                cout<<"input the index of the sibling node:\n";
                cin>>index;
                tmpNode=NULL;
                tmpNode=LeftSibling(T,index);
                if(tmpNode){
                    cout<<"the elem of the left sibling node is:"<<tmpNode->elem<<endl;
                }
                else{
                    cout<<"the left sibling node is not exist\n";
                }
                getchar();
                getchar();
                break;
            case 14:
                cout<<"input the index of the sibling node:\n";
                cin>>index;
                tmpNode=NULL;
                tmpNode=RightSibling(T,index);
                if(tmpNode){
                    cout<<"the elem of the right sibling node is:"<<tmpNode->elem<<endl;
                }
                else{
                    cout<<"the right sibling node is not exist\n";
                }
                getchar();
                getchar();
                break;
            case 15:
                cout<<"input the index where to insert the child tree:\n";
                cin>>index;
                cout<<"input the flag which represent the left child(0) or right child(1):\n";
                cin>>LR;
                tmpTree=NULL;
                //保存上下文环境
                tmpEmptyFlag=emptyFlag;
                emptyFlag=0;
                if(InitBitTree(tmpTree)){
                    cout<<"input the index and elem of the new tree,end with index 0:\n";
                    cin>>tmpIndex;
                    while(tmpIndex){
                        cin>>e;
                        insertNode(tmpTree,tmpIndex,e);
                        cin>>tmpIndex;
                    }
                }
                //恢复现场
                emptyFlag=tmpEmptyFlag;
                if(InsertChild(T,index,LR,tmpTree)){
                    cout<<"insert child tree success\n";
                }
                getchar();
                getchar();
                break;
            case 16:
                cout<<"input the index where to delete the child tree:\n";
                cin>>index;
                cout<<"input the flag which represent the left child(0) or right child(1):\n";
                cin>>LR;
                if(DeleteChild(T,index,LR)){
                    cout<<"delete the child tree success\n";
                }
                getchar();
                getchar();
                break;
            case 17:
                PreOrderTraverse(T);
                getchar();
                getchar();
                break;
            case 18:
                InOrderTraverse(T);
                getchar();
                getchar();
                break;
            case 19:
                PostOrderTraverse(T);
                getchar();
                getchar();
                break;
            case 20:
                LevelOrderTraverse(T);
                getchar();
                getchar();
                break;
            default:
                break;
        }
    }
    return 0;
}