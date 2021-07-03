//Link da questao
//https://neps.academy/br/exercise/543
#include<bits/stdc++.h>
using namespace std; 
typedef vector<string> graph;
inline void reads(string& x){char kk[102]; scanf("%s",kk); x = kk;}
int n, m, dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

bool out(int i, int j){
    return i<0 || i>=n || j<0 || j>=m;
}

bool dfs(int i, int j, graph &g, graph &v){
    bool can = g[i][j] == v[i][j];
    g[i][j] = '*';
    for(int k=0;k<4;k++){
        int ni = i + dx[k], nj = j + dy[k];
        if(out(ni,nj) || g[ni][nj] == '.' || g[ni][nj] == '*')continue;
        can &= dfs(ni,nj,g,v);
    }
    return can;
}

int main(){
    scanf("%d%d",&n,&m);
    graph g(n), v(n,string(m,'.')); for(int i=0;i<n;i++)reads(g[i]);
    
    int k; scanf("%d",&k);
    for(int a, b, i=0;i<k;i++){
        scanf("%d%d",&a,&b); --a, --b;
        if(g[a][b] == '#') v[a][b] = '#';
    }
    int ans = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j] == '#')
                ans+=dfs(i,j,g,v);
    printf("%d\n",ans);
}