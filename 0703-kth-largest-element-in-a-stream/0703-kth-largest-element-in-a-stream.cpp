#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2")

class KthLargest {
    int bit[20002] = {};
    int K, total = 0;
    const int OFFSET = 10000;
    const int MAXN = 20001;

    void update(int i, int val) {
        for(i++; i <= MAXN; i += i & (-i))
            bit[i] += val;
    }

    // how many elements <= i
    int query(int i) {
        int sum = 0;
        for(i++; i > 0; i -= i & (-i))
            sum += bit[i];
        return sum;
    }

    // binary search on BIT to find kth largest
    int findKth() {
        // kth largest = (total - K + 1)th smallest
        int target = total - K + 1;
        int pos = 0;
        int logn = 14; // 2^14 = 16384 > 20001
        for(int i = logn; i >= 0; i--) {
            if(pos + (1 << i) <= MAXN && bit[pos + (1 << i)] < target) {
                pos += (1 << i);
                target -= bit[pos];
            }
        }
        return pos - OFFSET;
    }

public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int x : nums) {
            update(x + OFFSET, 1);
            total++;
        }
    }

    int add(int val) {
        update(val + OFFSET, 1);
        total++;
        return findKth();
    }
};