//Link da questao
//https://neps.academy/br/exercise/183
#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
#define INF ((int)1e9+7)
typedef vector<vector<pair<int,int>>> graph;

int n, m, s;
graph g;

int dijkstra(int ini){
    priority_queue<pair<int,int>> q;
    vector<int> dist(n+1,INF);
    int viz, vizD;
    int no, noD;
    int mai = 0, men = INF;

    q.emplace(0,ini);
    while(!q.empty()){
        tie(noD, no) = q.top(); q.pop();
        if(dist[no] != INF)continue;
        dist[no] = noD;

        if(no != ini){
            mai = max(mai,-noD);
            men = min(men,-noD);
        }
        for(auto next : g[no]){
            tie(viz,vizD) = next;
            q.emplace(dist[no] - vizD,viz);
        }
    }
    return mai - men;
}

int main(){
    ios_base::sync_with_stdio(0);
    scanf("%d%d",&n,&m);
    g.assign(n+1,vector<pair<int,int>>());
    for(int a,b,c,i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }
    scanf("%d",&s);
    printf("%d\n",dijkstra(s));
}