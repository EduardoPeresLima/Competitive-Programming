//Link da questao
//https://codeforces.com/problemset/problem/1486/A
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n; scanf("%d", &n);
    ll val, falta = 0;
    bool can = true;
    for(ll i=0;i<n;i++){
        scanf("%lld",&val);
        if(val < i){
            ll dx = i-val;
            if(falta < dx)can = false;
            falta -= dx;
        }
        else{
            falta += val-i;
        }
    }
    printf("%s\n", can?"YES":"NO");
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int t = 1; scanf("%d",&t);
    for(int caso=1;caso<=t;caso++){
        solve();
    }
}