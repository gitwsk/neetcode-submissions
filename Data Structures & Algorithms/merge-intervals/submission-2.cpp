class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size == 0) {
            return {};
        } 
        
        if (size == 1) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end());

        for (auto inter : intervals) {
            cout<<"{ "<<inter[0]<<inter[1]<<" }";
        }

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i=1; i<size; i++) {
            auto &last = merged.back();
            if (intervals[i][0] <= last[1]) {
                if (intervals[i][1] >= last[1]) {
                    //Merge
                    last[1] = intervals[i][1]; 
                } else {
                    //Absorb //Nothing to do
                }
            } else { //No merge, so just add
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};
