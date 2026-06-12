class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> left(n + 1), right(n + 1);

        // Generate subset sums for left half
        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = 0, sum = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum += nums[i];
                }
            }

            left[cnt].push_back(sum);
        }

        // Generate subset sums for right half
        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = 0, sum = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum += nums[n + i];
                }
            }

            right[cnt].push_back(sum);
        }

        // Sort right side subset sums
        for (int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int ans = INT_MAX;

        // Choose i elements from left and n-i from right
        for (int i = 0; i <= n; i++) {
            for (int leftSum : left[i]) {

                int target = total / 2 - leftSum;

                auto &vec = right[n - i];

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int s1 = leftSum + *it;
                    int s2 = total - s1;
                    ans = min(ans, abs(s1 - s2));
                }

                if (it != vec.begin()) {
                    --it;
                    int s1 = leftSum + *it;
                    int s2 = total - s1;
                    ans = min(ans, abs(s1 - s2));
                }
            }
        }

        return ans;
    }
};