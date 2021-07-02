//Link da questao
//https://codeforces.com/contest/492/problem/B
#include<bits/stdc++.h>
using namespace std;
int n, l;
vector<double> v;
bool f(double x){
    if(x < v.front() || x < l-v.back()) return false;
    for(int i=0;i<n-1;i++){
        if(2*x < (v[i+1]-v[i])) return false;
    }
    return true;
}

double bb(){
    double lo = 0, hi = l, mid;
    for(int i=0;i<100;i++){
        mid = (lo + hi) / 2;
        if(!f(mid))lo = mid;
        else hi = mid;
    }
    return lo;
}

int main(){
    scanf("%d%d",&n,&l);
    v.resize(n); for(double &x : v)scanf("%lf",&x);
    sort(v.begin(),v.end());
    printf("%.12lf\n",bb());
}