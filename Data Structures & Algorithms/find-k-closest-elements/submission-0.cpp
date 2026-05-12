class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int n = arr.size();

        int head = n - 1;
        int tail = 0;

        // remove farther elements
        // TC: O(n-k)
        while(head - tail + 1 > k) {

            // left farther from x
            if(abs(arr[tail] - x) > abs(arr[head] - x)) {

                tail++;
            }

            // right farther from x
            else {

                head--;
            }
        }

        vector<int> ans;

        // remaining valid window
        // TC: O(k)
        for(int i = tail; i <= head; i++) {

            ans.push_back(arr[i]);
        }

        // TC: O(n)
        // SC: O(k)
        return ans;
    }
};