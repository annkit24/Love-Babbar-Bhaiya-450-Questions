#include<bits/stdc++.h>
using namespace std;
void solve(char *a,int no){
    int i=0;
    while(no>0){
        (no&1)?cout<<a[i]:cout<<"";
        i++;
        no=no>>1;
    }
    cout<<endl;
}
int main(){
    char a[100];
    cin>>a;
    int n=strlen(a);
    int range=(1<<n)-1;
    for(int i=0;i<=range;i++){
        solve(a,i);
    }
    return 0;
}
/* 
INPUT:abc
O/P:

a
b
ab
c
ac
bc
abc



*/
