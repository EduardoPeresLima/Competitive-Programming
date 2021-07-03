//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1583
#include<bits/stdc++.h>
using namespace std; 
typedef vector<string> graph;
inline void reads(string& x){char kk[2004]; scanf("%s",kk); x = kk;}
int n, m, dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};


bool out(int i, int j){
    return i<0 || i>=n || j<0 || j>=m;
}

void bfs(int i, int j, graph &g){
    queue<pair<int,int>> q;
    q.emplace(i,j);
    g[i][j] = 'T'; //marcar que ja passei
    while(!q.empty()){
        tie(i,j)= q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int ni = i + dx[k], nj = j + dy[k];
            if(out(ni,nj) || g[ni][nj] != 'A')continue;
            g[ni][nj] = 'T'; //marcar que ja passei/coloquei na fila
            q.emplace(ni,nj);
        }
    }
    
}

int main(){
    while(scanf("%d%d",&n,&m) && (n||m)){
        graph g(n); for(int i=0;i<n;i++)reads(g[i]);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(g[i][j] == 'T')
                    bfs(i,j,g);
        for(int i=0;i<n;i++)printf("%s\n",g[i].data());
        printf("\n");
    }
}