//Link da questao
//https://codeforces.com/contest/1493/submission/117882353
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m; scanf("%d%d", &n,&m);
    vector<int> ans;
    for(int i=(m+1)/2;i<=n;i++){
        if(i==m)continue;
        ans.emplace_back(i);
    }
    printf("%d\n",(int)ans.size());
    for(int x : ans)printf("%d ",x);printf("\n");
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int t = 1; scanf("%d",&t);
    for(int caso=1;caso<=t;caso++){
        solve();
    }
}