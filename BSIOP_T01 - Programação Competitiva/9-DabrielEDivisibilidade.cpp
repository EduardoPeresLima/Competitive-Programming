//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/2946
#include<bits/stdc++.h>
using namespace std;
inline void reads(string &x){char _[100005]; scanf("%s",_);x=_;}

bool restoDaDivisao(string &s, int m){
    int resto = 0;
    for(char c : s){
        resto = (resto * 2 + c-'0')%m;
    }
    return resto;
}

int main(){
    string s; reads(s);
    int m; scanf("%d",&m);
    vector<int> ans;
    for(int val,i=0;i<m;i++){
        scanf("%d",&val);
        if(restoDaDivisao(s,val) == 0)ans.emplace_back(val);
    }
    if(ans.size() == 0)printf("Nenhum\n");
    else{
        sort(ans.begin(),ans.end());
        printf("%d",ans[0]);
        for(int i=1;i<ans.size();i++)printf(" %d",ans[i]);
        printf("\n");
    }
}