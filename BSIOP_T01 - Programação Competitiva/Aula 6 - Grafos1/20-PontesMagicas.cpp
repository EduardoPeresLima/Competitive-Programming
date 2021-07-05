//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1706
#include<bits/stdc++.h>
using namespace std; 
typedef vector<vector<int>> graph;

int dfs(int no, graph &g, vector<char> &color){
    int ans = color[no] == 'B';
    color[no] = '*';
    for(int x : g[no]){
        if(color[x] == '*')continue;
        ans += dfs(x,g,color);
    }
    return ans;
}

int main(){
    int n, m;
    while(scanf("%d%d",&n,&m) != EOF){
        vector<char> color(n+1); for(int i=1;i<=n;i++)scanf(" %c",&color[i]);
        graph g(n+1);
        for(int a,b,i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        bool can = true;
        for(int i=1;i<=n;i++){
            if(color[i] == '*')continue;
            can &= (dfs(i,g,color)&1^1);
            /*a linha acima pode ser substituida por uma das duas abaixo:
            can = min(can, dfs(i,g,color)%2 == 0);
            if(dfs(i,g,color)%2 != 0) can = false;
            */
        }
        printf(can?"Y\n":"N\n");
    }
}