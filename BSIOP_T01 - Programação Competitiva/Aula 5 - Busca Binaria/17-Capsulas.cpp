//Link da questao
//https://neps.academy/br/exercise/205
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, f;
vector<ll> v;
bool fb(ll x){
    ll cont = 0;
    for(ll y : v)cont += x/y;
    return cont < f;
}

int main(){
    scanf("%lld%lld",&n,&f);
    v.assign(n,0); for(ll &x : v)scanf("%lld",&x);
    ll lo = 1, hi = 1e16, mid;
    while(lo < hi){
        mid = lo + ((hi-lo)>>1);
        if(fb(mid))lo = mid+1;
        else hi = mid;
    }
    printf("%lld\n",lo);
}