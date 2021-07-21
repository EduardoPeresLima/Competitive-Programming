//Link da questao
//https://cses.fi/problemset/task/1635
#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MOD = 1e9+7;
int dp[102][1'000'006];
int main(){
    ios_base::sync_with_stdio(0);
    int n, x; scanf("%d%d",&n,&x);
    vector<int> moedas(n); for(int &val : moedas)scanf("%d",&val);
    sort(moedas.begin(),moedas.end());
   
    for(int i=0;i<n;i++)dp[i][0] = 1;
    for(int i=n-1;i>=0;i--){// Qual a resposta pra soma ser "i"?
        for(int j=1;j<=x;j++){
            if(j - moedas[i] < 0)continue;
            dp[i][j] += dp[i+1][j] + dp[i][j-moedas[i]];
            if(dp[i][j] >= MOD)dp[i][j] -= MOD;
        }
    }
    printf("%d\n",dp[0][x]);
}