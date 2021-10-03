#include<bits/stdc++.h>
using namespace std;

inline void reads(){}
template<typename First, typename ... Strings> inline void reads(First x, const Strings&... rest){char kk[200'123]; scanf("%s",kk); x = kk;reads(rest...);}

const int MOD = 1'000'000'007;
typedef long long       ll;

int main(){
    int n,m,p; scanf("%d%d%d", &n,&m,&p);
    vector<vector<int>> g(n+2,vector<int>(n+2));
    for(int i=0;i<m;i++){
        int a, b; scanf("%d%d",&a,&b);
        g[a][b] = g[b][a] = true;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j] |= g[i][k]&g[k][j];
            }
        }
    }
    for(int i=0;i<p;i++){
        int a, b;scanf("%d%d",&a,&b);
        printf("%s\n",g[a][b]?"Lets que lets":"Deu ruim");
    }
}