class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>v;
        int n = speed.size();
        if(n == 0) return 0;
        for(int i=0;i<n;i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end(),[](const pair<int,int>&a, const pair<int,int>&b){
            return a.first<b.first;
        });
        stack<double>m;
        vector<double>t;
        for(auto it:v){
            t.push_back((double)(target-it.first)/it.second);
        }
        m.push(t[n-1]);
        for(int k=n-2;k>=0;k--){
            if(t[k]>m.top()){
                m.push(t[k]);
            }
        }
        return m.size();
    }
};
