//Link da questao
//https://neps.academy/br/exercise/261
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; scanf("%d%d",&n,&m);
    vector<int> v(n-1); for(int &x : v)scanf("%d",&x);
    vector<int> f(n); for(int &x : f)scanf("%d",&x);
    for(int x, i=0;i<m;i++){
        scanf("%d",&x);
        printf("%d ",f[lower_bound(v.begin(),v.end(),x+1)-v.begin()]);
    }
}