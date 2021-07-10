//Link da questao
//https://cses.fi/problemset/task/1671
#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const ll INF = 1e18+7;
typedef vector<vector<pair<ll,ll>>> graph;

int n, m;
graph g;

vector<ll> dijkstra(int ini){
    priority_queue<pair<ll,ll>> q;
    vector<ll> dist(n+1,INF);
    ll viz, vizD;
    ll no, noD;

    q.emplace(0,ini);
    while(!q.empty()){
        tie(noD, no) = q.top(); q.pop();
        if(dist[no] != INF)continue;
        dist[no] = noD;
        for(auto next : g[no]){
            tie(viz,vizD) = next;
            q.emplace(dist[no] - vizD,viz);
        }
    }
    return dist;
}

int main(){
    ios_base::sync_with_stdio(0);
    scanf("%d%d",&n,&m);
    g.assign(n+1,vector<pair<ll,ll>>());
    for(int a,b,c,i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        g[a].emplace_back(b,c);
    }
    vector<ll> dist = dijkstra(1);
    for(int i=1;i<=n;i++)printf("%lld ",-dist[i]);
    printf("\n");
}