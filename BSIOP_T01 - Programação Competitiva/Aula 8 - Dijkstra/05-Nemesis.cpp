//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1972
#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
typedef pair<int,int>       ii;
#define MOD ((int)1e9+7)
typedef vector<string> graph;
inline void reads(string &x){char c[1003]; scanf("%s",c);x=c;}
int n, m, dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
graph g;

bool out(int i, int j){
    return i<0 || i>=n || j<0 || j>=m;
}

int dijkstra(ii a, ii b){
    priority_queue<tuple<int,int,int>> q;
    vector<vector<int>> d(n,vector<int>(m,MOD));
    q.emplace(0,a.first,a.second);
    d[a.first][a.second] = 0;
    int dist, i, j;
    while(!q.empty()){
        tie(dist,i,j) = q.top(); q.pop();
        dist = -dist;
        for(int ni,nj,k=0;k<4;k++){
            ni = i+dx[k], nj = j+dy[k];
            if(out(ni,nj) || g[ni][nj] == '#' || d[ni][nj] <= dist)continue;
            char c = g[ni][nj];
            d[ni][nj] = dist;
            if(c == 'E')continue;
            int preco = c == '.'? 0: c - '0';
            q.emplace(- (dist + preco),ni,nj);
        }
    }
    return d[b.first][b.second];
}

int main(){
    ios_base::sync_with_stdio(0);
    scanf("%d%d",&n,&m);
    g.assign(n,"");
    ii ini, fim;
    for(int i=0;i<n;i++){
        reads(g[i]);
        for(int j=0;j<m;j++) {
            if(g[i][j] == 'H')ini = {i,j};
            if(g[i][j] == 'E')fim = {i,j};
        }
    }
    int ans = dijkstra(ini,fim);
    if(ans == MOD) printf("ARTSKJID\n");
    else printf("%d\n",ans);
}