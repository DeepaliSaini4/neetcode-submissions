class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, char> mp;
        int head = -1;
        int tail = 0;
        int ans = 0;
        int n = s.length();
        while (tail < n) {
            while (head + 1 < n && mp.find(s[head + 1]) == mp.end()) {
                head++;
                mp[s[head]]++;
            }
            int length = head - tail + 1;
            ans = max(length, ans);
            mp[s[tail]]--;
            if (mp[s[tail]] == 0) {
                mp.erase(s[tail]);
            }
            tail++;
        }
        return ans;
    }
};
