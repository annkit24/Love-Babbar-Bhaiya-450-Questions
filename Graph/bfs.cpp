#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll   long long int
#define endl '\n'
#define INF    10000000
#define D    998244353
#define PI   3.14159265
#define N    1000000007
#define M     200001

int main()
{
    int n,m;
vector<int> graph[n];
    cin>>n>>m;
      
    while(m--){
        int x,y;
        cin>>x>>y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
     queue<int> q;
    vector<bool> visited(n);
    int cnt=0;

    visited[1]=true;
    q.push(1);

    while(!q.empty()){
        int a=q.front();
        q.pop();

        for(auto x:graph[a]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }
       cnt++;
    }
    if(cnt== n){
    cout<<cnt<<endl;
    cout<<"Yes"<<endl;
    }else{
        cout<<cnt<<"\n";
        cout<<"No"<<endl;
    }
    return 0;
}
