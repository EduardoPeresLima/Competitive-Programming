//Link da questao
//https://neps.academy/br/exercise/543
#include<bits/stdc++.h>
using namespace std; 
typedef vector<string> graph;
inline void reads(string& x){char kk[252]; scanf("%s",kk); x = kk;}
int n, m, dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

bool out(int i, int j){
    return i<0 || i>=n || j<0 || j>=m;
}

pair<int,int> dfs(int i, int j, graph &g){
    pair<int,int> ans = {0,0};
    if(g[i][j] == 'k')ans.first++;
    else if(g[i][j] == 'v')ans.second++;
    g[i][j] = '*'; //marcar que ja passei

    for(int k=0;k<4;k++){
        int ni = i + dx[k], nj = j + dy[k];
        if(out(ni,nj) || g[ni][nj] == '#' || g[ni][nj] == '*')continue;
        pair<int,int> ret = dfs(ni,nj,g);
        ans.first += ret.first;
        ans.second += ret.second;
    }
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    graph g(n); for(int i=0;i<n;i++)reads(g[i]);
    
    pair<int,int> ans;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(g[i][j] == '*' || g[i][j] == '#')continue;
            pair<int,int> ret = dfs(i,j,g);
            if(ret.first > ret.second)ret.second = 0;
            else ret.first = 0;
            ans.first += ret.first;
            ans.second += ret.second;
        }
    printf("%d %d\n",ans.first, ans.second);
}