class Solution {
public:
    void find_permutations(vector<int> ip, vector<int> op,
                           vector<vector<int>> &res)
    {
        if(ip.size() == 0)
        {
            res.push_back(op);
            return;
        }

        unordered_set<int>mp;

        for(int i = 0; i < ip.size(); i++)
        {
            if(mp.find(ip[i])==mp.end())
            {
                mp.insert(ip[i]);
                vector<int> ip_new = ip;
                vector<int> op_new = op;

                op_new.push_back(ip[i]);
                ip_new.erase(ip_new.begin() + i);

                find_permutations(ip_new, op_new, res);

            }
           
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        find_permutations(nums, {}, res);
        return res;
    }
};
