//Link da questao
//https://neps.academy/br/exercise/567
#include<bits/stdc++.h>
using namespace std; 
typedef vector<vector<int>> graph;
int n, m, dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

bool out(int i, int j){
    return i<0 || i>=n || j<0 || j>=m;
}

void dfs(int i, int j, graph &g, graph &passei){
    passei[i][j] = true;
    for(int k=0;k<4;k++){
        int ni = i + dx[k], nj = j + dy[k];
        if(out(ni,nj) || g[ni][nj] == 0 || passei[ni][nj])continue;
        dfs(ni,nj,g,passei);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    graph g(n,vector<int>(m)), passei(n,vector<int>(m));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&g[i][j]);
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j] && !passei[i][j]){
                dfs(i,j,g,passei);
                ans++;
            }
        }
    }
    printf("%d\n",ans);
}