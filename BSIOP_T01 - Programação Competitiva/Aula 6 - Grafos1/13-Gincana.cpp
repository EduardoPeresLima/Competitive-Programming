//Link da questao
//https://neps.academy/br/exercise/309
#include<bits/stdc++.h>
using namespace std; 
typedef vector<vector<int>> graph;

void dfs(int no, graph &g, vector<int> &passei){
    passei[no] = true;
    for(int x : g[no])
        if(!passei[x])
            dfs(x,g,passei);
}

int main(){
    int n, m; scanf("%d%d",&n,&m);
    graph g(n+1); vector<int> passei(n+1);
    for(int a,b,i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(passei[i])continue;
        dfs(i,g,passei);
        ans++;
    }
    printf("%d\n",ans);
}