class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start_idx = 0;
        int end_idx = nums.size() - 1;

        while (start_idx <= end_idx) {
            // Calculate the correct midpoint dynamically each loop
            int mid = start_idx + (end_idx - start_idx) / 2;

            if (nums[mid] == target) {
                return mid; // Target found
            } else if (target < nums[mid]) {
                end_idx = mid - 1; // Search left half
            } else {
                start_idx = mid + 1; // Search right half
            }
        }
        return -1; // Target not found
    }
};
