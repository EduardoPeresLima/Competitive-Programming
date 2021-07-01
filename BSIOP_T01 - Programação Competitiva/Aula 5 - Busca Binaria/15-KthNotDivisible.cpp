//Link da questao
//https://codeforces.com/problemset/problem/1352/C
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
bool f(ll x){
    return (x - x/n) < k;
}

ll bb(){
    ll lo = 1, mid, hi = LLONG_MAX;
    for(int i=0;i<100;i++){
        mid = lo + ((hi-lo)>>1);
        if(f(mid))lo = mid+1;
        else hi = mid;
    }
    return lo;
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        printf("%lld\n",bb());
    }
}