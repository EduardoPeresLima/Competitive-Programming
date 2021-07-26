//Link da questao
//https://neps.academy/br/exercise/298
#include<iostream>
#include<vector>
#include<numeric> //iota
#include<algorithm>
#include<tuple>
using namespace std;
typedef vector<vector<pair<int,int>>> graph;
const int MOD = ((int)1e9+7);
typedef long long       ll;

int n, m;
vector<int> pai;
int id(int u){
    return pai[u] = u == pai[u]?u:id(pai[u]);
}
void join(int u, int v){
    u = id(u), v = id(v);
    if(u==v)return;
    pai[u] = v;
}

int main(){
    ios_base::sync_with_stdio(0);
    scanf("%d%d",&n,&m);
    pai.assign(n+1,0); iota(pai.begin(),pai.end(),0);
    vector<tuple<int,int,int>> edges;
    int a,b,dist;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&dist);
        edges.emplace_back(dist,a,b);
    }
    sort(edges.begin(),edges.end());
    int ans = 0;
    for(auto x : edges){
        tie(dist,a,b) = x;
        if(id(a) == id(b))continue;
        join(a,b);
        ans += dist;
    }
    printf("%d\n",ans);
}