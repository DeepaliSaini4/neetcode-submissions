class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp; 
        for(auto it :strs){
            auto copy = it;
            sort(it.begin(),it.end());//n*klogk
            mp[it].push_back(copy);
        }
        vector<vector<string>>fans; 
        for(auto it2:mp){
            vector<string>ans;
            for(auto it3:it2.second){
                ans.push_back(it3);//logn
            }
            fans.push_back(ans);
        }
        return fans;
    }
};
//O(nlogn+n*klogk) = n*klogk
