class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int32_t, uint16_t> um;  // value, idx

        for (int i = 0; i < nums.size(); i++) {
            //um.insert({nums[i], i});
            um[nums[i]] = i;
        }
        cout << "\n Size of map = " << um.size() << std::endl;

        for (int i = 0; i < nums.size(); i++) {
            auto diff = target - nums[i];
            if (um.count(diff) && um[diff] != i) {
                return {i, um[diff]};
            }
        }
        return {};
    }
};
