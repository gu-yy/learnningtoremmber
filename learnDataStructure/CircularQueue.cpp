#include <iostream>

using namespace std;
//implemented by array
typedef struct Queue{
    int *elem=NULL;
    int head=0,tail=0;
    int length=0;
}queue;
int InitQueue(queue &Q,int length);
int DestroyQueue(queue &Q);
int EnQueue(queue &Q,int e);
int DeQueue(queue &Q,int &e);
int GetTop(queue Q,int &e);
int Empty(queue Q);

int main(){
    queue Q;
    int operation=1,length=0,e=0,tmp=0;
    while(operation){
        system("clear");
        cout<<"Menu for Linear Table On Circular Queue Structure\n";
        cout<<"---------------------------------------------\n";
        cout<<"1.InitQueue\n";
        cout<<"2.DestroyQueue\n";
        cout<<"3.EnQueue\n";
        cout<<"4.Dequeue\n";
        cout<<"5.GetTop\n";
        cout<<"6.Empty\n";
        cout<<"0.Exit\n";
        cout<<"---------------------------------------------\n";
        cout<<"Select your operation:\n";
        cin>>operation;
        switch(operation){
            case 1:
                cout<<"input the length of the queue\n";
                cin>>length;
                if(InitQueue(Q,length)){
                    cout<<"Init the queue success\n";
                }
                getchar();
                getchar();
                break;
            case 2:
                if(DestroyQueue(Q)){
                    cout<<"Destroy the queue success\n";
                }
                getchar();
                getchar();
                break;
            case 3:
                cout<<"input the elem added to the queue\n";
                cin>>e;
                if(EnQueue(Q,e)){
                    cout<<"input elem success\n";
                }
                getchar();
                getchar();
                break;
            case 4:
                if(DeQueue(Q,e)){
                    cout<<"output the elem "<<e<<" success\n";
                }
                getchar();
                getchar();
                break;
            case 5:
                if(GetTop(Q,e)){
                    cout<<"get the top elem "<<e<<" success\n";
                }
                getchar();
                getchar();
                break;
            case 6:
                tmp=Empty(Q);
                if(tmp==1){
                    cout<<"the queue is empty\n";
                }
                else if(tmp==-1){
                    cout<<"the queue is not empty\n";
                }
                getchar();
                getchar();
                break;
            case 0:
                return 0;
        }
    }
    return 0;
}
int InitQueue(queue &Q,int length){
    if(Q.elem){
        cout<<"the queue is exist\n";
        return 0;
    }
    Q.elem=new int[length];
    Q.head=0;
    Q.tail=0;
    Q.length=length;
    return 1;
}
int DestroyQueue(queue &Q){
    if(!Q.elem){
        cout<<"the queue is not exist\n";
        return 0;
    }else{
        delete []Q.elem;
        Q.elem=NULL;
        Q.head=0;
        Q.tail=0;
        Q.length=0;
        return 1;
    }
}
int EnQueue(queue &Q,int e){
    if(!Q.elem){
        cout<<"the queue is not exist\n";
        return 0;
    }
    if((Q.head+1)%Q.length==Q.tail){
        //当队列只剩下最后一个位置的时候，就判定为满了
        cout<<"the queue is filled\n";
        return 0;
    }
    Q.elem[Q.head]=e;
    Q.head=(Q.head+1)%Q.length;
    return 1;
}
int DeQueue(queue &Q,int &e){
    if(!Q.elem){
        cout<<"the queue is not exist\n";
        return 0;
    }
    if(Q.head==Q.tail){
        cout<<"the queue is empty\n";
        return 0;
    }
    e=Q.elem[Q.tail];
    Q.tail=(Q.tail+1)%Q.length;
    return 1;
}
int GetTop(queue Q,int &e){
    if(!Q.elem){
        cout<<"the queue is not exist\n";
        return 0;
    }
    if(Q.head==Q.tail){
        cout<<"the queue is empty\n";
        return 0;
    }
    int tmp=(Q.head-1)%Q.length;
    e=Q.elem[tmp];
    return 1;
}
int Empty(queue Q){
    if(!Q.elem){
        cout<<"the queue is not exist\n";
        return 0;
    }
    if(Q.head==Q.tail){
        return 1;
    }else{
        return -1;
    }
}

