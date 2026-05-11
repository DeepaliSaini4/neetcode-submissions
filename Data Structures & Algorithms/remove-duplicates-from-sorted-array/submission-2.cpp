class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;//position for the first unique element
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]!=nums[i]){
                //unique elemnt place it
                nums[k++] = nums[i]; 
            }
        }
        return k;

    }
};