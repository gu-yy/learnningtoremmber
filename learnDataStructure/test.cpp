#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

bool compare(int a,int b){
    if(a<=b)
        return true;
    else
        return false;
}

int main(){


    stack <int> sta;
    queue <int*> que;
    int * p=NULL;
    que.push(p);
    cout<<que.empty()<<endl;
    sta.push(1);
    sta.push(2);
    int i=0;
    while (!sta.empty())
    {
        i=sta.top();
        sta.pop();
        cout<<i<<endl;
    }
    
    
    return 0;
}