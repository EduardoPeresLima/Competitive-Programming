//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1905
#include<bits/stdc++.h>
using namespace std; 
typedef vector<vector<int>> graph;
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
bool out(int i, int j){
    return i<0 || i>=5 || j<0 || j>=5;
}
bool bfs(int i, int j, graph &g){
    if(g[i][j])return false;
    queue<pair<int,int>> q; q.emplace(i,j);
    g[i][j] = 1;
    while(!q.empty()){
        tie(i,j) = q.front(); q.pop();
        for(int k=0;k<4;k++){
            int ni = i+dx[k], nj = j+dy[k];
            if(out(ni,nj) || g[ni][nj])continue;
            g[ni][nj] = 1;
            if(ni == 4 && nj == 4)return true;
            q.emplace(ni,nj);
        }
    }
    return false;
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        graph g(5,vector<int>(5));
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
                scanf("%d",&g[i][j]);
        printf(bfs(0,0,g)?"COPS\n":"ROBBERS\n");
    }
}