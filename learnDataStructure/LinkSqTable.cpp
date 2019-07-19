#include <iostream>
using namespace std;

/*
 *两种方式定义链表的节点结构
 struct node{
     int data;
     struct node *next;
 };
 struct node *head *tail;
 */
typedef struct node{
    int data;
    struct node *next;
}node,*LinkList;
/*
 *两种方式声明表节点
 * LinkList head,tail;
 * node *head,*tail;
 * 效果都是一样的
 */
bool compare(int a,int b);
int InitList(LinkList &L,int &length);
int DestroyList(LinkList &L,int &length);
int ClearList(LinkList &L,int &length);
int ListEmpty(LinkList L,int length);
int ListLength(LinkList L,int length);
void GetElem(LinkList L,int i,int &e,int length);
int LocateElem(LinkList L,int e);
int PrioElem(LinkList L,int cur_e,int &pre_e,int length);
int NextElem(LinkList L,int cur_e,int &next_e,int length);
int ListInsert(LinkList &L,int i,int e,int &length);
int ListDelete(LinkList &L,int i,int &e,int &length);
void ListTraverse(LinkList L,int length);

int main(){
    LinkList head=NULL,tail=NULL;
    int operation=1,i=0,e=0,location=0,cur_e=0,pre_e=0,next_e=0,flag=0,length=0;
    while(operation){
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
        switch(operation){
            case 1:
                if(InitList(head,length))
                    cout<<"init succeed\n";
                tail=head;
                getchar();
                getchar();
                break;
            case 2:
                if(DestroyList(head,length)){
                    cout<<"destroy succeed\n";
                }
                getchar();
                getchar();
                break;
            case 3:
                if(ClearList(head,length)){
                    cout<<"clear succeed\n";
                }
                getchar();
                getchar();
                break;
            case 4:
                if(ListEmpty(head,length)){
                    cout<<"the table is empty\n";
                }
                else{
                    cout<<"the table is not empty\n";
                }
                getchar();
                getchar();
                break;
            case 5:
                cout<<ListLength(head,length);
                getchar();
                getchar();
                break;
            case 6:
                cout<<"input the location\n";
                cin>>i;
                GetElem(head,i,e,length);
                cout<<"get the elem: e="<<e;
                getchar();
                getchar();
                break;
            case 7:
                cout<<"input the Elem\n";
                cin>>e;
                location=LocateElem(head,e);
                if(location==-1){
                    cout<<"there is not the Elem int the table\n";
                }
                else{
                    cout<<"the location of the Elem "<<e<<" in the table is "<<location<<endl;
                }
                getchar();
                getchar();
                break;
            case 8:
                cout<<"input the Elem\n";
                cin>>cur_e;
                flag=PrioElem(head,cur_e,pre_e,length);
                if(flag){
                    cout<<"the preElem of the currentElem "<<cur_e<<" is "<<pre_e<<endl;
                }
                getchar();
                getchar();
                break;
            case 9:
                cout<<"input the Elem\n";
                cin>>cur_e;
                flag=NextElem(head,cur_e,next_e,length);
                if(flag){
                    cout<<"the nextElem of the currentElem "<<cur_e<<" is "<<next_e<<endl;
                }
                getchar();
                getchar();
                break;
            case 10:
                cout<<"input the location of the insertElem\n";
                cin>>i;
                cout<<"input the insertElem\n";
                cin>>e;
                flag=ListInsert(head,i,e,length);
                if(flag){
                    cout<<"insert Elem succeed\n";
                }
                getchar();
                getchar();
                break;
            case 11:
                cout<<"input the location of the deleteElem\n";
                cin>>i;
                flag=ListDelete(head,i,e,length);
                if(flag){
                    cout<<"delete the Elem "<<e<<" from the table succeed\n";
                }
                getchar();
                getchar();
                break;
            case 12:
                cout<<"traverse the table blow\n";
                ListTraverse(head,length);
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
int InitList(LinkList &L,int &length){
    L=new node();
    //cout<<L<<endl;
    if(!L){
        cout<<"init failed\n";
        exit(-1);
    }
    L->next=NULL;
    length=0;
    return 1;
}
int DestroyList(LinkList &L,int &length){
    LinkList preTmp=L,latTmp=L;
    //cout<<preTmp<<endl;
    if(!preTmp){
        cout<<"the table is not exist\n";
        exit(-1);
    }
    do{
        preTmp=latTmp;
        latTmp=preTmp->next;
        delete preTmp;
        preTmp=NULL;
    }while(latTmp!=NULL);
    L=NULL;
    length=0;
    return 1;
}
int ClearList(LinkList &L,int &length){
    LinkList preTmp=L->next,latTmp=L->next;
    if(!L){
        cout<<"the table is not exist\n";
        exit(-1);
    }
    length=0;
    if(!preTmp){
        return 1;
    }
    do{
        preTmp=latTmp;
        latTmp=preTmp->next;
        delete preTmp;
        preTmp=NULL;
    }while(latTmp!=NULL);
    return 1;
}
int ListEmpty(LinkList L,int length){
    if(!L){
        cout<<"the table is not exist\n";
        exit(-1);
    }
    if(length==0){
        return 1;
    }
    else{
        return 0;
    }
}
int ListLength(LinkList L,int length){
    if(!L){
        cout<<"the table is not exist\n";
        exit(-1);
    }
    return length;
}
void GetElem(LinkList L,int i,int &e,int length){
    if(!L){
        cout<<"the table is not exist\n";
        exit(-1);
    }
    LinkList tmp=L;
    if(i<1||i>length){
        cout<<"the error location\n";
        exit(-1);
    }
    for(int location=1;location<i;location++){
        tmp=tmp->next;
    }
    e=tmp->data;
    return;
}
int LocateElem(LinkList L,int e){
    if(!L){
        cout<<"the table is not exist\n";
        exit(-1);
    }
    int location=0,tmpNumber=0;
    LinkList tmp=L;
    while((tmp->data!=e)&&(tmp!=NULL)){
        location++;
        //tmpNumber=tmp->data;
        tmp=tmp->next;
    }
    if(!tmp){
        return -1;
    }
    else{
        return location+1;
    }
}
int PrioElem(LinkList L,int cur_e,int &pre_e,int length){
    if(!L){
        cout<<"the table is not exist\n";
        exit(-1);
    }
    LinkList tmp=L;
    int location=LocateElem(tmp,cur_e);
    if((location<=1)||(location>length)){
        cout<<"illegal input\n";
        return 0;
    }
    tmp=L;
    for(int i=1;i<location-1;i++){
        tmp=tmp->next;
    }
    pre_e=tmp->data;
    return 1;
}
int NextElem(LinkList L,int cur_e,int &next_e,int length){
    if(!L){
        cout<<"the table is not exist\n";
        exit(-1);
    }
    LinkList tmp=L;
    int location=LocateElem(tmp,cur_e);
    if((location<1)||(location>=length)){
        cout<<"illegal input\n";
        return 0;
    }
    tmp=L;
    for(int i=1;i<=location;i++){
        tmp=tmp->next;
    }
    next_e=tmp->data;
    return 1;
}
int ListInsert(LinkList &L,int i,int e,int &length){
    if(!L){
        cout<<"the table is not exist\n";
        exit(-1);
    }
    if(i<1||i>length+1){
        cout<<"illegal location\n";
        return 0;
    }
    LinkList tmp=L,insertTmp=NULL;
    insertTmp=new node();
    insertTmp->data=e;
    for(int j=1;j<i-1;j++){
        tmp=tmp->next;
    }
    if(length==0){
        L->data=e;
        length++;
        return 1;
    }
    else{
        if(i==1){
            insertTmp->next=L;
            L=insertTmp;
            length++;
            return 1;
        }
        else{
            if(i==length+1){
                tmp->next=insertTmp;
                insertTmp->next=NULL;
                length++;
                return 1;
            }
            else{
                insertTmp->next=tmp->next;
                tmp->next=insertTmp;
                length++;
                return 1;
            }
        }
    }
}
int ListDelete(LinkList &L,int i,int &e,int &length){
    if(!L){
        cout<<"the table is not exist\n";
        exit(-1);
    }
    if(i<1||i>length){
        cout<<"illegal location\n";
        return 0;
    }
    LinkList tmp=L,deleteTmp=NULL;
    for(int j=1;j<i-1;j++){
        tmp=tmp->next;
    }
    if(i==length){
        e=tmp->next->data;
        delete tmp->next;
        tmp->next=NULL;
        length--;
        return 1;
    }
    else{
        e=tmp->next->data;
        deleteTmp=tmp->next;
        tmp->next=deleteTmp->next;
        delete deleteTmp;
        deleteTmp=NULL;
        length--;
        return 1;
    }
}
void ListTraverse(LinkList L,int length){
    if(!L){
        cout<<"the table is not exist\n";
        exit(-1);
    }
    LinkList tmp=L;
    for(int i=0;i<length;i++){
        cout<<tmp->data<<' ';
        tmp=tmp->next;
    }
}
