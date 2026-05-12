class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> need(128, 0);
        // SC: O(128) = O(1)

        for(char c : t) {
            need[c]++;
        }

        int cnt = t.size(); // chars still needed

        int head = -1;
        int tail = 0;

        int bestLen = 1e9;
        int bestStart = 0;

        int n = s.size();

        // TC: O(2n)
        while(tail < n) {

            // acquire until window becomes valid
            while(head + 1 < n && cnt > 0) {
                head++;

                // if this char was needed
                if(need[s[head]] > 0) {
                    cnt--;
                }

                need[s[head]]--;
            }

            // valid window
            if(cnt == 0) {
                int len = head - tail + 1;

                if(len < bestLen) {
                    bestLen = len;
                    bestStart = tail;
                }
            }

            // release from left
            if(tail > head) {
                tail++;
                head = tail - 1;
            }
            else {
                need[s[tail]]++;

                // if after release this char becomes needed again
                if(need[s[tail]] > 0) {
                    cnt++;
                }

                tail++;
            }
        }

        // TC: O(n)
        // SC: O(1)
        if(bestLen == 1e9) return "";

        return s.substr(bestStart, bestLen);
    }
};