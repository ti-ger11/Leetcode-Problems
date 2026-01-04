class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        
        for(int i = 0; i < n; i++) {
           
            int complement = target - numbers[i];
            auto it = lower_bound(numbers.begin() + i + 1, numbers.end(), complement);
            
           
            if(it != numbers.end() && *it == complement) {
                int j = distance(numbers.begin(), it);
                return {i + 1, j + 1}; 
            }
        }
        
        return {-1, -1};
    }
};