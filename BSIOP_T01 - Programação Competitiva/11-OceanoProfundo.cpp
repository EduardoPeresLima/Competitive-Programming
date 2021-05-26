//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1398
#include<bits/stdc++.h>
using namespace std;
inline int reads(string &x){char _[105]; int r = scanf("%s",_);x=_; return r;}

int main(){
    string s;
    int resto = 0, primo = 131071;
    while(reads(s)!=EOF){
        for(char c : s){
            if(c == '#'){
                printf("%s\n",resto == 0?"YES":"NO");
                resto = 0;
            }
            else resto = (resto * 2 + c-'0')%primo;
        }
    }
}