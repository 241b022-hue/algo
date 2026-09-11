class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if (n <= 2) {
            return n;
        }

        int result = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<double, int> mp;
            int duplicate = 1;
            int localMax = 0;

            for (int j = i + 1; j < n; j++) {
                if (points[i][0] == points[j][0] &&
                    points[i][1] == points[j][1]) {
                    duplicate++;
                }
                else if (points[i][0] == points[j][0]) {
                    mp[1e9]++;
                    localMax = max(localMax, mp[1e9]);
                }
                else {
                    double slope =
                        (double)(points[j][1] - points[i][1]) /
                        (double)(points[j][0] - points[i][0]);

                    mp[slope]++;
                    localMax = max(localMax, mp[slope]);
                }
            }

            result = max(result, localMax + duplicate);
        }

        return result;
    }
};