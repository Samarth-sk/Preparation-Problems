#include<bits/stdc++.h>

using namespace std;


int n,m;
vector<vector<int>> g; 
vector<bool> vis;
vector<int> lead;

int c=0;




void dfs(int x){
    vis[x] = true;
    for(auto u: g[x]){
        if(!vis[u]){
            dfs(u);
        }
    }
}

void CC(){
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            
            c++;
            lead.push_back(i);
            dfs(i);

        }
    }
}

int main(){
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1, false);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    CC();

    cout<<c-1<<"\n";

    if(c>1){
        int u = lead[0];
        int v;
        for(int i=1;i<c;i++){
            v = lead[i];
            
            cout<<u<<" "<<v<<"\n";
            u = v;

        }
    }


}