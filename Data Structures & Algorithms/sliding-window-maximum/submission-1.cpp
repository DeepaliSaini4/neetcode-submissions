class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
     deque<int> dq; // stores indices

        vector<int> ans;

        int n = nums.size();

        // TC: O(n)
        for(int i = 0; i < n; i++) {

            // remove expired indices
            // outside current window
            while(!dq.empty() && dq.front() <= i - k) {

                dq.pop_front();
            }

            // remove smaller useless elements
            while(!dq.empty() &&
                  nums[dq.back()] <= nums[i]) {

                dq.pop_back();
            }

            // push current index
            dq.push_back(i);

            // first valid window formed
            if(i >= k - 1) {

                ans.push_back(nums[dq.front()]);
            }
        }

        // TC: O(n)
        // SC: O(k)
        return ans;
    }
};
