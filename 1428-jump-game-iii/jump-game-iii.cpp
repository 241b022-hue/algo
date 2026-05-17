class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        queue<int> q;
        vector<int> vis(n, 0);

        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (arr[i] == 0) return true;

            int next1 = i + arr[i];
            int next2 = i - arr[i];

            if (next1 < n && !vis[next1]) {
                vis[next1] = 1;
                q.push(next1);
            }

            if (next2 >= 0 && !vis[next2]) {
                vis[next2] = 1;
                q.push(next2);
            }
        }

        return false;
    }
};