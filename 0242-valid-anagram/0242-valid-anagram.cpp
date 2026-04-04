class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size()!=t.size())
        {
            return false;
        }

        vector<int>a(26,0);

        for(int i=0;i<s.size();i++)
        {
            a[s[i]-'a']++;
            a[t[i]-'a']--;

        }

        for(auto x:a)
        {
            if(x!=0)
            {
                return false;
            }
        }

        return true;

        
    }
};