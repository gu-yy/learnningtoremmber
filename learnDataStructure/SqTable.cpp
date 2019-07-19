#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_LENGTH 100
typedef int Status;
typedef char ElemType;
/**
 * 3 way to define a linear table
 * -----------1------------
 * int SqList[MAX_LENGTH];
 * int length=MAX_LENGTH;
 * -----------2------------
 * typedef struct{
 *      int elem[MAX_LENGTH];
 *      int length=MAX_LENGTH;
 * }SqList;
 * SqList L;
 * -----------3------------
 * typedef struct{
 *      int *elem;
 *      int length;
 * }SqList
 * SqList L;
 */
typedef struct SQLIST{
    int *elem=NULL;
    int length=0;
}SqList;
bool compare(int a,int b);
bool equal(int a,int b);
bool visit(int a,int b);
int InitList(SqList &L);
int DestroyList(SqList &L);
int ClearList(SqList &L);
int ListEmpty(SqList L);
int ListLength(SqList L);
void GetElem(SqList L,int i,int &e);
int LocateElem(SqList L,int e,bool compare(int a,int b));
int PrioElem(SqList L,int cur_e,int &pre_e);
int NextElem(SqList L,int cur_e,int &next_e);
int ListInsert(SqList &L,int i,int e);
int ListDelete(SqList &L,int i,int &e);
void ListTraverse(SqList L,bool visit(int a,int b));
int main(){
    SqList L;
    int operation=1,e=0,i=0,cur_e=0,pre_e=0,next_e=0,location=0,flag=0;
    while (operation)
    {
        /* code */
        system("clear");
        cout<<"Menu for Linear Table On Sequence Structure\n";
        cout<<"---------------------------------------------\n";
        cout<<"1.InitList                      7.LocateElem\n";
        cout<<"2.DestroyList                   8.PrioElem\n";
        cout<<"3.ClearList                     9.NextElem\n";
        cout<<"4.ListEmpty                     10.ListInsert\n";
        cout<<"5.ListLength                    11.ListDelete\n";
        cout<<"6.GetElem                       12.ListTrabverse\n";
        cout<<"0.Exit\n";
        cout<<"---------------------------------------------\n";
        cout<<"Select your operation:\n";
        cin>>operation;
        switch (operation){
        case 1:
            if(InitList(L)==OK)
                cout<<"init success\n";
            getchar();
            getchar();
            break;
        case 2:
            if(DestroyList(L)==OK){
                cout<<"destroy success\n";
            }
            getchar();
            getchar();
            break;
        case 3:
            if(ClearList(L)==OK){
                cout<<"clear suceess\n";
            }
            getchar();
            getchar();
            break;
        case 4:
            if(ListEmpty(L)==TRUE){
                cout<<"the table is empty\n";
            }
            else{
                cout<<"the table is not empty\n";
            }
            getchar();
            getchar();
            break;
        case 5:
            cout<<ListLength(L);
            getchar();
            getchar();
            break;
        case 6:
            cout<<"input the location\n";
            cin>>i;
            GetElem(L,i,e);
            cout<<"get the elem: e="<<e;
            getchar();
            getchar();
            break;
        case 7:
            cout<<"input the elem\n";
            cin>>e;
            location=LocateElem(L,e,compare);
            if(location==0){
                cout<<"there is not the elem in the table\n";
            }
            else{
                cout<<"the location of the elem in the table is "<<location;
            }
            getchar();
            getchar();
            break;
        case 8:
            cout<<"input the elem\n";
            cin>>cur_e;
            flag=PrioElem(L,cur_e,pre_e);
            if(flag==0){
                cout<<"get the prioElem failed\n";
            }
            else{
                cout<<"the prioElem of "<<cur_e<<"is "<<pre_e;
            }
            getchar();
            getchar();
            break;
        case 9:
            cout<<"input the elem\n";
            cin>>cur_e;
            flag=NextElem(L,cur_e,next_e);
            if(flag==0){
                cout<<"get the nextElem failed\n";
            }
            else{
                cout<<"the nextElem of "<<cur_e<<"is "<<next_e;
            }
            getchar();
            getchar();
            break;
        case 10:
            cout<<"input the insert location\n";
            cin>>i;
            cout<<"input the insert elem\n";
            cin>>e;
            flag=ListInsert(L,i,e);
            if(flag==0){
                cout<<"insert Elem failed\n";
            }
            else{
                cout<<"insert the Elem "<<e<<" succeed\n";
            }
            getchar();
            getchar();
            break;
        case 11:
            cout<<"input the location of the delete Elem\n";
            cin>>i;
            flag=ListDelete(L,i,e);
            if(flag==0){
                cout<<"delete Elem failed\n";
            }
            else{
                cout<<"delete the Elem "<<e<<" succeed\n";
            }
            getchar();
            getchar();
            break;
        case 12:
            cout<<"traverse the table\n";
            ListTraverse(L,visit);
            getchar();
            getchar();
            break;
        case 0:
            return 0;
        }
    }
    
    return 0;
}

