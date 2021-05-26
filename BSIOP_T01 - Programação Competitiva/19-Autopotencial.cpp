//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/2505
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll bpow(ll a, ll b, ll mod){
    ll ans = 1;
    while(b){
        if(b&1)ans = ans*a % mod;
        a = a*a % mod;
        b>>=1;
    }
    return ans;
}

int main(){
    ll n;
    while(scanf("%lld",&n)!=EOF){
        ll x = n;
        ll pow_10 = 10;
        while(x/=10)pow_10*=10;
        printf("%s\n",bpow(n,n,pow_10) == n?"SIM":"NAO");
    }
}