//Link da questao
//https://atcoder.jp/contests/dp/tasks/dp_c
#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MOD = ((int)1e9+7);

int main(){
    ios_base::sync_with_stdio(0);
    int n; scanf("%d",&n);
    vector<vector<int>> dp(n+1,vector<int>(3));
    vector<int> v(3);
    //dp[i][x] -> se eu escolher x nesse dia, nao posso ter escolhido ele no dia anterior
    //ent pego o melhor dos outros dois q sao != x e escolho pra ser o do dia anterior
    for(int i=1;i<=n;i++){
        for(int &x : v)scanf("%d",&x);
        dp[i][0] = v[0] + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = v[1] + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = v[2] + max(dp[i-1][0],dp[i-1][1]);
    }
    printf("%d\n",*max_element(dp[n].begin(),dp[n].end()));
}