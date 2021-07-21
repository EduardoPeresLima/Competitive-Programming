//Link da questao
//https://cses.fi/problemset/task/1638
#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MOD = ((int)1e9+7);
inline void reads(string &s){char c[1003]; scanf("%s",c);s=c;}
int main(){
    ios_base::sync_with_stdio(0);
    int n; scanf("%d",&n);
    vector<string> grid(n); for(string &s : grid)reads(s);
    vector<vector<int>> dp(n,vector<int>(n));
    dp[0][0] = grid[0][0] != '*'; //Se a entrada for uma trap, ja nao tem resposta, inicia com 0
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == '*')continue;
            if(i>0)dp[i][j] += dp[i-1][j];
            if(j>0)dp[i][j] += dp[i][j-1];
            if(dp[i][j] >= MOD)dp[i][j] -= MOD;
        }
    }
    printf("%d\n",dp[n-1][n-1]);
}