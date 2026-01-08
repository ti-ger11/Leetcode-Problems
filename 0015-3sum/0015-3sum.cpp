class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        
        // Sort the array to handle duplicates
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 2; i++) {
            // Skip duplicate first elements
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;
            
            while(left < right) {
                int sum = nums[left] + nums[right];
                
                if(sum == target) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for left pointer
                    while(left < right && nums[left] == nums[left + 1])
                        left++;
                    
                    // Skip duplicates for right pointer
                    while(left < right && nums[right] == nums[right - 1])
                        right--;
                    
                    left++;
                    right--;
                }
                else if(sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        
        return res;
    }
};