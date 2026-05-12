class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int head = -1;
       int tail = 0;
       int mini = prices[0];
       int pro = 0;
       int n = prices.size();
      for(int i=0;i<n;i++){
        pro = max(pro,prices[i]-mini);
        mini = min(mini,prices[i]);
      }
      return pro;
    }
};
