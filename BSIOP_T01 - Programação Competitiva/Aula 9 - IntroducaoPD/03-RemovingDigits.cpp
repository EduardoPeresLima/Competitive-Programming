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
    for(int i=1;i<=n;i++){//Qual a resposta para o numero i?
        //Olho pra resposta de i - "um dos seus digitos"
        //Minha resposta = menor deles + 1 (+1 pq eu removo um digito pra poder chegar ao [i - "digito escolhido"])
        int x = i;
        while(x){
            dp[i] = min(dp[i],dp[i-x%10]+1);
            x/=10;
        }
    }
    printf("%d\n",dp[n]);
}