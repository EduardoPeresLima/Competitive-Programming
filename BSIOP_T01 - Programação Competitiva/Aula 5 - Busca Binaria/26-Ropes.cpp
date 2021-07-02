//Link da questao
//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<double> v;
bool f(double x){
    int cont = 0;
    for(double &y : v) cont += int(y/x);
    return cont >= k;
}

double bb(){
    double eps = 1e-7;
    double lo = eps, hi = 1e7, mid;
    while(hi-lo > eps){
        mid = (lo + hi)/2;
        if(f(mid))lo = mid;
        else hi = mid;
    }
    return lo;
}

int main(){
    scanf("%d%d",&n,&k);
    v.resize(n);for(double &x : v)scanf("%lf",&x);
    
    printf("%.10lf\n",bb());
}