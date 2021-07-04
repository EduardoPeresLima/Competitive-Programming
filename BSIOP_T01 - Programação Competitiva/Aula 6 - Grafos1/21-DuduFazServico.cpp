//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1610
#include<bits/stdc++.h>
using namespace std; 
typedef vector<vector<int>> graph;

int n, m;
bool topSort(graph &g, vector<int> grau){
    queue<int> q;
    for(int i=1;i<=n;i++)if(grau[i] == 0)q.push(i);
    while(!q.empty()){
        int no = q.front();
        q.pop();
        for(int viz : g[no]){
            grau[viz]--;
            if(grau[viz] == 0)q.push(viz);
        }
    }
    for(int i=1;i<=n;i++)if(grau[i] != 0)return true;
    return false;
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d%d", &n,&m);
        graph g(n+1);
        vector<int> grau(n+1);
        for(int a,b,i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            g[b].push_back(a);
            grau[a]++;
        }
        printf("%s\n", topSort(g,grau)?"SIM":"NAO");
    }
}