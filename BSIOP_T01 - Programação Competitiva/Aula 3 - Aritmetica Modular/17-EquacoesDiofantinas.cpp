//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1381
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N (int(2e6+10))
#define MOD 1300031

ll fat[N];

ll inv_mod(ll a, ll b){
    return (a > 1 ? b-inv_mod(b%a, a)*b/a : 1);
}
int main(){
    fat[0] = 1;
    for(ll i=1;i<N;i++)fat[i] = fat[i-1] * i % MOD;
    int t; scanf("%d",&t);
    while(t--){
        int n, c; scanf("%d%d",&n,&c);
        ll ans = fat[n+c-1];
        ans = ans*inv_mod(fat[n-1],MOD) % MOD;
        ans = ans*inv_mod(fat[c],MOD) % MOD;
        printf("%lld\n",ans);
    }
}