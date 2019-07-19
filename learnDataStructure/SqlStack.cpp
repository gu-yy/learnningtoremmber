#include <iostream>
using namespace std;

#define MAX_LENGTH 5
/* 
typedef struct SqlStack
{
    int elem[MAX_LENGTH];
    int op;
    int stackOverSize;
}sqlStack;
*/

typedef struct SqlStack{
    int *elem=NULL;
    int op=0;
    int stackOverSize=MAX_LENGTH;
}sqlStack;

int InitStack(sqlStack &S);
int DestroyStack(sqlStack &S);
int Push(sqlStack &S,int e);
int Pop(sqlStack &S,int &e);
int GetTop(sqlStack S,int &e);
int Empty(sqlStack S);

int main(){
    sqlStack stack;
    int operation=1,e=0;
    while(operation){
        system("clear");
        cout<<"Menu for Linear Table On Stack Structure\n";
        cout<<"---------------------------------------------\n";
        cout<<"1.InitStack\n";
        cout<<"2.DestroyStack\n";
        cout<<"3.Push\n";
        cout<<"4.Pop\n";
        cout<<"5.GetTop\n";
        cout<<"6.Empty\n";
        cout<<"0.Exit\n";
        cout<<"---------------------------------------------\n";
        cout<<"Select your operation:\n";
        cin>>operation;
        switch(operation){
            case 1:
                if(InitStack(stack)==1){
                    cout<<"init the stack success\n";
                }
                getchar();
                getchar();
                break;
            case 2:
                if(DestroyStack(stack)==1){
                    cout<<"desroy the stack success\n";
                }
                getchar();
                getchar();
                break;
            case 3:
                cout<<"input the Elem which will be pushed into the stack\n";
                cin>>e;
                if(Push(stack,e)==1){
                    cout<<"push the Elem success\n";
                }
                getchar();
                getchar();
                break;
            case 4:
                if(Pop(stack,e)==1){
                    cout<<"the Elem which was poped is "<<e;
                }
                getchar();
                getchar();
                break;
            case 5:
                if(GetTop(stack,e)==1){
                    cout<<"the Elem which is on the top of the stack is "<<e;
                }
                getchar();
                getchar();
                break;
            case 6:
                if(Empty(stack)==0){
                    cout<<"the stack is empty\n";
                }
                else{
                    cout<<"the stack is not empty\n";
                }
                getchar();
                getchar();
                break;
            case 0:
                return 0;
        }
    }
}

int InitStack(sqlStack &S){
    if(S.elem){
        cout<<"init error,the stack is exist\n";
        return 0;
    }
    S.elem=new int[MAX_LENGTH];
    S.op=0;
    S.stackOverSize=MAX_LENGTH;
    return 1;
}
int DestroyStack(sqlStack &S){
    if(!S.elem){
        cout<<"the stack is not exist\n";
        return 0;
    }
    S.op=0;
    S.stackOverSize=0;
    delete []S.elem;
    S.elem=NULL;
    return 1;
}
int Push(sqlStack &S,int e){
    if(!S.elem){
        cout<<"the stack is not exist\n";
        return 0;
    }
    if(S.op==S.stackOverSize){
        cout<<"the stack is overflow";
        return 0;
    }
    else{
        S.elem[S.op]=e;
        S.op++;
        return 1;
    }
}
int Pop(sqlStack &S,int &e){
    if(!S.elem){
        cout<<"the stack is not exist\n";
        return 0;
    }
    if(S.op==0){
        cout<<"the stack is underflow\n";
        e=0;
        return 0;
    }
    else{
        S.op--;
        e=S.elem[S.op];
        return 1;
    }
}
int GetTop(sqlStack S,int &e){
    if(!S.elem){
        cout<<"the stack is not exist\n";
        return 0;
    }
    if(S.op==0){
        cout<<"the stack is underflow\n";
        e=0;
        return 0;
    }
    else{
        e=S.elem[S.op-1];
        return 1;
    }
}
int Empty(sqlStack S){
    if(!S.elem){
        cout<<"the stack is not exist\n";
        return 0;
    }
    if(S.op==0){
        return 0;
    }
    else{
        return 1;
    }
}