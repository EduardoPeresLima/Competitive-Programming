//Link da questao
//https://cses.fi/problemset/task/1669
#include<bits/stdc++.h>
using namespace std; 
typedef vector<vector<int>> graph;

int dfs(int no, graph &g, vector<int> &pai, int parent = -1){
    int id = -1;
    for(int x : g[no]){
        if(x == parent)continue;
        bool temPai = pai[x] != -1;
        pai[x] = no;
        if(temPai)return x;
        id = dfs(x,g,pai,no);
        if(id != -1)return id;
    }
    return id;
}

int main(){
    int n, m; scanf("%d%d",&n,&m);
    graph g(n+1); vector<int> pai(n+1,-1);
    for(int a,b,i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int id = -1;
    for(int i=1;i<=n;i++){
        if(pai[i] != -1)continue;
        id = dfs(i,g,pai);
        if(id != -1)break;
    }
    if(id == -1)printf("IMPOSSIBLE");
    else{
        vector<int> ans = {id};
        int cur = pai[id];
        while(cur != id){
            ans.emplace_back(cur);
            cur = pai[cur];
        }
        ans.emplace_back(id);
        printf("%d\n",(int)ans.size());
        for(int x : ans)printf("%d ",x);printf("\n");
    }
}