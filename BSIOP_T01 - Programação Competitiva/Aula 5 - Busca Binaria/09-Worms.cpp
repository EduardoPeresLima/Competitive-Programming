//Link da questao
//https://codeforces.com/problemset/problem/474/B
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n; scanf("%d",&n);
    vector<int> v(n); for(int &x : v)scanf("%d",&x);
    for(int i=1;i<n;i++)v[i] += v[i-1];
    int m; scanf("%d",&m);
    for(int x, i=0;i<m;i++){
        scanf("%d",&x);
        printf("%d\n", lower_bound(v.begin(),v.end(),x) - v.begin() + 1);
    }
}