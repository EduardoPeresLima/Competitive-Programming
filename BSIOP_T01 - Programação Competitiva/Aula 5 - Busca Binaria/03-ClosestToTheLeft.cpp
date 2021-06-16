//Link da questao
//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B
#include<bits/stdc++.h>
using namespace std;

int befUBound(int val, vector<int> &v){
    int lo = 0, hi = v.size(), mid;
    while(lo < hi){
        mid = lo + (hi-lo)/2;
        if(v[mid] <= val)lo = mid+1;
        else hi = mid;
    }
    return lo;
}

int main(){
    int n, k; scanf("%d%d",&n,&k);
    vector<int> v(n); for(int &x : v)scanf("%d",&x);
    for(int val, i=0;i<k;i++){
        scanf("%d",&val);
        printf("%d\n",befUBound(val,v));
    }
}