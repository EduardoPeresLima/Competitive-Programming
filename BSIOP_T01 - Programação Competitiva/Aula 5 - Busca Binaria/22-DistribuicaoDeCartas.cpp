//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/2821
#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;

pair<int,bool> can(int val){
    int cont = 0, sum = 0;
    int maior = 0, cur = 0;
    for(int x : v){
        if(x > val)return {0,false};
        if(sum + x > val){
            cont++,sum = 0;
            maior = max(maior,cur), cur = 0;
        }
        sum += x;
        cur++;
    }
    cont++,sum = 0;
    maior = max(maior,cur), cur = 0;
    return {maior,cont <= m};
}

bool f(int val){
    return can(val).second;
}

int bb(){
    int lo = 0, hi = 1000, mid;
    while(lo < hi){
        mid = lo + ((hi - lo) >> 1);
        if(!f(mid))lo = mid+1;
        else hi = mid;
    }
    return lo;
}

int main(){
    scanf("%d%d",&n,&m);
    v.resize(n); 
    char c[2];
    for(int &x : v){
        scanf("%s",c);
        if(strlen(c) == 2) x = 10;
        else if(c[0] == 'A')x = 1;
        else if(c[0] == 'J')x = 11;
        else if(c[0] == 'Q')x = 12;
        else if(c[0] == 'K')x = 13;
        else x = c[0]-'0';
    }
    int ans = bb();
    int maior = can(ans).first;
    printf("%d %d\n",maior,ans);
}