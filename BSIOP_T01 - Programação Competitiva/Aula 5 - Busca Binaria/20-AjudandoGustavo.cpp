//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/2220
#include<bits/stdc++.h>
using namespace std;
inline void reads(string &x){char k[100005]; scanf("%s",k);x=k;}
string a, b;

bool f(int x){
    int n = a.size(), m = b.size();
    for(int i=0,k=0;i<m;i++){
        for(int j=0;j<x;){
            if(k>=n)return false;
            if(b[i] == a[k++])j++;
        }
    }
    return true;
}

int bb(){
    int lo = 0, hi = 2e5, mid;
    while(lo < hi){
        mid = lo + ((hi-lo)>>1);
        if(f(mid))lo = mid + 1;
        else hi = mid;
    }
    return lo-1;
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        reads(a); reads(b);
        printf("%d\n",bb());
    }
}