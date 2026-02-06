class Solution {
public:

    void solve(vector<int>&nums,int si,vector<vector<int>>&res)
    {
        //base condition
        if(si==nums.size())
        {
            res.push_back(nums);
            return;
        }

        unordered_set<int>mp;

        for(int i=si;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
                mp.insert(nums[i]);

                swap(nums[i],nums[si]);

                solve(nums,si+1,res);

                //backtarck

                swap(nums[i],nums[si]);
            }

        }


    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>>res;
        solve(nums,0,res);

        return res;
        
    }
};