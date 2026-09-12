#include<bits/stdc++.h>
using namespace std;

int n;
int m;

vector<vector<int>> g;
vector<int> color;
vector<bool> vis;


bool dfs(int u, int c, int par){
    vis[u] = true;
    color[u] = c;
    for(auto v :g[u]){
        if(v == par) continue;
        if(color[v] == 0){
            if(!dfs(v, (color[u]^3), u))
                return false;
        }
        if(color[v] == color[u]){
            return false;
        }
    }
    return true;
}


bool color_them(){
    for(int i=0;i<=n;++i){
        if(!vis[i]){
            if(!dfs(i,1,-1))
                return false;
        }
    }

    return true;
}

int main(){
    cin>>n>>m;

    g.resize(n+1);
    vis.resize(n+1,false);
    color.resize(n+1, 0);
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool hehe = color_them();
    if(hehe)
        for(int i=1;i<=n;i++){
            cout<<color[i]<<" ";
        }
    else
        cout<<"IMPOSSIBLE";

}