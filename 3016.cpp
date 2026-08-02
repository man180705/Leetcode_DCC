class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int ans=0;
        vector<int>freq(26,0);
        for(char c:word) freq[c-'a']++;
        sort(freq.begin(),freq.end(),greater<int>());
        // for(int i=0;i<n;i++) ans+=(i/8)+1;
        for(int i=0;i<26;i++){
            if(freq[i]==0) break;
            ans+=freq[i]*((i/8)+1);
        }
        return ans;
    }
};