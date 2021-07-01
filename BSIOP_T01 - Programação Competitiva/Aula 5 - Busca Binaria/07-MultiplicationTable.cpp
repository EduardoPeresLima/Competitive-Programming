//Link da questao
//https://cses.fi/problemset/task/2422
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

ll f(ll x){
    ll cont = 0;
    for(ll i = 1; i<=n;i++){
        cont += min(n,x/i);
    }
    return cont;
}

int main(){
    scanf("%lld",&n);
    ll lo = 1, hi = n*n, mid, mediana = ((n*n)>>1) + 1;
    while(lo<hi){
        mid = lo + ((hi-lo)>>1);
        if(f(mid) < mediana) lo = mid+1;
        else hi = mid;
    }    
    printf("%lld\n",lo);
}