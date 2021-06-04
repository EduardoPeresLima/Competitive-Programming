//Link da questao
//https://codeforces.com/problemset/problem/1353/B
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int t;cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        sort(a.begin(),a.end()); sort(b.begin(),b.end());
        for(int i=0;i<k;i++){
            if(a[i] < b[n-1-i]){
                swap(a[i], b[n-1-i]);
            }
        }
        cout << accumulate(a.begin(),a.end(),0) << endl;
    }
}