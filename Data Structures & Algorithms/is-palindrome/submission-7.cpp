class Solution {
   public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;  // one minus size as 0 based
        // O(n)
        while (l < r) {
            while (l < r && !isalnum(s[l])) l++;  // skipping multiple invalid characters
            while (l < r && !isalnum(s[r])) r--;  // skipping multiple invalid characters
            if (l <= r) {
                if (tolower(s[l]) != tolower(s[r])) return false;  // converting to lower to unify
                l++;                                               // increment if a match
                r--;                                               // decreement if a match
            }
        }
        return true;  // met no false case
    }
};
