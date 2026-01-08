class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 2; i++) {
            // Skip duplicates
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            
            unordered_set<int> seen;
            for(int j = i + 1; j < n; j++) {
                int complement = -nums[i] - nums[j];
                
                if(seen.count(complement)) {
                    res.push_back({nums[i], complement, nums[j]});
                    
                    // Skip duplicates for nums[j]
                    while(j + 1 < n && nums[j] == nums[j + 1])
                        j++;
                }
                seen.insert(nums[j]);
            }
        }
        
        return res;
    }
};