//Link da questao
//https://cses.fi/problemset/task/1637
#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MOD = ((int)1e9+7);

int main(){
    ios_base::sync_with_stdio(0);
    int n; scanf("%d",&n);
    vector<int> dp(n+1, MOD); dp[0] = 0;
    for(int i=1;i<=n;i++){
        int x = i;
        while(x){
            dp[i] = min(dp[i],dp[i-x%10]+1);
            x/=10;
        }
    }
    printf("%d\n",dp[n]);
}