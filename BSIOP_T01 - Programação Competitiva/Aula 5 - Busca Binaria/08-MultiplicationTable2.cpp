//Link da questao
//https://codeforces.com/problemset/problem/448/D
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, k;

ll f(ll x){
    ll cont = 0;
    for(ll i = 1; i<=n;i++){
        cont += min(m,x/i);
    }
    return cont;
}

int main(){
    scanf("%lld%lld%lld",&n,&m,&k);
    ll lo = 1, hi = n*m, mid;
    while(lo<hi){
        mid = lo + ((hi-lo)>>1);
        if(f(mid) < k) lo = mid+1;
        else hi = mid;
    }    
    printf("%lld\n",lo);
}