bool compare(int a,int b){
    if(a==b)
        return true;
    else
        return false;
}
bool equal(int a,int b){
    if(a==b)
        return true;
    else
        return false;
}
bool visit(int a,int b){
    return true;
}
int InitList(SqList &L){
    L.elem=new int[MAX_LENGTH];//理论上new int 和new int()的区别是不大，new int 没有给数据初始化，new int()给数据初始化了
    if(!L.elem){
        cout<<"init error";
        exit(-1);
    }
    L.length=0;
    return OK;
}
int DestroyList(SqList &L){
    delete []L.elem;
    L.elem=NULL;//释放掉了内存，但是不代表会指向NULL，需要手动指定
    if(L.elem){
        cout<<"destroy the list error\n";
        exit(-1);
    }
    L.length=0;
    return OK;
}
int ClearList(SqList &L){
    L.length=0;
    return OK;
}
int ListEmpty(SqList L){
    if(!L.elem){
        cout<<"the table is not exist";
        exit(-1);
    }
    if(L.length==0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
int ListLength(SqList L){
    if(!L.elem){
        cout<<"the table is not exist";
        exit(-1);
    }
    return L.length;
}
void GetElem(SqList L,int i,int &e){
    if(!L.elem){
        cout<<"the table is not exist";
        exit(-1);
    }
    if(i<1||i>L.length){
        cout<<"illegal input\n";
        return;
    }
    e=*(L.elem+i-1);
    return;
}
int LocateElem(SqList L,int e,bool compare(int a,int b)){
    if(!L.elem){
        cout<<"the table is not exist";
        exit(-1);
    }
    for(int i=0;i<L.length;i++){
        if(compare(*(L.elem+i),e)){
            return i+1;
        }
    }
    return 0;
}
int PrioElem(SqList L,int cur_e,int &pre_e){
    if(!L.elem){
        cout<<"the table is not exist";
        exit(-1);
    }
    int location=LocateElem(L,cur_e,equal);
    if(location==0||location==1){
        return 0;
    }
    else{
        pre_e=*(L.elem+location-2);
        return 1;
    }
}
int NextElem(SqList L,int cur_e,int &next_e){
    if(!L.elem){
        cout<<"the table is not exist";
        exit(-1);
    }
    int location=LocateElem(L,cur_e,equal);
    if(location==0||location==L.length){
        return 0;
    }
    else{
        next_e=*(L.elem+location);
        return 1;
    }
}
int ListInsert(SqList &L,int i,int e){
    if(!L.elem){
        cout<<"the table is not exist";
        exit(-1);
    }
    if(i<1||i>L.length+1){
        cout<<"illegal location\n";
        return 0;
    }
    for(int j=L.length;j>=i;j--){
        *(L.elem+j)=*(L.elem+j-1);
    }
    *(L.elem+i-1)=e;
    L.length++;
    return 1;
}
int ListDelete(SqList &L,int i,int &e){
    if(!L.elem){
        cout<<"the table is not exist";
        exit(-1);
    }
    if(i<1||i>L.length){
        cout<<"illegal location\n";
        return 0;
    }
    e=*(L.elem+i-1);
    for(int j=i-1;j<L.length-1;j++){
        *(L.elem+j)=*(L.elem+j+1);
    }
    L.length--;
    return 1;
}
void ListTraverse(SqList L,bool visit(int a,int b)){
    if(!L.elem){
        cout<<"the table is not exist";
        exit(-1);
    }
    for(int i=0;i<L.length;i++){
        if(visit(*(L.elem+i),1)){
            cout<<*(L.elem+i)<<' ';
        }
    }
    return;
}

