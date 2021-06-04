//Link da questao
//https://cses.fi/problemset/task/1073
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);    
    multiset<int> m;
    for(int val,i=0;i<n;i++){
        scanf("%d",&val);
        auto it = m.upper_bound(val);
        if(it!=m.end())m.erase(it);
        m.emplace(val);
    }
    printf("%d\n",(int)m.size());

}