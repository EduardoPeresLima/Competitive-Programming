//Link da questao
//https://atcoder.jp/contests/dp/tasks/dp_b 
#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MOD = ((int)1e9+7);

int main(){
    ios_base::sync_with_stdio(0);
    int n, k; scanf("%d%d",&n,&k);
    vector<int> v(n); for(int &x : v)scanf("%d",&x);
    vector<int> dp(n,1e9);
    dp[0] = 0;
    for(int i=1;i<n;i++){
        //Estando no passo i, eu tento ir pra [i-1 .. i-k], o que tiver menor custo total eu escolho
        for(int j=max(i-k,0);j<i;j++){
            dp[i] = min(dp[i],dp[j] + abs(v[i]-v[j]));
        }
    }
    printf("%d\n",dp[n-1]);
}