//Link da questao
//https://cses.fi/problemset/task/1635
#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MOD = ((int)1e9+7);

int main(){
    ios_base::sync_with_stdio(0);
    int n, x; scanf("%d%d",&n,&x);
    vector<int> moedas(n); for(int &val : moedas)scanf("%d",&val);
    vector<int> dp(x+1,MOD);
    dp[0] = 0;
    for(int i=1;i<=x;i++){// Qual a resposta pra soma ser "i"?
        for(int c : moedas){
            if(i - c >= 0)dp[i] = min(dp[i],dp[i - c] + 1);
        }
    }
    printf("%d\n",dp[x]==MOD?-1:dp[x]);
}