//Link da questao
//https://cses.fi/problemset/task/1621
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,val; scanf("%d",&n);
    set<int> st;
    for(int i=0;i<n;i++) scanf("%d",&val), st.emplace(val);
    printf("%d\n",(int)st.size());
}