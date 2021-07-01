//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1308
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        ll n; scanf("%lld",&n);
        ll lo = 1, hi = 2e9+7, mid;
        while(lo < hi){
            mid = lo + ((hi-lo)>>1);
            if(mid * (mid+1) > 2*n)hi = mid;
            else lo = mid+1;
        }
        printf("%lld\n",lo-1);
    }
}