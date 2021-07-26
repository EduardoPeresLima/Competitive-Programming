//Link da questao
//https://neps.academy/br/exercise/512
#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MOD = ((int)1e9+7);

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
    pai.assign(n+1,0);
    iota(pai.begin(),pai.end(),0); //sequencia iniciando em 0 -> 0,1,2,3...
    for(int a,b,i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        join(a,b);
    }
    set<int> ans;
    for(int i=1;i<=n;i++)ans.emplace(id(i));
    printf("%d\n",(int)ans.size());
}