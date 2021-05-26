//Link da questao
//https://neps.academy/br/exercise/266
#include<bits/stdc++.h>
using namespace std;
inline void reads(string &x){char _[100005]; scanf("%s",_);x=_;}

bool restoDaDivisao(string &s, int m){
    int n = s.size();
    int resto = 0;
    for(int i=0;i<n;i++){
        resto = (resto * 10 + s[i]-'0')%m;
    }
    return resto;
}

int main(){
    string s;reads(s);
    int r2 = restoDaDivisao(s,2);
    int r3 = restoDaDivisao(s,3);
    int r5 = restoDaDivisao(s,5);

    printf("%c\n",r2==0?'S':'N');
    printf("%c\n",r3==0?'S':'N');
    printf("%c\n",r5==0?'S':'N');
}