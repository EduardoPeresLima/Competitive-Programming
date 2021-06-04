//Link da questao
//https://codeforces.com/problemset/problem/1385/B
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int t;cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(2*n); for(int &x : a) cin >> x;
        vector<int> f(n+1), ans;
        for(int i=2*n-1;i>=0;i--){
            if(f[a[i]] == 0){
                ans.emplace_back(a[i]);
                f[a[i]]++;
            }
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<n;i++)cout << ans[i] << " ";
        cout << endl;
    }
}