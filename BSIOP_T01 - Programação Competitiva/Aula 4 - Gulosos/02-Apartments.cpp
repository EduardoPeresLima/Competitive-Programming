//Link da questao
//https://cses.fi/problemset/task/1084
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    vector<int> a(n), b(m);
    for(int &x : a)scanf("%d",&x);
    for(int &x : b)scanf("%d",&x);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans = 0;
    for(int i=0,j=0;i<n;i++){
        while(j<m && b[j] < a[i] - k){
            j++;
        }
        if(j==m)continue;
        if(b[j] <= a[i] + k){
            ans++;
            j++;
        }
    }
    printf("%d\n",ans);
}