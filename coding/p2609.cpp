#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long long a,b,c,ans =0,tmp=1,tt=1;
    scanf("%lld %lld %lld",&a,&b,&c);
    ans = a;
    if(b==1){
     cout<<a%c<<endl;
     return 0;
 	}

    while(1){
        ans = ans%c;
        if(c-ans < ans) ans = -(c-ans);
        tt = ans;
        if(b%2 ==0){
            b/=2;
        }
        else{
            b = (b-1)/2;
            tmp *= tt;
            tmp %= c;
        }
        ans = (ans*ans)%c;
        if(b==1) break;
    }
    ans = (ans*tmp)%c;
    if(ans < 0) printf("%lld\n",c+ans);
    else printf("%lld\n",ans);
    return 0;
}