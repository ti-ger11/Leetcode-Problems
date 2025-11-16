class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n=s.length();
        int cnta=0,cntb=0;
        for(auto x:s)
        {
            if(x=='a')
            {
                cnta++;
            }

            else
            {
                cntb++;
            }
        }

        return n-2*min(cnta,cntb);
        
    }
};