class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();

        //making set for the pairs
        unordered_set<int>s1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                s1.insert(nums[i]^nums[j]);
            }
        }

        //taking xor with the 3rd num
        unordered_set<int>s2;
        for(int pairXor:s1){
            for(int &num:nums){
                s2.insert(pairXor^num);
            }
        }
        //and can be assured from this as max can be the 2^k bits so which will be 2*max_ele of s2but number of bits remain same.
        //we want to return the unique vals in the set 
        return s2.size();
    }
};


//Approach-2 (Xor Pairs and then Xor triplets using vectors instead of set), Set involves hashing internally and hence this is an improved solution
//T.C : O(n^2 + n*maxEl), maxEl = max element in nums
//S.C : O(maxEl), less than next power of 2 after maxEl
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxEl = *max_element(begin(nums), end(nums));

        int T = 1;
        while(T <= maxEl) {
            T <<= 1; //T = T*2
        }

        vector<bool> s1(T, false); //XOR pair values set to true
        vector<bool> s2(T, false); //XOR triplet values set to true

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                s1[nums[i] ^ nums[j]] = true;
            }
        }

        for(int i = 0; i < T; i++) {
            if(s1[i] == true) {
                for(int &num : nums) {
                    s2[i ^ num] = true;
                }
            }
        }

        int count = 0; //unique xor count
        for(int i = 0; i < T; i++) {
            if(s2[i] == true)
                count++;
        }

        return count;

        
    }
};