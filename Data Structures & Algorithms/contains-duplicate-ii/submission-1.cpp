class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int n = nums.size();
        int head = -1;
        int tail = 0;
        while (tail < n) {
            while (head + 1 < n && head - tail + 1 <= k) {
                if (s.find(nums[head + 1]) != s.end()) return true;
                head++;
                s.insert(nums[head]);
            }
           
                s.erase(nums[tail]);
                tail++;
            
        }
        return false;
    }
};