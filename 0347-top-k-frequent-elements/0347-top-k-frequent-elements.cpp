class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    
        unordered_map<int,int> m;

        vector<int> ans;

        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }

        priority_queue<pair<int,int>,      // stores {frequency, element}
               vector<pair<int,int>>,  // underlying container
               greater<pair<int,int>>> pq; // greater = min heap

        for(auto x:m)
        {
            pq.push({x.second,x.first});
            if(pq.size()>k)
            {
                pq.pop();
            }
           
        }

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
        

    }
};