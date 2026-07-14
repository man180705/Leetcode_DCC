class Solution {
public:

    int as=0;
    const int MOD = 1e9+7;
    int dp[201][201][201];

    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);
    }

    int f(int ind, vector<int>& nums, int g1, int g2){
        //base
        if(ind==nums.size()) return (g1!=0 && g2!=0 && g1==g2);
        
        if(dp[ind][g1][g2] != -1) return dp[ind][g1][g2];

        int x=nums[ind];
        //take1
        long long t1=f(ind+1,nums,(g1 == 0 ? x : gcd(g1, x)),g2);

        //take2
        long long t2=f(ind+1,nums,g1,(g2 == 0 ? x : gcd(g2, x)));

        //not take
        long long nt=f(ind+1,nums,g1,g2);

        return dp[ind][g1][g2]=(t1+t2+nt)%MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        // 3 choices h->
        // seq1 lu
        // 2 lu
        // skip krdu
        memset(dp, -1, sizeof(dp));
        return f(0,nums,0,0);
        // return ans;
    }
};