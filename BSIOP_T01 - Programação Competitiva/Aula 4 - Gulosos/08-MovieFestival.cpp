//Link da questao
//https://cses.fi/problemset/task/1629/
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(),v.end(),cmp);

    int fim = -10, ans = 0;
    for(int i=0;i<n;i++){
        if(v[i].first >= fim){
            ans++;
            fim = v[i].second;
        }
    }
    cout << ans << endl;
}