//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1579
#include<bits/stdc++.h>
using namespace std;
int n, m, frete;
vector<int> v;
bool f(int x){
    int cont = 0, sum = 0;
    for(int val : v){
        if(sum + val > x){
            cont++, sum = 0;
        }
        sum += val;
    }
    cont++;
    return cont > m;
}

int bb(){
    int lo = *max_element(v.begin(),v.end()), hi = 1e9, mid;
    while(lo < hi){
        mid = lo + ((hi-lo) >> 1);
        if(f(mid))lo = mid+1;
        else hi = mid;
    }
    return lo;
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&frete);
        v.assign(n,0);for(int &x : v)scanf("%d",&x);
        int ans = bb();
        printf("%d $%d\n",ans, ans * m * frete);
    }
}