//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1213
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        int ans = 1, val = 1%n;
        while(val){
            val = (val*10 + 1)%n;
            ans++;
        }
        printf("%d\n",ans);
    }
}