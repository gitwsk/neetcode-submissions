class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int longest = 1;
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return 1;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = 1;
        }
        if (map.size() == 1) return 1;

        // for (auto iter = map.begin(); iter != map.end(); ++iter) {
        //     std::cout << iter->first << " : " << iter->second << endl;
        // }
        // std::cout << endl;

        for (const auto& [key, value] : map) {
            int curr_longest = 1;
            int temp = key;
            if (auto search1 = map.find(key - 1); search1 != map.end()) {
                //Found so this key is not the start of a sequence
            }
            else {
                for (int i=0; i<map.size();i++) {
                    if (auto search2 = map.find(++temp); search2 != map.end()) {
                        //Run through consecutive keys for all nos. that are start of sequence
                        curr_longest++;
                    }
                    else {
                        break;
                    }
                }
            }
            if (curr_longest > longest) {
                longest = curr_longest;
            }
        }

        return longest;
    }
};
