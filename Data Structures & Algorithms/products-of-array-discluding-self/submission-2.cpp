class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro = 1;
        int cnt = 0;
        int pro2=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)cnt++;
            pro*=nums[i];
            if(nums[i]!=0){
                pro2*=nums[i];
            }
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(cnt>1) ans.push_back(0);
            else if(nums[i]==0) ans.push_back(pro2);
            else ans.push_back(pro/nums[i]);
        }
        return ans;
    }
};
