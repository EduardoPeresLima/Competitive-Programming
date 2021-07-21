//Link da questao
//https://cses.fi/problemset/task/1633
#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MOD = ((int)1e9+7);

int main(){
    ios_base::sync_with_stdio(0);
    int n; scanf("%d",&n);
    vector<int> dp(n+1);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=i-6;j<i;j++){
            if(j>=0)dp[i] += dp[j];
            if(dp[i]>MOD)dp[i]-=MOD;
        }
    }
    printf("%d\n",dp[n]);

}