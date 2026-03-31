class Solution {
public:
    double myPow(double x, long long n) {
        if(n<0)
        {
            x=1.0/x;
            n=-n;
        }

        double result=1;

        while(n>0)
        {
            if(n%2!=0)//current bit is 1
            {
                result*=x;
            }

            x*=x;

            n=n/2;
        }

        return result;
    }
};