// Leetcode 1358 : Number of substrings containing all three characters

class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int substring = 0;
        int n = s.length();
        int hash[3] = {0};
        while(r<n){
            hash[s[r]-'a']++;
            while(hash[0]>0 && hash[1]>0 && hash[2]>0){
                substring += (n-r);
                hash[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return substring;
    }
};
