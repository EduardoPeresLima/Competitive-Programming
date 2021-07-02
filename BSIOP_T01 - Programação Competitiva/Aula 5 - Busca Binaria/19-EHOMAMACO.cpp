//Link da questao
//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3183
#include<bits/stdc++.h>
using namespace std;

bool f(int n, vector<int> &v, int k){
    int last = 0, delta;
    for(int val : v){
        delta = val - last;
        if(delta > k)return false;
        if(delta == k)k--;
        last = val;
    }
    return true;
}

int bb(int n, vector<int> &v){
    int lo = 1, hi = 1e9, mid;
    while(lo < hi){
        mid = lo + ((hi-lo)>>1);
        if(f(n,v,mid))hi = mid;
        else lo = mid+1;
    }
    return lo;
}

int main(){
    int t; scanf("%d",&t);
    for(int caso = 1;caso <=t;caso++){
        int n; scanf("%d",&n);
        vector<int> v(n); for(int &x : v)scanf("%d",&x);
        printf("Case %d: %d\n",caso, bb(n,v));
    }
}