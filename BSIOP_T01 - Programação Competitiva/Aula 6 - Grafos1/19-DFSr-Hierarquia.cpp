//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1081
#include<bits/stdc++.h>
using namespace std; 
typedef vector<set<int>> graph;

void dfs(int no, graph &g, vector<bool> &passei, int depth = 1){
    passei[no] = true;
    for(int x : g[no]){
        for(int i=0;i<depth;i++)printf("  ");
        printf("%d-%d",no,x);
        if(passei[x]){
            printf("\n");
            continue;
        }
        printf(" pathR(G,%d)\n",x);
        dfs(x,g,passei,depth+1);
    }
}

int main(){
    int t; scanf("%d",&t);
    for(int caso = 1; caso <= t; caso++){
        printf("Caso %d:\n",caso);
        int n, m; scanf("%d%d",&n,&m);
        graph g(n+1);
        vector<bool> passei(n+1);

        for(int a, b, i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            g[a].emplace(b);
        }
        for(int i=0;i<n;i++) 
            if(!passei[i] && g[i].size() > 0){
                dfs(i,g,passei);
                printf("\n");
            }
    }
}