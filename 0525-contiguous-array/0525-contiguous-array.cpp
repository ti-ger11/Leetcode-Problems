class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int n=nums.size();

        map<int,int>m;
        int ans=0;
        int pre=0;


        m[pre]=-1;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                nums[i]=-1;

            }
        }

        for(int i=0;i<n;i++)
        {
            pre+=nums[i];

            if(m.find(pre)!=m.end()){
                int val=m[pre];
                ans=max(ans,i-val);
            }
            else
            {
                m[pre]=i;
            }
        }

        return ans;
        
    }
};