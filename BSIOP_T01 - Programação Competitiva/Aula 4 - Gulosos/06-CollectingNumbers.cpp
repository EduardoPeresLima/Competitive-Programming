//Link da questao
//https://cses.fi/problemset/task/2216
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x; scanf("%d", &n);
    vector<int> id(1+n);
    for(int val,i=0;i<n;i++){
        scanf("%d",&val);
        id[val] = i+1;
    }
    int ans = 1;
    for(int i=1;i<=n;i++){
        if(id[i] < id[i-1])ans++;
    }
    printf("%d\n", ans);
}