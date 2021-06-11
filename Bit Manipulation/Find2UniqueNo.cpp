#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll   long long int
#define endl '\n'

void findUniq2(int a[],int n){
    int res=0;
    for(int i=0;i<n;i++){
        res=res^a[i];
    }
    int i=0;
    int temp=res;
    while(temp>0){
        if(temp&1){
            break;
        }
        i++;
        temp=temp>>1;
    }
    int mask=(1<<i);
    int FirstNo=0;
    for(int i=0;i<n;i++){
        if((mask&a[i])!=0){
            FirstNo=FirstNo^a[i];
        }
    }
    int secondNo=0;
    secondNo=res^FirstNo;

    cout<<FirstNo<<" "<<secondNo<<endl;
}


int main()
{
    fastio
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    findUniq2(a,n);
    return 0;
}
