class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        vector<int> charset(26, 0);
        int head = -1;
        int tail = 0;
        int n = s2.size();
        int cnt = s1.size();
        for (auto it : s1) {
            charset[it - 'a']++;
        }
        while (tail < n) {
            while (head + 1 < n && charset[s2[head + 1] - 'a']) {
                head++;
                cnt--;
                charset[s2[head] - 'a']--;
                if (cnt == 0) return true;
            }
            if (tail > head) {
                tail++;
                head = tail - 1;
            } else {
               
                    charset[s2[tail] - 'a']++;
                    cnt++;
                    tail++;
            }
        }
        return false;
    }
};
