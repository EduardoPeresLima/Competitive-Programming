//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/2858
//kkkk levilliam ai sim
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll inv_mod(ll a, ll b){
    return (a > 1 ? b-inv_mod(b%a, a)*b/a : 1);
}
int main(){
    ll a, b; scanf("%lld%lld",&a,&b);
    ll g = __gcd(a,b);
    if(g!=1){
        printf("IMPOSSIVEL\n");
        return 0;
    }
    ll inva = inv_mod(a,b), invb = inv_mod(b,a);
    printf("%lld\n",min(inva + (inva*a-1)/b, invb + (invb*b-1)/a));

}