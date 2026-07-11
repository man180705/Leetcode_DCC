class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>visit(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(visit[i]) continue;
            queue<int>q;
            q.push(i);
            visit[i]=true;
            int nodes=0;
            int degreeSum=0;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                nodes++;
                degreeSum+=adj[u].size();
                for(int v:adj[u]){
                    if(!visit[v]){
                        visit[v]=true;
                        q.push(v);
                    }
                }
            }
            if(degreeSum==nodes*(nodes-1)) count+=1;
        }
        return count;
    }
};