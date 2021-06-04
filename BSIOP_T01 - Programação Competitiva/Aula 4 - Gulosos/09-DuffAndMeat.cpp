//Link da questao
//https://codeforces.com/contest/588/problem/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n), p(n);
    int ans = 0, preco = 200;
    for(int i=0;i<n;i++) cin >> a[i] >> p[i];
    for(int i=0;i<n;i++){
        preco = min(preco,p[i]);
        ans += a[i] * preco;
    }
    cout << ans << endl;
}