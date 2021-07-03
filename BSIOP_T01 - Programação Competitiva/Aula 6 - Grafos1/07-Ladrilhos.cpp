//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/2246
#include<bits/stdc++.h>
using namespace std; 
typedef vector<vector<int>> graph;
int n, m, dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

bool out(int i, int j){
    return i<0 || i>=n || j<0 || j>=m;
}

int dfs(int i, int j, graph &g){
    int ans = 1;
    int myColor = g[i][j];
    g[i][j] = -1; //marcar que ja passei

    for(int k=0;k<4;k++){
        int ni = i + dx[k], nj = j + dy[k];
        if(out(ni,nj) || g[ni][nj] != myColor)continue;
        ans += dfs(ni,nj,g);
    }
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    graph g(n,vector<int>(m)); 
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) 
            scanf("%d",&g[i][j]);
    
    int ans = 1e9;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j] != -1)
                ans = min(ans,dfs(i,j,g));
    printf("%d\n",ans);
}