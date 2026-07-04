//Approach1
class DSU{
public:
    vector<int>parent,rank;
    DSU(int n){
        //made of size n+1 bcz 0 is of no use;
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=1;i<=n;i++) parent[i]=i; //self is the parent of itself;
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int a,int b){
        int parentA=find(a);
        int parentB=find(b);
        if(parentA==parentB) return;
        if(rank[parentA]<rank[parentB]) parent[parentA]=parentB;
        else if(rank[parentB]<rank[parentA]) parent[parentB]=parentA;
        else{
            parent[parentB]=parentA;
            rank[parentA]++;
        }
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // hame matlab hi unse h jo 1 se connected h;
        DSU dsu(n);
        //union of all edges
        for(auto& r:roads){
            dsu.unite(r[0],r[1]);
        }
        //find component for 1
        int p1=dsu.find(1);
        //find min in its component
        int ans=INT_MAX;
        for(auto& r:roads){
            if(dsu.find(r[0])==p1){
                ans=min(ans,r[2]);
            }
        }
        return ans;
    }
};

//approach 2:
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto& r:roads){
            // it is done because it is bidirectional
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        vector<int>vis(n+1,0); //will not use 0th because starting from 1-n
        queue<int>q;
        q.push(1);
        vis[1]=1;
        int ans=INT_MAX;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto& it:adj[node]){
                int next=it.first;
                int dist=it.second;
                ans=min(ans,dist);
                if(!vis[next]){
                    vis[next]=1;
                    q.push(next);
                }
            }
        }
        return ans;
    }
};