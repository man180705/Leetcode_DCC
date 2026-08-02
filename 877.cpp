class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<int>nums=piles;
        int n =nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int i=0;i<n;i++) dp[i][i]=nums[i];

        for(int i=2;i<=n;i++){
            for(int j=0;j+i-1<n;j++){
                int k=j+i-1;
                dp[j][k]=max(nums[j]-dp[j+1][k], nums[k]-dp[j][k-1]);
            }
        }
        //return dp[0][n-1]>0; //which one is correct:(
        return dp[0][n-1]>=0;
    }
};