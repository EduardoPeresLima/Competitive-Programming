//Link da questao
//
#include<iostream>
#include<vector>
#include<numeric> //iota
using namespace std;
const int MOD = ((int)1e9+7);
typedef long long       ll;

int n, m;
vector<int> pai;
int id(int u){
    return pai[u] = u == pai[u]?u:id(pai[u]);
}
void join(int u, int v){
    u = id(u), v = id(v);
    if(u==v)return;
    pai[u] = v;
}

int main(){
    ios_base::sync_with_stdio(0);
    
}