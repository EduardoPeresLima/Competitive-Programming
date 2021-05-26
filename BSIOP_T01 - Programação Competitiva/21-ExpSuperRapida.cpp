//Link da questao
//https://neps.academy/br/exercise/1353
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
    ll base = 0, ans = 1, m;
    string b, e; reads(b); reads(e); scanf("%lld",&m);
    for(char c : b)base = (base*10 + c-'0')%m;
    for(char c : e)ans = bpow(ans,10,m) * bpow(base,c-'0',m) % m;
    printf("%lld\n",ans);
}