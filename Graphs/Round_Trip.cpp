#include<bits/stdc++.h>
using namespace std;

int n,m;
int sv, ev;
vector<vector<int>> g;
vector<bool> vis;
vector<int> parent;
vector<int> ans;

bool dfs(int u, int par){
    vis[u] = true;
    parent[u] = par;
    for(auto v:g[u]){
        if(v==par) continue;
        if(vis[v]){
            sv = v;
            ev = u;
            return true;
        }
        if(!vis[v]){
            if(dfs(v,u)){
                return true;
            }
        }
    }
    return false;
}

bool CC(){
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,-1)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin>>n>>m;
    g.resize(n+1);
    parent.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        
    }
    vis.resize(n+1, false);
    
    if(CC()){
        
        int tv = ev;
        ans.push_back(tv);
        while(tv!=sv){
            ans.push_back(parent[tv]);
            tv = parent[tv];
        }
        ans.push_back(ev);
        cout<<ans.size()<<"\n";
        for(auto v:ans){
            cout<<v<<" ";
        }
    } else{
        
        cout<<"IMPOSSIBLE";
    }
}