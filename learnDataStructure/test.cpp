#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a,int b){
    if(a<=b)
        return true;
    else
        return false;
}

int main(){


    //cout<<sizeof(int)<<endl;
    int *p=new int();
    cout<<sizeof(p)<<endl;
    int *q=p+1;
    //q=new int();
    *q=1;
    //cout<<*q<<endl;
    //q=new int();
    cout<<p<<endl<<q<<endl;
    cout<<q-p<<endl;
    //cout<<p<<endl<<(p+1*sizeof(int*))<<endl<<q;
    //delete (p+1);
    return 0;
}