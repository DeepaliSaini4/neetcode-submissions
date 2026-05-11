class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        int one = nums[0];
        int two = nums[1];
        int cnt1 = 0;
        int cnt2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == one) {
                cnt1++;
            } else if (nums[i] == two) {
                cnt2++;
            } else {
                if (cnt1 == 0) {
                    one = nums[i];
                    cnt1 = 1;
                } else if (cnt2 == 0) {
                    two = nums[i];
                    cnt2 = 1;
                } else {
                    cnt1--;
                    cnt2--;
                }
            }}
            cnt1 = cnt2 = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] == one) {
                    cnt1++;
                } else if (nums[i] == two) {
                    cnt2++;
                }
            }
            vector<int> ans;

            if (cnt1 > n / 3) ans.push_back(one);
            if (one == two) return ans;
            if (cnt2 > n / 3) ans.push_back(two);
            return ans;
        }
    };