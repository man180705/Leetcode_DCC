class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //either three largest
        int a=nums[nums.size()-1];
        int b=nums[nums.size()-2];
        int c=nums[nums.size()-3];
        //or 2 smallest and one positive
        int d=nums[0];
        int e=nums[1];
        return max((a*b*c), (a*d*e));
    }
};