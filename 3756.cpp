class Solution {
public:

    using ll=long long;
    const int MOD=1e9+7;

    vector<int> cnt, sum;
    vector<ll> prefNum, pow10;

    int sumAndMultiply(int l,int r){
        int L=cnt[l],R=cnt[r+1]-1;
        if(L>R) return 0;
        int len=R-L+1;
        ll x=(prefNum[R+1]-(prefNum[L]*pow10[len])%MOD+MOD)%MOD;
        ll ssum=sum[r+1]-sum[l];
        return (x*ssum)%MOD;
    }

    // int sumAndMultiply(string s, int a, int b) {
    //     ll sum=0;
    //     ll x=0;
    //     for(int i=a;i<=b;i++){
    //         int d=s[i]-'0';
    //         if(d!=0){
    //             sum+=d; //stoi(d) wont work as d is a char not a string
    //             x=x*10+d;
    //         }
    //     }
    //     return (sum*x)%MOD;
    // }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        cnt.assign(n+1,0);
        sum.assign(n+1,0);
        for(int i=0;i<n;i++){
            cnt[i+1]=cnt[i];
            sum[i+1]=sum[i];
            if(s[i]!='0'){
                cnt[i+1]++;
                sum[i+1]+=(s[i]-'0');
            }
        }
        vector<int>digits;
        for(char c:s) if(c!='0') digits.push_back(c-'0');
        int m=digits.size();
        prefNum.assign(m+1,0);
        for(int i=0;i<m;i++) prefNum[i+1]=(prefNum[i]*10+digits[i])%MOD;
        pow10.assign(m+1,1);
        for(int i=1;i<=m;i++) pow10[i]=(pow10[i-1]*10)%MOD;
        vector<int>ans;
        for(auto&q:queries) ans.push_back(sumAndMultiply(q[0],q[1]));
        return ans;
    }
    // int n=s.size();
    //     int m=queries.size();
    //     vector<int>ans;
    //     for(int i=0;i<m;i++){
    //         ans.push_back(sumAndMultiply(s,queries[i][0],queries[i][1]));
    //     }
    //     return ans;
    
};