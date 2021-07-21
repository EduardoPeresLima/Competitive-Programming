//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1689
#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MOD = ((int)1e9+7);

int main(){
    ios_base::sync_with_stdio(0);
    int t; scanf("%d",&t);
    while(t--){
        int n, k; scanf("%d%d",&n,&k);
        vector<int> v(n); for(int &x : v)scanf("%d",&x);
        vector<int> a(n); for(int &x : a)scanf("%d",&x);
        int maior = v.back();
        v.emplace_back(MOD);
        vector<int> dp(maior+1);
        for(int i=0,j=1;j<=maior;){
            if(j<v[i]){
                dp[j] = max(dp[j],dp[j-1]);
                j++;
            }
            else{
                dp[j] = max(dp[j],dp[max(0,j-k)]+a[i]);
                i++;
            }
        }
        printf("%d\n",dp[maior]);
    }
}