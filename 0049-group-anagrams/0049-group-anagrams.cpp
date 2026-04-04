class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n=strs.size();
        unordered_map<string,vector<string>>m;
        for(auto c:strs)
        {
            auto k=c;
            sort(k.begin(),k.end());
            m[k].push_back(c);

        }

        vector<vector<string>>res;

        for(auto x:m)
        {
            res.push_back(x.second);
        }

        return res;
        
    }
};