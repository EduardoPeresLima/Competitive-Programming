//Link da questao
//https://codeforces.com/problemset/problem/1006/C
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n; scanf("%d",&n);
    vector<ll> v(n+2),s(n+2);
    ll ans = 0, tot = 0, sum = 0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i]);
        tot += v[i];
    }
    for(int i=n;i>0;i--)s[i] = v[i] + s[i+1];

    for(int i=1;i<=n;i++){
        sum += v[i];
        if(sum + sum > tot)break;
        if(binary_search(++s.rbegin(),--s.rend(),sum))ans = sum;
    }
    printf("%lld\n",ans);
}