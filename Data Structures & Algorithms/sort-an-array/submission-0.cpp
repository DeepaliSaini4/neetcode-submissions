class Solution {
public:

    void merge(vector<int>&nums,int l,int m, int r){
        int i = l;
        int j = m+1;
        vector<int>v;
        while(i<=m && j<=r){
            if(nums[i]<nums[j]){
                v.push_back(nums[i]);
                i++;
            }else{
                v.push_back(nums[j++]);
            }
        }
        while(i<=m){
            v.push_back(nums[i++]);
        }
        while(j<=r){
            v.push_back(nums[j++]);
        }

        for(int k=l;k<=r;k++){
            nums[k] = v[k-l];
        }

    }
    
    void ms(vector<int>&nums,int l,int r){
        if(l>=r) return;
        int mid = (l+r)/2;
        ms(nums,l,mid);
        ms(nums,mid+1,r);
        merge(nums,l,mid,r);
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        ms(nums,0,nums.size()-1);
        return nums;
    }
};