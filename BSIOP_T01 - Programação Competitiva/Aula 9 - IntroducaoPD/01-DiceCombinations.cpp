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
    for(int i=1;i<=n;i++){//Qual a resposta para "i" lancamentos de dados?
        for(int j=i-6;j<i;j++){ //Comentario mais abaixo
            if(j>=0)dp[i] += dp[j];
            if(dp[i]>MOD)dp[i]-=MOD;
        }
    }
    printf("%d\n",dp[n]);


    //Continua aqui
    //Pra conseguir lancar n=10, por exemplo
    //Pego a resposta pra n=4 e lanco um dado com lado 6, somando 10
    //Ou   a resposta pra n=5 e lanco um dado com lado 5, somando 10
    //...
    //Ou seja,  soma os valores do range [n-6,n-1], se forem >=0 claro
}