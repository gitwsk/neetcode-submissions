class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if (nums.size() && nums.size()>2) {
            for (int i=0; i < nums.size(); i++) {
                for(int j = i+1; j < nums.size(); j++) {
                    if (nums[i] == nums[j]) {
                        return true;
                    }
                }
            }
        }
        else if (nums.size() == 2) {
            if (nums[0] == nums[1]) {
                return true;
            }
        }
        return false;
    }
};