//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1940
#include<bits/stdc++.h>
using namespace std;

int main(){
    int j, r; scanf("%d%d",&j,&r);
    vector<int> v(j,0);
    int n = j*r;
    for(int val,i=0;i<n;i++){
        scanf("%d",&val);
        v[i%j] += val;
    }
    int winner = 0;
    for(int i=0;i<j;i++){
        if(v[i]>=v[winner])winner = i;
    }
    printf("%d\n",winner+1);
}