class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> ss;
        int l = 0, r = 0;
        int n = s.length();
        int res = 0;

        while (r < n) {
            while (ss.find(s[r]) != ss.end()) {
                ss.erase(s[l]);
                l++;
            }
            ss.insert(s[r]);
            r++;
            res = max(res, (int)ss.size());
        }

        return res;
    }
};