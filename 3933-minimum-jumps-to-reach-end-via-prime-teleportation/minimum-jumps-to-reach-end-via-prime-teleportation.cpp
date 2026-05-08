class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> spf(mx + 1);
        for (int i = 0; i <= mx; i++) spf[i] = i;

        for (long long i = 2; i * i <= mx; i++) {
            if (spf[i] == i) {
                for (long long j = i * i; j <= mx; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }

        unordered_map<int, vector<int>> divs;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            unordered_set<int> seen;

            while (x > 1) {
                int p = spf[x];
                if (!seen.count(p)) {
                    divs[p].push_back(i);
                    seen.insert(p);
                }
                x /= p;
            }
        }

        queue<int> q;
        vector<int> dist(n, -1);
        unordered_set<int> usedPrime;

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1) return dist[i];

            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = dist[i] + 1;
                q.push(i + 1);
            }

            int x = nums[i];

            if (x >= 2 && spf[x] == x && !usedPrime.count(x)) {
                usedPrime.insert(x);

                for (int idx : divs[x]) {
                    if (idx != i && dist[idx] == -1) {
                        dist[idx] = dist[i] + 1;
                        q.push(idx);
                    }
                }
            }
        }

        return -1;
    }
};