//Link da questao
//https://codeforces.com/problemset/problem/722/C
#include<iostream>
#include<vector>
#include<numeric> //iota
#include<algorithm> //reverse
using namespace std;
const int MOD = ((int)1e9+7);
typedef long long       ll;

int n, m;
vector<ll> pai,soma;
int id(int u){
    return pai[u] = u == pai[u]?u:id(pai[u]);
}
ll join(int u, int v){
    u = id(u), v = id(v);
    pai[u] = v;
    return soma[v] += soma[u];
}

int main(){
    ios_base::sync_with_stdio(0);
    //Ideia -> https://cp-algorithms.com/data_structures/disjoint_set_union.html#toc-tgt-10
    scanf("%d",&n);
    pai.assign(n+1,0); iota(pai.begin(),pai.end(),0);
    soma.assign(n+1,0);
    vector<ll> perm(n+1);
    vector<bool> has(n+1);
    for(int i=1;i<=n;i++)scanf("%lld",&soma[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&perm[i]);

    vector<ll> ans(n+1);
    ll curAns = 0;
    for(int id,i=n;i>=1;i--){
        id = perm[i];
        ans[i] = curAns;
        has[id] = true;
        curAns = max(curAns,soma[id]);
        if(has[id-1])curAns = max(curAns,join(id,id-1));
        if(has[id+1])curAns = max(curAns,join(id,id+1));
    }
    for(int i=1;i<=n;i++)printf("%lld\n",ans[i]);
}