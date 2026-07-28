class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int>freq(26,0);
        for(char c:s) freq[c-'a']++;

        string half="", middle="";
        for(int i=0;i<26;i++){
            if(freq[i]%2==1) middle=string(1,'a'+i);
            half+=string(freq[i]/2,'a'+i);
        }

        string revHalf=half;
        reverse(revHalf.begin(),revHalf.end());

        return half+middle+revHalf;
    }
};