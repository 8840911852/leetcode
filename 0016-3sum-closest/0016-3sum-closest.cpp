class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                // Check which sum is closer to target
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }

                // Exact target mil gaya
                if (sum == target) {
                    return sum;
                }

                // Sum chhota hai -> left badhao
                if (sum < target) {
                    left++;
                }
                // Sum bada hai -> right ghatao
                else {
                    right--;
                }
            }
        }

        return closest;
    }
};