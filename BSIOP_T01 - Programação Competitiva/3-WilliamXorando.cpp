//Link da questao
//https://neps.academy/br/exercise/864
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    while(scanf("%d%d%d",&n,&m,&k) && (n||m||k)){
        vector<int> v(n); for(int &x : v)scanf("%d",&x);
        
        printf("%d\n",v[((k-1)-m%n + n)%n]);
    }
}