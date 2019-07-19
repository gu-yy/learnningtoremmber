#include <iostream>
using namespace std;

typedef struct LinkStack
{
    /* data */
    int elem;
    struct LinkStack *prio;
    struct LinkStack *next;
} *linkStack;

int InitStack(linkStack &S,int &length);
int DestroyStack(linkStack &S,int &length);
int Push(linkStack &S,int e,int &length);
int Pop(linkStack &S,int &e,int &length);
int GetTop(linkStack S,int &e);
int Empty(linkStack S,int length);

int main(){
    linkStack stack=NULL;
    int operation=1,length=0,e=0,flag=0;
    while (operation)
    {
        /* code */
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
        switch (operation)
        {
        case 1/* constant-expression */:
            /* code */
            if(InitStack(stack,length)==1){
                cout<<"init the stack success\n";
            }
            getchar();
            getchar();
            break;
        case 2:
            if(DestroyStack(stack,length)==1){
                cout<<"destroy the stack success\n";
            }
            getchar();
            getchar();
            break;
        case 3:
            cout<<"input the elem be pushed\n";
            cin>>e;
            if(Push(stack,e,length)==1){
                cout<<"push the elem success";
            }
            getchar();
            getchar();
            break;
        case 4:
            if(Pop(stack,e,length)==1){
                cout<<"Pop the elem success e = "<<e<<endl;
            }
            getchar();
            getchar();
            break;
        case 5:
            if(GetTop(stack,e)==1){
                cout<<"the top elem of the stack is "<<e<<endl;
            }
            getchar();
            getchar();
            break;
        case 6:
            flag=Empty(stack,length);
            if(flag==1){
                cout<<"the stack is empty\n";
            }
            else if(flag==-1){
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
int InitStack(linkStack &S,int &length){
    if(S){
        cout<<"the stack is exist\n";
        return 0;
    }
    else{
        S=new LinkStack();
        S->prio=NULL;
        S->next=NULL;
        length=0;
        return 1;
    }
}
int DestroyStack(linkStack &S,int &length){
    if(!S){
        cout<<"the stack is not exist\n";
        return 0;
    }
    else{
        linkStack curTmp=S;
        while(S){
            curTmp=S;
            S=S->prio;
            delete curTmp;
        }
        length=0;
        return 1;
    }
}
int Push(linkStack &S,int e,int &length){
    if(!S){
        cout<<"the stack is not exist\n";
        return 0;
    }
    else{
        if(length==0){
            S->elem=e;
            length++;
        }
        else{
            S->next=new LinkStack();
            S->next->prio=S;
            S=S->next;
            S->elem=e;
            length++;
        }
        return 1;
    }
}
int Pop(linkStack &S,int &e,int &length){
    if(!S){
        cout<<"the stack is not exist\n";
        return 0;
    }
    else{
        if(length==0){
            cout<<"the stack is empty\n";
            return 0;
        }
        else if(length==1){
            e=S->elem;
            length--;
        }
        else{
            e=S->elem;
            S=S->prio;
            delete S->next;
            S->next=NULL;
            length--;
        }
        return 1;
    }
}
int GetTop(linkStack S,int &e){
    if(!S){
        cout<<"the stack is not exist\n";
        return 0;
    }
    e=S->elem;
    return 1;
}
int Empty(linkStack S,int length){
    if(!S){
        cout<<"the stack is not exist\n";
        return 0;
    }
    if(length==0){
        return 1;
    }
    else{
        return -1;
    }
}