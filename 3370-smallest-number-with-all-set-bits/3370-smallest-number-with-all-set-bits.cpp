class Solution {
public:
    int smallestNumber(int n) {

        int k=log2(n)+1;
        return (1<<k)-1;
        
    }
};