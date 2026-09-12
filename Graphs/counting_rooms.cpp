#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> vis;
vector<pair<int,int>> moves = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
int rooms = 0;

bool valid(int x, int y){
    if((x<0 || x>=n) || (y<0 || y>=m)){
        return false;
    }
    if(vis[x][y] == true){
        return false;
    }
    
    return true;
}

void dfs(int x, int y){
    vis[x][y] = true;
    for(auto i : moves){
        if(valid(x+i.first, y+i.second)){
            dfs(x+i.first, y+i.second);
        }
    }
}

void CC(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                dfs(i,j);
                rooms++;
            }
        }
    }
}



int main(){
    cin>>n>>m;
    vis.assign(n, vector<bool>(m, false));


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char temp;
            cin>>temp;
            if(temp == '#'){
                vis[i][j] = true;
            }else{
                vis[i][j] = false;
            }
        }
    }
    CC();
    cout<<rooms;

    


}