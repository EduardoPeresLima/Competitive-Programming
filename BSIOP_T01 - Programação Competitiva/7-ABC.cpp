//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/2336
#include<bits/stdc++.h>
typedef long long ll;
#define MOD 1'000'000'007
using namespace std;
inline int reads(string &x){char _[100005]; int r = scanf("%s",_);x=_; return r;}

int main(){
    string s;
    while(reads(s)!= EOF){
        ll val = 0;
        for(char c : s){
            val = (val*26 + c-'A')%MOD;
        }
        printf("%lld\n",val);
    }
}