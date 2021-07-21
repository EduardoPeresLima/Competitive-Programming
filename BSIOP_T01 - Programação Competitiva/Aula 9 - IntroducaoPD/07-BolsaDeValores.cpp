//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1932
#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MOD = ((int)1e9+7);

int main(){
    ios_base::sync_with_stdio(0);
    int n, c; scanf("%d%d",&n,&c);
    vector<int> v(n); for(int &x : v)scanf("%d",&x);
    vector<vector<int>> dp(n+1,vector<int>(2));
    // dp[i][0] nao investindo no momento
    // dp[i][1] investindo agora
    dp[0][1] = -c - v[0];
    for(int i=1;i<n;i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + v[i]); //continuo no msm estado de antes, ou tinha comprado e agora vendi
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - c - v[i]); //continuo com o msm investimento de antes, ou finjo que nao investi antes e começo a investir agr
    }
    printf("%d\n",max({dp[n-1][0], dp[n-1][1],0}));
}