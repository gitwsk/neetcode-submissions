class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int longest = 1;
        int curr_longest = 0;
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return 1;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = 1;
        }
        if (map.size() == 1) return 1;

        for (auto iter = map.begin(); iter != map.end(); ++iter) {
            std::cout << iter->first << " : " << iter->second << endl;
        }
        std::cout << endl;

        for (const auto& [key, value] : map) {
            curr_longest = 1;
            int temp = key;
            std::cout <<"^^^^^^^^^\ncurr key : value <-> "<<key<<" : "<<value<<endl;
            if (auto search1 = map.find(key - 1); search1 != map.end()) {

            }
            else {
                for (int i=0; i<map.size();i++) {
                    if (auto search2 = map.find(++temp); search2 != map.end()) {
                        curr_longest++;
                        continue;
                    }
                    else {
                        break;
                    }
                }
            }
            // if (auto search2 = map.find(key + 1); search2 != map.end()) {
            //     curr_longest = curr_longest + 1;
            //     map[key] = curr_longest;
            //     std::cout << "Not Found : curr_longest <-> " << search2->first << " : " << curr_longest
            //               << endl;
            // }
            // std::cout <<"UPDATED curr key : value <-> "<<key<<" : "<<map[key]<<endl;
            if (curr_longest > longest) {
                longest = curr_longest;
            }
        }

        return longest;
    }
};
