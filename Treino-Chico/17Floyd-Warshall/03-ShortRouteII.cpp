#include<bits/stdc++.h>
using namespace std;

inline void reads(){}
template<typename First, typename ... Strings> inline void reads(First x, const Strings&... rest){char kk[200'123]; scanf("%s",kk); x = kk;reads(rest...);}

const int MOD = 1'000'000'007;
typedef long long       ll;

int main(){
    int n,m,q; scanf("%d%d%d", &n,&m,&q);
    vector<vector<ll>> g(n+2,vector<ll>(n+2,LLONG_MAX));
    for(int i=0;i<m;i++){
        int a, b, c; scanf("%d%d%d",&a,&b,&c);
        g[a][b] = min(g[a][b],(ll)c);
        g[b][a] = min(g[b][a],(ll)c);
    }
    for(int i=1;i<=n;i++)g[i][i] = 0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(g[i][k] != LLONG_MAX && g[k][j] != LLONG_MAX)
                    g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for(int i=0;i<q;i++){
        int a, b; scanf("%d%d",&a,&b);
        printf("%lld\n",g[a][b] == LLONG_MAX?-1:g[a][b]);
    }
}