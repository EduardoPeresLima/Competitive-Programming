//Link da questao
//https://neps.academy/br/exercise/865
#include<bits/stdc++.h>
using namespace std;
inline int reads(string &x){char _[100'005]; int r = scanf("%s",_);x=_; return r;}

int getDigitRoot(int val){
    if(val<10)return val;
    int ans = 0;
    while(val){
        ans += val%10;
        val/=10;
    }
    return getDigitRoot(ans);
}

int main(){
    //teoria ->dr(b^e) = dr(dr(b)^e). Sendo dr -> digit root

    string b, e;
    reads(b); reads(e);
    int db = 0;
    for(char c : b) db += c-'0';
    db = getDigitRoot(db);
    int ans = 1;
    for(char c : e){
        int pow_10 = 1, pow_c = 1;
        for(int i=0;i<10;i++)pow_10 = getDigitRoot(pow_10*ans);
        for(int i = c-'0'; i>0;i--)pow_c = getDigitRoot(pow_c*db);
        ans = getDigitRoot(pow_10*pow_c);
    }
    printf("%d\n",ans);
}