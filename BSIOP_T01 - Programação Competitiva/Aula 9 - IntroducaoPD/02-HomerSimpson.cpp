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
        if(n<m)swap(m,n); //pao do tipo 1 sempre vai ser mais rapido de comer que o do tipo 2, pra faciliar os calculos
        //a -> qntdd de pao do tipo 1 q eu como
        //b -> qntdd de pao do tipo 2 q eu como
        //tot -> tempo total gasto pra comer os paes
        //beer -> tempo q sobra pra beber
        int a = t/m, b = 0, tot = a*m + b*n, beer = t-tot;
        int minBeer = beer, ans = a;
        //enquanto tiver tempo pra beber, eu diminuo a qntdd de pao 1 q eu como
        //e se der, como pao do tipo 2, dai vejo o tempo q sobra pra beber,
        //se o tempo for menor, eu escolho essa como nova resposta
        //se o tempo for o msm, eu escolho a maior qntdd de pao q der p comer
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