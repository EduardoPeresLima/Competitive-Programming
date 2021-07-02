//Link da questao
//https://neps.academy/br/exercise/825
#include<bits/stdc++.h>
using namespace std; 
typedef vector<string> graph;
inline void reads(string& x){char kk[502]; scanf("%s",kk); x = kk;}
int n, f, dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

bool out(int i, int j){
    return i<0 || i>=n || j<0 || j>=n;
}

void dfs(int i, int j, graph &g){
    g[i][j] = '*';
    for(int k=0;k<4;k++){
        int ni = i + dx[k], nj = j + dy[k];
        if(out(ni,nj) || g[ni][nj] == '*' || g[ni][nj]-'0' > f)continue;
        dfs(ni,nj,g);
    }
}

int main(){
    scanf("%d%d",&n,&f);
    graph g(n);
    for(int i=0;i<n;i++)reads(g[i]);
    if(g[0][0]-'0'<=f) dfs(0,0,g);
    for(int i=0;i<n;i++) printf("%s\n",g[i].data());
}