class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // Binary search always on smaller array
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);

        int l = 0, r = m;

        while (l <= r) {
            int p1 = (l + r) / 2;
            int p2 = (m + n + 1) / 2 - p1;

            int max_l1 = (p1 == 0) ? INT_MIN : nums1[p1 - 1];
            int min_r1 = (p1 == m) ? INT_MAX : nums1[p1];

            int max_l2 = (p2 == 0) ? INT_MIN : nums2[p2 - 1];
            int min_r2 = (p2 == n) ? INT_MAX : nums2[p2];

            // Correct partition
            if (max_l1 <= min_r2 && max_l2 <= min_r1) {

                // Even total length
                if ((m + n) % 2 == 0) {
                    return (max(max_l1, max_l2) +
                            min(min_r1, min_r2)) / 2.0;
                }

                // Odd total length
                return max(max_l1, max_l2);
            }

            // Move left
            else if (max_l1 > min_r2) {
                r = p1 - 1;
            }

            // Move right
            else {
                l = p1 + 1;
            }
        }

        return 0.0;
    }
};