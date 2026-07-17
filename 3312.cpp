class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n=nums.size();

        int maxVal=*max_element(nums.begin(),nums.end());

        vector<long long>freq(maxVal+1,0);
        for(int x:nums) freq[x]++;

        //counting the pairs and finding the gcd:)
        vector<long long>countG(maxVal+1,0);
        for(int g=maxVal;g>=1;g--){
            long long count=0;
            for(int i=g;i<=maxVal;i+=g) count+=freq[i];
            countG[g]=count*(count-1)/2;
            for(int j=2*g;j<=maxVal;j+=g) countG[g]-=countG[j];
        }

        // vector<long long>prefix;
        // for(int g=1;g<=maxVal;g++){
        //     for(long long i=0;i<countG[g];i++) prefix.push_back(g);
        // }

        // vector<int>ans;
        // for(auto q:queries) ans.push_back(prefix[q]);
        // return ans;

         // prefix sum: number of pairs with gcd <= g
        vector<long long> pref(maxVal + 1, 0);
        for (int g = 1; g <= maxVal; g++) {
            pref[g] = pref[g - 1] + countG[g];
        }

        // answer queries using binary search
        vector<int> ans;
        for (auto q : queries) {
            int g = lower_bound(pref.begin(), pref.end(), q + 1) - pref.begin();
            ans.push_back(g);
        }
        return ans;

    }
};

// queries[i] <n*(n-1)/2 because to apply the short cut trick for the brute force :)


//it will not happen in o(N^2) as tle will occur otherwise easy
        // rest is easy but how to do for finding all the gcdPair*
        // int n=nums.size();
        // int m=queries.size();
        // vector<int>gcdPairs;
        // vector<int>ans;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         gcdPairs.push_back(gcd(nums[i],nums[j]));
        //     }
        // }
        // sort(gcdPairs.begin(),gcdPairs.end());
        // // return gcdPairs;
        // for(int i=0;i<m;i++){
        //     ans.push_back(gcdPairs[queries[i]]);
        // }
        // return ans;