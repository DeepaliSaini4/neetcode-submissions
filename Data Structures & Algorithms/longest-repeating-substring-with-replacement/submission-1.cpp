class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int head = -1;
        int tail = 0;
        int left = 0;
        int maxf = 0;
        int ans = 0;
        vector<int>hash(26,0);
        while(tail<n){
            while(head+1<n && left<=k){
                //a check before entering the next character as it could be valid or invalid both
                //if invalid we terminate our search
                int idx = hash[s[head+1]-'A'];
                int newmaxf = max(maxf,idx+1);
                int newlen = (head+1) - tail + 1;
                if(newlen-newmaxf>k){
                    break;
                }
                head++;
                hash[s[head]-'A']++;
                maxf = max(maxf,hash[s[head]-'A']);
                left = (head-tail+1) - maxf;
            }
            ans = max(head-tail+1,ans);
            hash[s[tail]-'A']--;
            tail++;
        }
        return ans;
    }
};
