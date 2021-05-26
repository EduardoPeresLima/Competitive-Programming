//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/2801
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll inv_mod(ll a, ll b){
    return (a > 1 ? b-inv_mod(b%a, a)*b/a : 1);
}
//(a*x + b)%t = c%t
//(a*x)%t = (c-b)%t
//x = ((c-b)/a)%t
ll f(ll a, ll b, ll c, ll t){
    return ((c-b + t)%t * inv_mod(a,t))%t;
}

int main(){
    ll n,t,a,b; scanf("%lld",&n);
    vector<ll> m(n); for(ll &x : m)scanf("%lld",&x);
    scanf("%lld%lld%lld",&t,&a,&b);
    if(__gcd(a,t) != 1){
        printf("DECIFRAGEM AMBIGUA\n");
        return 0;
    }
    a%=t, b%=t;
    printf("%lld",f(a,b,m[0],t));
    for(int i=1;i<n;i++)printf(" %lld",f(a,b,m[i],t));
    printf("\n");

}