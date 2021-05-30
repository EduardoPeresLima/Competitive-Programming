//Link da questao
//https://neps.academy/br/exercise/496
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int l, n; scanf("%d%d",&l,&n);
    ll ans = l-n+1;
    ans = ans*ans + n-1;
    printf("%lld\n",ans);
}