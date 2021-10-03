#include<bits/stdc++.h>
using namespace std;

inline void reads(){}
template<typename First, typename ... Strings> inline void reads(First x, const Strings&... rest){char kk[200'123]; scanf("%s",kk); x = kk;reads(rest...);}

const int MOD = 1'000'000'007;
typedef long long       ll;

int main(){
    int n,m; scanf("%d%d", &n,&m);
    vector<vector<int>> g(n+2,vector<int>(n+2,MOD));
    for(int i=0;i<m;i++){
        int a, b, c; scanf("%d%d%d",&a,&b,&c);
        g[a][b] = g[b][a] = c;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(g[i][k] != MOD && g[k][j] != MOD)
                    g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    printf("%d\n",g[1][n]);
}