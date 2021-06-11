//https://www.codechef.com/problems/MARCHA1
#include<bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
bool subset(int *a,int n,int m){

    if(m==0){
        return true;
    }
    if(n==0 && m!=0){
        return false;
    }
    if(a[n-1]>m){
        return subset(a,n-1,m);
    }else{
        return subset(a,n-1,m-a[n-1])||subset(a,n-1,m);
    }

}
int main(){
    fastio
 int t;
 cin>>t;
 while(t--){
     int n,m;
     cin>>n>>m;
     int a[n];
     for(int i=0;i<n;i++){
         cin>>a[i];
     }
      if(subset(a,n,m)==true){
          cout<<"Yes"<<endl;
      }else{
          cout<<"No"<<endl;
      }
 }   
    return 0;
}
