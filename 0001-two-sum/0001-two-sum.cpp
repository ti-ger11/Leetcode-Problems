class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int x=nums[i];
            int ans=target-x;
           auto it=find(nums.begin(),nums.end(),ans);
            if(it!=nums.end())
            {
                int k=it-nums.begin();
                if(i==k)
                {
                    continue;
                }
                return {i,k};
            }
        }
        
        return {-1};
        
    }
};