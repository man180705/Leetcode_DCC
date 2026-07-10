// class Solution {
// public:
//     vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
//     }
// };

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++) a[i]={nums[i],i};
        sort(a.begin(),a.end());

        vector<int> pos(n);
        for(int i=0;i<n;i++) pos[a[i].second]=i;

        // next[i] = farthest reachable index in sorted array
        vector<int> next(n);
        int r=0;
        for(int i=0;i<n;i++){
            while(r<n && a[r].first - a[i].first <= maxDiff) r++;
            next[i]=r-1;
        }

        // binary lifting
        int LOG=20;
        vector<vector<int>> up(LOG, vector<int>(n));
        for(int i=0;i<n;i++) up[0][i]=next[i];

        for(int j=1;j<LOG;j++){
            for(int i=0;i<n;i++){
                up[j][i]=up[j-1][up[j-1][i]];
            }
        }

        vector<int> ans;

        for(auto &q:queries){
            int u=pos[q[0]], v=pos[q[1]];
            if(u>v) swap(u,v);

            // case 1: same node
            if(u==v){
                ans.push_back(0);
                continue;
            }

            // case 2: cannot move at all
            if(next[u]==u){
                ans.push_back(-1);
                continue;
            }

            int cur=u, steps=0;

            for(int j=LOG-1;j>=0;j--){
                if(up[j][cur] < v){
                    if(up[j][cur]==cur) continue;
                    cur=up[j][cur];
                    steps += (1<<j);
                }
            }

            if(next[cur] < v) ans.push_back(-1);
            else ans.push_back(steps+1);
        }

        return ans;
    }
};