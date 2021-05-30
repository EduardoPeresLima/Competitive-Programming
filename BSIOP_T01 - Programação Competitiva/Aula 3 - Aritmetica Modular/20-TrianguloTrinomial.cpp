//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1807
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
    ll n;scanf("%lld",&n);
    
    printf("%lld\n",bpow(3,n,(1LL<<31)-1));
    
}