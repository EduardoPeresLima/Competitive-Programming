//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1082
#include<bits/stdc++.h>
using namespace std; 
typedef vector<vector<int>> graph;

void dfs(int no, graph &g, vector<int> &passei, vector<int> &component){
    passei[no] = true;
    component.emplace_back(no);
    for(int x : g[no]){
        if(passei[x])continue;
        dfs(x,g,passei,component);
    }
}

int main(){
    int t; scanf("%d",&t);
    for(int caso = 1; caso <= t; caso++){
        printf("Case #%d:\n",caso);
        int n, m; scanf("%d%d",&n,&m);
        graph g(n+1);
        for(int i=0;i<m;i++){
            char a, b;
            scanf(" %c %c",&a,&b);
            g[a-'a'].emplace_back(b-'a');
            g[b-'a'].emplace_back(a-'a');
        }
        vector<vector<int>> ans;
        vector<int> component, passei(n+1);
        int total = 0;
        for(int i=0;i<n;i++){
            if(passei[i])continue;
            total++;
            dfs(i, g, passei, component);
            sort(component.begin(),component.end());
            ans.emplace_back(component);
            component.clear();
        }
        for(auto comp : ans){
            for(int x : comp)printf("%c,",x+'a');
            printf("\n");
        }
        printf("%d connected components\n\n",total);
    }
}