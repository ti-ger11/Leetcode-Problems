class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

       unordered_map<char,int>m;

       for(auto x:tasks)
       {
            m[x]++;
       }

       priority_queue<int>pq;

       for(auto x:m)
       {
            pq.push(x.second);
       }

       queue<pair<int,int>>q;

       int count=0;

       while(!q.empty()||!pq.empty())
       {    
            count++;
            if(!pq.empty())
            {
                int val=pq.top();

                pq.pop();

                if(val-1>0)
                {
                    q.push({val-1,n+count});
                }
                
            }
            


            if(!q.empty()&&count==(q.front().second))
            {
                pq.push(q.front().first);
                q.pop();

            }
        }

        return count;
    }
};
