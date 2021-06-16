//Link da questao
//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
#include<bits/stdc++.h>
using namespace std;

int uBound(int val, vector<int> &v){
    int lo = 0, hi = v.size(), mid;
    while(lo < hi){
        mid = lo + (hi-lo)/2;
        if(v[mid] <= val)lo = mid+1;
        else hi = mid;
    }
    return lo;
}
int lBound(int val, vector<int> &v){
    int lo = 0, hi = v.size(), mid;
    while(lo < hi){
        mid = lo + (hi-lo)/2;
        if(v[mid] < val)lo = mid+1;
        else hi = mid;
    }
    return lo;
}

int main(){
    int n; scanf("%d",&n);
    vector<int> v(n); for(int &x : v)scanf("%d",&x);
    sort(v.begin(),v.end());
    int k; scanf("%d",&k);
    for(int l,r,i=0;i<k;i++){
        scanf("%d%d",&l,&r);
        printf("%d ",uBound(r,v) - lBound(l,v));
    }
    printf("\n");
}