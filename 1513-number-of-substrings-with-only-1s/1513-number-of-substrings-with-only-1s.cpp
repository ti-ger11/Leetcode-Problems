class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1000000007LL;
        long long run = 0;
        long long ans = 0;

        for (char c : s) {
            if (c == '1') {
                run++;
            } else {
                if (run > 0) {
                    // add run*(run+1)/2 safely under modulo
                    long long add = (run * (run + 1) / 2) % MOD;
                    ans = (ans + add) % MOD;
                    run = 0;
                }
            }
        }
        if (run > 0) {
            long long add = (run * (run + 1) / 2) % MOD;
            ans = (ans + add) % MOD;
        }

        return static_cast<int>(ans);
    }
};
