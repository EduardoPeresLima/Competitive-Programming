//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/2828
#include<bits/stdc++.h>
using namespace std;
#define N 100'005
inline int reads(string &x){char _[N]; int r = scanf("%s",_);x=_; return r;}
typedef long long ll;
#define MOD (ll)(1e9+7)

ll inv_mod(ll a, ll b){
    return (a > 1 ? b-inv_mod(b%a, a)*b/a : 1);
}
int main(){
    vector<ll> fat(N);
    fat[0] = 1;
    for(ll i=1;i<N;i++)fat[i] = fat[i-1]*i % MOD;
    string s;
    reads(s);
    vector<int> f(30);
    for(char c : s)f[c-'a']++;
    ll ans = fat[s.size()];
    for(int i=0;i<30;i++)ans = (ans * inv_mod(fat[f[i]],MOD)) % MOD;
    printf("%lld\n",ans);
}