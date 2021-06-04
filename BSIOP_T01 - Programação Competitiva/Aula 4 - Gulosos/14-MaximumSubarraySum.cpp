//Link da questao
//https://cses.fi/problemset/task/1643/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n; scanf("%d",&n);
    vector<ll> v(n); for(ll &x : v)scanf("%lld",&x);
    ll ans = LLONG_MIN, men = 0, sum = 0;
    for(int i=0;i<n;i++){
        sum += v[i];
        ans = max(ans,sum-men);
        men = min(men,sum);
    }
    printf("%lld\n",ans);
}