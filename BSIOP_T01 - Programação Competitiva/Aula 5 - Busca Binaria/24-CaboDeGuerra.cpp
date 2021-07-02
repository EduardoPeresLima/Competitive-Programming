//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1586
#include<bits/stdc++.h>
using namespace std;
inline void reads(string &x) {char k[20]; scanf("%s",k);x=k;}
typedef long long ll;
int n;
vector<string> nome;
vector<ll> v;
ll f(int id){
    ll sum = 0;
    for(ll i=0;i<=id;i++)sum += v[i] * (id-i+1);
    for(ll i=id+1;i<n;i++)sum-= v[i] * (i-id);
    return sum;
}

int bb(){
    int lo = 0, hi = n, mid;
    while(lo < hi){
        mid = lo + ((hi-lo)>>1);
        ll ret = f(mid);
        if(ret == 0)return mid;
        else if(ret < 0)lo = mid+1;
        else hi = mid;
    }
    return -1;
}

int main(){
    while(scanf("%d",&n) && n){
        nome.resize(n), v.assign(n,0);
        for(int i=0;i<n;i++){
            reads(nome[i]);
            for(char c : nome[i])v[i] += c;

        }
        int ans = bb();
        printf("%s\n",ans == -1?"Impossibilidade de empate.":nome[ans].data());
    }
}