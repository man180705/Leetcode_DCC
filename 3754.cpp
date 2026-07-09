class Solution {
public:
using ll= long long;
    long long sumAndMultiply(int n) {
        if(n<=0) return 0;
        ll sum=0;
        ll x=0;
        ll place=1;
        while(n>0){
            int d=n%10;
            if(d!=0){
                sum+=d;
                x=d*place+x;
                place*=10;
            }
            n=n/10;
        }
        return sum*x;
    }
};