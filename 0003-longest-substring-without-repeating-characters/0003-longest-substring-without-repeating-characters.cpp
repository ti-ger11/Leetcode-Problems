class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int>m;

        int l=0,h=0;

        int maxlen=0;
        while (h < s.size()) 
        {
            if (m.count(s[h]) && m[s[h]] >= l) 
            {
                l = m[s[h]] + 1;  // jump low past duplicate
            }
            m[s[h]] = h;          // always update index
            maxlen = max(maxlen, h - l + 1);  // always update maxlen
            h++;
        }
        return maxlen;

    }
};