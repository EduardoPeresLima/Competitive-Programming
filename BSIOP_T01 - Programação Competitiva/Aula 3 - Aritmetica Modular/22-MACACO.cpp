//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/2681
//EH O MACACO, MACACO, MACAAAAACOOOOOOOOOO
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
inline int reads(string &x){char _[100005]; int r = scanf("%s",_);x=_; return r;}

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
    string n; reads(n);
    ll mod = 24*60*60;
    ll s = 1;
    for(char c : n) s = bpow(s,10,mod) * bpow(2,c-'0',mod) % mod;
    s = (s - 1 + mod)%mod;
    ll h = s/3600; s%=3600;
    ll m = s/60; s%=60; 
    printf("%02lld:%02lld:%02lld\n",h,m,s);
}