//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1862
#include<bits/stdc++.h>
using namespace std; 
typedef vector<string> graph;
inline void reads(string& x){char kk[2004]; scanf("%s",kk); x = kk;}

int main(){
    int n; scanf("%d",&n);
    graph g(n); for(string &s : g)reads(s);
    bool can = true;
    vector<int> ans, passei(n);
    for(int i=0;i<n;i++){
        if(passei[i])continue;
        int cont = 0;
        for(int j=0;j<n;j++){
            if(g[i][j] == 'D')continue;
            passei[j] = true;
            can &= g[i]==g[j];
            cont++;
        }
        ans.emplace_back(cont);
    }
    if(can){
        sort(ans.rbegin(),ans.rend());
        printf("%d\n",(int)ans.size());
        printf("%d", ans[0]);
        for(int i=1;i<ans.size();i++)printf(" %d",ans[i]);
        printf("\n");
    }
    else printf("-1\n");
}