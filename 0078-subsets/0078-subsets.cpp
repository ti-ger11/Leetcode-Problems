class Solution {
public:

    void ans( vector<vector<int>> &result,vector<int> &subset,int index,vector<int> nums)
    {
        //base condition
        if(index==nums.size())
        {
            result.push_back(subset);
            return;
        }


        //pick the number
        subset.push_back(nums[index]);
        //backtrack
        ans(result,subset,index+1,nums);



        //do not pick the number
        subset.pop_back();
        //backtrack
        ans(result,subset,index+1,nums);



    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;

        vector<int>subset;

        ans(result,subset,0,nums);

        return result;
    }


};