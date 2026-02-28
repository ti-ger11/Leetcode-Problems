class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,int>>pq;

        for(int i=0;i<points.size();i++)
        {
            auto x=points[i];
            float d=(x[0]*x[0])+(x[1]*x[1]);
            if(pq.size()<k)
            {
                pq.push({d,i});

            }

            else if(d<pq.top().first)
            {
                pq.pop();
                pq.push({d,i});
            }

        }

        vector<vector<int>>ans;

        for(int i=0;i<k;i++)
        {
            auto [val,idx]=pq.top();
            ans.push_back(points[idx]);
            pq.pop();
        }


        return ans;
        
    }
};
