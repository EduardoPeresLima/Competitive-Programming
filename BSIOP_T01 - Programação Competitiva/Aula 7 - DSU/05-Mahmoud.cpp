//Link da questao
//https://codeforces.com/problemset/problem/959/B
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<numeric> //iota
using namespace std;
const int MOD = ((int)1e9+7);
typedef long long       ll;
inline void reads(string &x){char c[50]; scanf("%s",c);x=c;}

int n, k,m;
vector<int> pai, menor;
int id(int u){
    return pai[u] = u == pai[u]?u:id(pai[u]);
}
void join(int u, int v){
    u = id(u), v = id(v);
    if(u==v)return;
    pai[u] = v;
    menor[v] = min(menor[v],menor[u]);
}

int main(){
    ios_base::sync_with_stdio(0);
    scanf("%d%d%d",&n,&k,&m);

    pai.assign(n,0); iota(pai.begin(),pai.end(),0); //sequencia iniciando em 0 -> 0,1,2,3...
    menor.assign(n,0);
    map<string,int> index;
    string s;

    for(int i=0;i<n;i++) reads(s), index[s] = i;
    for(int i=0;i<n;i++) scanf("%d",&menor[i]);

    for(int a,b,i=0;i<k;i++){
        int x; scanf("%d",&x);
        scanf("%d",&a);a--;
        for(int j=1;j<x;j++){
            scanf("%d",&b);b--;
            join(a,b);
        }
    }
    ll ans = 0;
    for(int i=0;i<m;i++){
        reads(s);
        ans += menor[id(index[s])];
    }
    printf("%lld\n",ans);
}