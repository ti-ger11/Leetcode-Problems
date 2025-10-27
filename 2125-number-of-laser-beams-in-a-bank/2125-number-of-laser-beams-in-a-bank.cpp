class Solution {
public:

    int count1(string row)
    {
        int count=0;
        for(char x:row)
        {
            if(x=='1')
            {
                count++;
            }
        }
        return count;
    }
    int numberOfBeams(vector<string>& bank) {

        int n=bank.size();
        int ans=0;

        int x=0,y=0;

        
        for(int i=0;i<n;i++)
        {
            x = count1(bank[i]);
            if(x>0)
            {
                ans += x*y;
                y = x; 
            }
        }
        return ans;


       
        
    }
};