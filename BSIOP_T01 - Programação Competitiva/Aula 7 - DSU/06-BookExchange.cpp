//Link da questao
//https://codeforces.com/contest/1249/problem/B2
#include<iostream>
#include<vector>
#include<numeric> //iota
using namespace std;
const int MOD = ((int)1e9+7);
typedef long long       ll;

int n, m;
vector<int> pai, tam;
int id(int u){
    return pai[u] = u == pai[u]?u:id(pai[u]);
}
void join(int u, int v){
    u = id(u), v = id(v);
    if(u==v)return;
    pai[u] = v;
    tam[v] += tam[u];
}

void solve(){
    int n; scanf("%d",&n);
    pai.assign(n,0); iota(pai.begin(),pai.end(),0);
    tam.assign(n,1);
    for(int a,i=0;i<n;i++){
        scanf("%d",&a);a--;
        join(i,a);
    }
    for(int i=0;i<n;i++)printf("%d ",tam[id(i)]);printf("\n");
}

int main(){
    ios_base::sync_with_stdio(0);
    int t; scanf("%d",&t);
    while(t--)solve();
}