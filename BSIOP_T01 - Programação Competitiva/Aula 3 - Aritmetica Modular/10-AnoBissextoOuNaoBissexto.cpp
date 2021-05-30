//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1279
#include<bits/stdc++.h>
using namespace std;
inline int reads(string &x){char _[100005]; int r = scanf("%s",_);x=_; return r;}

int main(){
    string s;
    int index = 0;
    while(reads(s)!=EOF){
        if(index++ != 0)printf("\n");
        int r4 = 0, r100 = 0, r400 = 0;
        int r15 = 0, r55 = 0;
        for(char c : s){
            r4 = (r4*10 + c-'0')%4;
            r100 = (r100*10 + c-'0')%100;
            r400 = (r400*10 + c-'0')%400;
            
            r15 = (r15*10 + c-'0')%15;
            r55 = (r55*10 + c-'0')%55;
        }
        bool bissexto = (r400 == 0 || (r4 == 0 && r100 != 0));
        bool huluculu = (r15 == 0);
        bool bulukulu = (bissexto && r55==0);
        if(bissexto || huluculu || bulukulu){   
            if(bissexto)printf("This is leap year.\n");
            if(huluculu)printf("This is huluculu festival year.\n");
            if(bulukulu)printf("This is bulukulu festival year.\n");
        }
        else printf("This is an ordinary year.\n");
    }
}