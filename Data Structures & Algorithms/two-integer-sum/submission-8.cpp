// class Solution {
//    public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         std::unordered_map<int32_t, uint16_t> um;  // value, idx
//         std::vector<int32_t> vec;
//         if ((nums.size() == 2) && ((nums[0] + nums[1]) == target)) {
//             return {0,1};
//         }
//         for (int i = 0; i < nums.size(); i++) {
//             um.insert({nums[i], i});
//         }
//         for (int i = 0; i < nums.size(); i++) {
//             if (auto search = um.find(target - nums[i]); search != um.end()) {
//                 // vec.push_back(i);
//                 // vec.push_back(search->second);
//                 return {i,search->second};
//                 break;
//             }
//         }
//         return vec;
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;  // val -> index

        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (indices.count(diff) && indices[diff] != i) {
                return {i, indices[diff]};
            }
        }

        return {};
    }
};