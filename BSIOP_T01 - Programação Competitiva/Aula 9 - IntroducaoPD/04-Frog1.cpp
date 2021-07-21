//Link da questao
//https://atcoder.jp/contests/dp/tasks/dp_a
#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MOD = ((int)1e9+7);

int main(){
    ios_base::sync_with_stdio(0);
    int n; scanf("%d",&n);
    vector<int> v(n); for(int &x : v)scanf("%d",&x);
    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = abs(v[1]-v[0]);
    for(int i=2;i<n;i++){
        //Estando no passo i, eu tento ir pra i-1 ou i-2, o que tiver menor custo total eu escolho
        dp[i] = min(dp[i-1] + abs(v[i]-v[i-1]), dp[i-2] + abs(v[i]-v[i-2]));
    }
    printf("%d\n",dp[n-1]);
}