//Link da questao
//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1626
#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MOD = ((int)1e9+7);
inline void reads(string &x){char c[50]; scanf("%s",c);x=c;}


int c, r;
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


int main(){
    ios_base::sync_with_stdio(0);
    while(scanf("%d%d",&c,&r) && (c||r)){
        pai.assign(c,0);
        tam.assign(c,1);
        iota(pai.begin(),pai.end(),0); //sequencia iniciando em 0 -> 0,1,2,3...
        string s, sa, sb;
        map<string,int> index;
        for(int i=0;i<c;i++){
            reads(s);
            index[s] = i;
        }

        for(int a,b,i=0;i<r;i++){
            reads(sa); reads(sb);
            a = index[sa], b = index[sb];
            join(a,b);
        }
        int ans = 0;
        for(int i=0;i<c;i++)ans = max(ans,tam[i]);
        printf("%d\n",ans);
    }
}