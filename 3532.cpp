class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> components(n);
        int id = 0;
        components[0] = 0;

        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff) components[i]=id;
            else{
                id++;
                components[i]=id;
            }
        }
        vector<bool>ans;
        for(auto &q:queries){
            int u=q[0],v=q[1];
            ans.push_back(components[u]==components[v]);
        }
        
        return ans;
    }
};