class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>us;
        for(int i=0;i<nums.size();i++){
            us.insert(nums[i]);
        }
        int ans = 0;
        for(auto it:us){
            //start only from the begining of the sequence of numbers
            if(us.find(it-1)==us.end()){
                int curr = it;
                int count=1;
                while(us.find(curr+1)!=us.end()){
                    curr = curr+1;
                    count++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};
