class Solution {
public:
    int trap(vector<int>& height) {

        int l = 0;
        int r = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;

        int water = 0;

        // TC: O(n)
        while(l < r) {

            // left side is bottleneck
            if(height[l] < height[r]) {

                leftMax = max(leftMax, height[l]);

                water += leftMax - height[l];

                l++;
            }

            // right side is bottleneck
            else {

                rightMax = max(rightMax, height[r]);

                water += rightMax - height[r];

                r--;
            }
        }

        // TC: O(n)
        // SC: O(1)
        return water;
    }
};