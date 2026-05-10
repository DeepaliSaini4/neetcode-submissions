class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int d = 0;
        int k = nums.size()-1;
        while(d<=k){
            if(nums[d]==0){
                swap(nums[i++],nums[d++]);
            }else if(nums[d]==2){
                swap(nums[d],nums[k--]);
            }
            else d++;
        }
        return;
    }
};