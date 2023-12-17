class Solution {
public:
    bool predicate(vector<int>& nums, int len, long long k) {
        int i = len / 2, j = len;
        long long sum1 = 0, sum2 = 0;
        for (int x = 0; x < i; x++)
            sum1 += nums[x];
        for (int x = (len + 1) / 2; x < j; x++)
            sum2 += nums[x];
        if (sum2 - sum1 <= k)
            return 1;
        while (j < nums.size()) {
            sum1 += nums[i];
            sum2 += nums[j];
            sum1 -= nums[i - len / 2];
            sum2 -= nums[j - len / 2];
            if (sum2 - sum1 <= k)
                return 1;
            i++;
            j++;
        }
        return 0;
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int l = 1, h = nums.size(), ans;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (predicate(nums, mid, k)) {
                ans = mid;
                l = mid + 1;
            }
            else
                h = mid - 1;
        }
        return ans;
    }
};
