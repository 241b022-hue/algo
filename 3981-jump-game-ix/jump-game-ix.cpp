class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n);
        suf[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            suf[i] = min(suf[i + 1], nums[i]);
        }

        vector<int> ans(n);
        int l = 0, mx = nums[0], pref = nums[0];

        for (int i = 0; i < n - 1; ++i) {
            pref = max(pref, nums[i]);
            mx = max(mx, nums[i]);

            if (pref <= suf[i + 1]) {
                for (int j = l; j <= i; ++j) {
                    ans[j] = mx;
                }
                l = i + 1;
                if (l < n) {
                    mx = nums[l];
                    pref = nums[l];
                }
            }
        }

        mx = nums[l];
        for (int i = l; i < n; ++i) {
            mx = max(mx, nums[i]);
        }

        for (int i = l; i < n; ++i) {
            ans[i] = mx;
        }

        return ans;
    }
};