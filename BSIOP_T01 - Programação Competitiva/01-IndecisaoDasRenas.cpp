//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/2721
#include<bits/stdc++.h>
using namespace std;

string renas[] = {"Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen", "Rudolph"};

int main(){
    int sum = 0, val;
    for(int i=0;i<9;i++){
        scanf("%d",&val);
        sum+=val;
    }
    printf("%s\n",renas[(sum-1)%9].data());
}