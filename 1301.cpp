// class Solution {
// public:
//     const int MOD=1e9+7;
//     vector<int> pathsWithMaxScore(vector<string>& board) {
//         int n=board.size();
//         vector<vector<int>>best(n,vector<int>(n,INT_MIN));
//         vector<vector<int>>ways(n,vector<int>(n,0));
//         best[0][0]=0;
//         ways[0][0]=1;

//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(board[i][j]=='X') continue;
//                 if(i==0 && j==0) continue;
//                 int mx=INT_MIN;
//                 long long count=0;
//                 vector<pair<int,int>> prev = {
//                     {i-1, j}, {i, j-1}, {i-1, j-1}
//                 };
//                 for(auto& p:prev){
//                     int x=p.first,y=p.second;
//                     if(x>=0 && y>=0 && ways[x][y>0]){
//                         if(best[x][y] > mx) {
//                             mx = best[x][y];
//                             count = ways[x][y];
//                         }
//                         else if(best[x][y]==mx) count=(count+ways[x][y]) % MOD;
//                     }
//                 }
//                 if(count==0) continue;
//                 int val=0;
//                 if(isdigit(board[i][j])) {
//                     val = board[i][j] - '0';
//                 }
//                 best[i][j] = mx + val;
//                 ways[i][j] = count % MOD;
//             }
//         }
//         if(ways[n-1][n-1] == 0) return {0, 0};
//         return {best[n-1][n-1], ways[n-1][n-1]};
//     }
// };

using PII = pair<int,int>;

class Solution {
private:
    static constexpr int mod = 1e9 + 7;

public:
    void update(vector<vector<PII>>& dp, int n, int x, int y, int u, int v) {
        if(u >= n || v >= n || dp[u][v].first == -1) return;

        if(dp[u][v].first > dp[x][y].first) {
            dp[x][y] = dp[u][v];
        } 
        else if(dp[u][v].first == dp[x][y].first) {
            dp[x][y].second = (dp[x][y].second + dp[u][v].second) % mod;
        }
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        
        vector<vector<PII>> dp(n, vector<PII>(n, {-1, 0}));

        // Start from 'S'
        dp[n-1][n-1] = {0, 1};

        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {

                if(i == n - 1 && j == n - 1) continue;
                if(board[i][j] == 'X') continue;

                // Check 3 possible moves
                update(dp, n, i, j, i + 1, j);
                update(dp, n, i, j, i, j + 1);
                update(dp, n, i, j, i + 1, j + 1);

                if(dp[i][j].first == -1) continue;

                // Add value (ignore 'E' and 'S')
                if(isdigit(board[i][j])) {
                    dp[i][j].first += board[i][j] - '0';
                }
            }
        }

        if(dp[0][0].first == -1) return {0, 0};
        return {dp[0][0].first, dp[0][0].second};
    }
};