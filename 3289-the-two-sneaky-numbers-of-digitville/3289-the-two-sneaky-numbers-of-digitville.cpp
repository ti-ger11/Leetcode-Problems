class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {

        map<int,int>m;
        vector<int>ans;

        for(auto x:nums)
        {
            m[x]++;
        }

        for(auto x:m)
        {
            if(x.second>1)
            {
                ans.push_back(x.first);
            }
        }

        return ans;
        
    }
};