//Link da questao
//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1406
#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MOD = ((int)1e9+7);

int main(){
    ios_base::sync_with_stdio(0);
    int m, n, t;
    while(scanf("%d%d%d",&m,&n,&t) != EOF){
        if(n<m)swap(m,n);

        int a = t/m, b = 0, tot = a*m, beer = t-tot;
        int minBeer = beer, ans = a;
        while(a-- && minBeer){
            
            b = (t-a*m)/n;
            tot = a*m + b*n;
            beer = t-tot;
            if(beer < minBeer){
                minBeer = beer;
                ans = a+b;
            }
            else if(beer == minBeer)ans = max(ans,a+b);
        }
        if(minBeer)printf("%d %d\n",ans,minBeer);
        else printf("%d\n",ans);
    }
}