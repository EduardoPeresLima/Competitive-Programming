//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1689
#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MOD = ((int)1e9+7);

int main(){
    ios_base::sync_with_stdio(0);
    int t; scanf("%d",&t);
    while(t--){
        int n, k; scanf("%d%d",&n,&k);
        vector<int> v(n); for(int &x : v)scanf("%d",&x);
        vector<int> a(n); for(int &x : a)scanf("%d",&x);
        int maior = v.back();
        v.emplace_back(MOD);
        //Pra cada posicao da estrada, eu vejo o melhor custo até ali
        vector<int> dp(maior+1); 
        for(int i=0,j=1;j<=maior;){//Two-Pointers
            if(j < v[i]){
                //Nesse caso, tem 2 opcoes -> nao tem radar nessa posicao, ou essa posicao eh do radar anterior (i-1)
                //Se nao tiver radar aqui, ent dp[j] = dp[j-1]
                //Se tiver o radar anterior aqui, eu assumi que ele era melhor resposta, mas pode ser que nao seja, daí TALVEZ dp[j-1] seja melhor pra esse caso
                //De qualquer forma, um max() resolve o problema
                dp[j] = max(dp[j],dp[j-1]);
                j++;
            }
            else{
                //Se aqui tem um radar, eu digo que a resposta vai ser escolhendo esse radar (tem uma observação no if acima, ja que isso nao necessariamente eh vdd)
                dp[j] = max(dp[j],dp[max(0,j-k)]+a[i]);
                i++;
            }
        }
        printf("%d\n",dp[maior]);
    }
}