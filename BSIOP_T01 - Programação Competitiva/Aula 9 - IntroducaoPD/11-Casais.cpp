//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/2939
#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MOD = ((int)1e9+7);

int main(){
    ios_base::sync_with_stdio(0);

    //Essa questao eh semelhante a encontrar de quantas formas eh possivel preencher
    //uma matrix 2xN usando apenas pecas de domino, e a reposta eh ans = fibonacci(n)
    //(assumindo que cada casal eh uma peca de domino)

    //Porem, as posicoes A1-A2 e A2-A1 de cada casal contam como diferentes, entao tem que fazer "* 2^N"
    //Alem disso, pra dois casais -> (A1-A2,B1-B2) e (B1-B2,A1-A2) tb contam como diferentes
    //Pra N casais, tem N! formas de rearranjá-los usando a msm configuracao, logo, "* N!"" tbm

    //No final fica fib(N) * N! * 2^N
    ll n; scanf("%lld",&n);
    vector<ll> fib(n+1);
    fib[0] = fib[1] = 1;
    ll fat = 1;
    ll pow2 = 1;
    for(ll i=1;i<=n;i++){
        fat = fat * i % MOD;
        pow2 = pow2 * 2 % MOD;
        if(i>1)fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }
    printf("%lld\n", (fib[n] * fat % MOD) * pow2% MOD);
}