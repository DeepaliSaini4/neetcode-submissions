class Solution {
public:
    int calPoints(vector<string>& operations) {

        vector<int> record;

        int sum = 0;

        // TC: O(n)
        for(auto op : operations) {

            // remove previous score
            if(op == "C") {

                sum -= record.back();

                record.pop_back();
            }

            // double previous score
            else if(op == "D") {

                int val = 2 * record.back();

                record.push_back(val);

                sum += val;
            }

            // sum of previous two scores
            else if(op == "+") {

                int n = record.size();

                int val = record[n - 1] + record[n - 2];

                record.push_back(val);

                sum += val;
            }

            // normal integer score
            else {

                int val = stoi(op);

                record.push_back(val);

                sum += val;
            }
        }

        // TC: O(n)
        // SC: O(n)
        return sum;
    }
};