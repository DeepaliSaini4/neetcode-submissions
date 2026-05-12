class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int head = -1;
        int tail = 0;
        int ans = 1e9;
        int n = nums.size();
        while (tail < n) {
            while (head + 1 < n && sum < target) {
                head++;
                sum += nums[head];
            }
            if (sum >= target) {
                ans = min(ans, head - tail + 1);
            }
            if (tail > head) {
                tail++;
                head = tail - 1;
            } else {
                // release
                sum -= nums[tail];

                tail++;
            }
        }
        if (ans == 1e9) {
            return 0;
        }
        return ans;
    }
};