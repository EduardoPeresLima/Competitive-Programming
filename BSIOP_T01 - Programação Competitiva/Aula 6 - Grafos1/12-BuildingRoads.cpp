//Link da questao
//https://cses.fi/problemset/task/1666
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
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(passei[i])continue;
        ans.emplace_back(i);
        dfs(i,g,passei);
    }
    int sz = ans.size();
    printf("%d\n",sz-1);
    for(int i=1;i<sz;i++)printf("%d %d\n",ans[0], ans[i]);
}