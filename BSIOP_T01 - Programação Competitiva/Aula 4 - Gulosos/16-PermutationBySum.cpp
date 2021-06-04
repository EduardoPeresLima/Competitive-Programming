//Link da questao
//https://codeforces.com/contest/1512/problem/E
#include<bits/stdc++.h>
using namespace std;

int sum(int x){
    return (x*(x+1))/2;
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,l,r,s;scanf("%d%d%d%d",&n,&l,&r,&s);
        int x = r-l+1;
        if(s < sum(x) || s > sum(n) - sum(n-x)){
            printf("-1\n");
            continue;
        }
        vector<int> ans(n);l--,r--; 
        int add = (s - sum(x))/x;
        int resto = (s-sum(x))%x;
        set<int> used;
        for(int i=l;i<=r;i++){
            ans[i] = (i-l+1) + add;
        }
        for(int i=r;i>l && resto > 0; i--){
            ans[i]++;
            resto--;
        }
        for(int i=l;i<=r;i++)used.emplace(ans[i]);
        for(int i=0,val=1;i<n;i++){
            if(ans[i] != 0)continue;
            while(used.find(val) != used.end())val++;
            ans[i] = val;
            val++;
        }
        for(int x : ans)printf("%d ",x);printf("\n");
    }
}