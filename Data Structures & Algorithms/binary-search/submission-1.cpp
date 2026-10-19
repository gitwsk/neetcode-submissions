class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1 && target == nums[0]) {
            return 0;
        }
        int start_idx = 0;
        int end_idx = nums.size() - 1;

        while (start_idx <= end_idx) {
            int mid = start_idx + (end_idx - start_idx)/2;
            if (target == nums[mid]) {
                return mid;
            }  if (target < nums[mid]) {
                end_idx = mid - 1;
            }  else {
                start_idx = mid + 1;
            }
        }
        return -1;
    }
};
