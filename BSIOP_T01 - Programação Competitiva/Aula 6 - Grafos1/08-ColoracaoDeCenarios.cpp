//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1907
#include<bits/stdc++.h>
using namespace std; 
typedef vector<string> graph;
inline void reads(string& x){char kk[2004]; scanf("%s",kk); x = kk;}
int n, m, dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

bool out(int i, int j){
    return i<0 || i>=n || j<0 || j>=m;
}

void bfs(int i, int j, graph &g){ //Nao usar DFS -> TLE, provavelmente no caso na matriz cheia de ponto -> 1e6 dfs uma chamando a outra

    queue<pair<int,int>> q;
    q.emplace(i,j);
    g[i][j] = '*'; //marcar que ja passei
    while(!q.empty()){
        tie(i,j)= q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int ni = i + dx[k], nj = j + dy[k];
            if(out(ni,nj) || g[ni][nj] == '*' || g[ni][nj] == 'o')continue;
            g[ni][nj] = '*'; //marcar que ja passei/coloquei na fila, n precisa colocar dnv, se marcar so dps de realmente passar pelo no -> MLE
            q.emplace(ni,nj);
        }
    }
    
}

int main(){
    scanf("%d%d",&n,&m);
    graph g(n); for(int i=0;i<n;i++)reads(g[i]);
    
    int ans = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(g[i][j] == '*' || g[i][j] == 'o')continue;
            bfs(i,j,g);
            ans++;
        }
    printf("%d\n",ans);
}