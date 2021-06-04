//Link da questao
//https://cses.fi/problemset/task/1090
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x; scanf("%d%d", &n,&x);
    vector<int> v(n); for(int &x : v)scanf("%d",&x);
    sort(v.begin(),v.end());
    int ans = 0;
    for(int i=0,j=n-1;i<=j;j--){
        if(v[i]+v[j]<=x)i++;
        ans++;
    }
 
    printf("%d\n", ans);
}