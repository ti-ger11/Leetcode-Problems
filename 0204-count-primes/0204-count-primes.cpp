class Solution {
public:
    int countPrimes(int n) {

        if(n==1||n==0)
        {
            return 0;
        }

        vector<int>a(n,1);

        for(int i=2;i<n;i++)
        {
            int temp=2;
            while(temp*i<n)
            {
                a[temp*i]=0;
                temp++;

            }
        }

        int sum=0;

        for(auto x:a)
        {
            sum+=x;
        }

        return sum-2;
        
    }
};