class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixGcd(n);
        int max_num=0;//generally we take INT_MIN but here numbers are from 1

        for(int i=0;i<n;i++){
            max_num=max(max_num,nums[i]);
            prefixGcd[i]=gcd(max_num,nums[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());

        long long ans=0;
        int l=0, r=n-1;

        while(l<r){
            ans+=gcd(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;
            // esse agr beech mein oi aayega to wo miss ho jayega thats why while mein equality nhi h
        }
        return ans;
    }
};