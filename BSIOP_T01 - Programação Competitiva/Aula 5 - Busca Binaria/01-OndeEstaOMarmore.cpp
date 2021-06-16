//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1025
#include<bits/stdc++.h>
using namespace std;


int bb(int val, vector<int> &v){
    int lo = 0, hi = v.size(), mid;
    while(lo < hi){
        mid = lo + (hi-lo)/2;
        if(v[mid] < val)lo = mid+1;
        else hi = mid;
    }
    return v[lo] == val? lo:-1;
}

int main(){
    int n, q; 
    int caso = 1;
    while(scanf("%d%d",&n,&q) && (n || q)){
        printf("CASE# %d:\n",caso++);
        vector<int> v(n); for(int &x : v)scanf("%d",&x);
        sort(v.begin(),v.end());
        for(int val,i=0;i<q;i++){
            scanf("%d",&val);
            int r = bb(val,v);
            if(r == -1)printf("%d not found\n",val);
            else printf("%d found at %d\n",val,r+1);
        }
    }
}