#include <iostream>
#include <string>
using namespace std;

/*
 * 朴素匹配算法
 */
int SimpleMatch(string Sparent,string Schild){
    int flag=-1;
    int lengthParent=Sparent.length();
    int lengthChild=Schild.length();
    for(int i=0;i<lengthParent;i++){
        for(int j=0;j<lengthChild;j++){
            if(Schild[j]==Sparent[i+j]){
                if(j==lengthChild-1){
                    flag=i;
                    break;
                }
                continue;
            }else{
                break;
            }
        }
    }
    return flag;
}
/*
 * KMP算法
 */
//首先求next数组
void Next(string Cstr,int next[]){
    int length=Cstr.length();
    int j=0,k=-1;
    next[j]=k;
    while(j<length-1){
        if(k==-1||Cstr[j]==Cstr[k]){
            next[++j]=++k;
        }
        else{
            k=next[k];
        }
    } 
}
int KMP(string Pstr,string Cstr,int next[]){
    int lenPstr=Pstr.length();
    int lenCstr=Cstr.length();
    int flag=-1,i=0,j=0;
    while(i<lenPstr){
        if(Pstr[i]==Cstr[j]){
            i++;
            j++;
            if(j==lenCstr){
                flag=i-j;
                break;
            }
            else{
                continue;
            }
        }
        else{
            j=next[j];
            if(j==-1){
                i++;
                j++;
            }
        }
    }
    return flag;
}
int main(){
    string s1="abcfahahgj",s2="ahahg";
    cout<<SimpleMatch(s1,s2)<<endl;
    int len=s2.length();
    int next[len]={0};
    Next(s2,next);
    cout<<KMP(s1,s2,next)<<endl;
    return 0;
}