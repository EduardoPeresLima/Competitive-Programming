//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1076
#include<bits/stdc++.h>
using namespace std; 
typedef vector<set<int>> graph;

int dfs(int no, graph &g, int pai = -1){
    int ans = 1;
    for(int x : g[no]){
        if(x == pai)continue;
        ans += dfs(x,g,no);
    }
    return ans;
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n, m, ini; scanf("%d%d%d",&ini,&n,&m);
        graph g(n+1);
        for(int a,b,i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            g[a].emplace(b);
            g[b].emplace(a);
        }
        printf("%d\n",2*(dfs(ini,g)-1));
    }
}