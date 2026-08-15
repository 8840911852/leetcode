class Solution {
public:
    int maxArea(vector<int>& height) {

        int min_height = height[0];
        int max_height = height[height.size() - 1];

        int min_idx = 0;
        int max_idx = height.size() - 1;

        if (max_height < min_height) {
            min_height = max_height;
            min_idx = max_idx;

            max_height = height[0];
            max_idx = 0;
        }

        int w = abs(max_idx - min_idx);
        int max_area = min_height * w;

        while (w > 0) {

            int idx = min_idx;

            while (idx >= 0 && idx < height.size() &&
                   height[idx] <= min_height) {

                if (min_idx < max_idx)
                    idx++;
                else
                    idx--;

                if (idx < 0 || idx >= height.size())
                    break;
            }

            if (idx < 0 || idx >= height.size())
                break;

            if (height[idx] > max_height) {
                min_height = max_height;
                min_idx = max_idx;

                max_height = height[idx];
                max_idx = idx;
            } else {
                min_idx = idx;
                min_height = height[idx];
            }

            w = abs(max_idx - min_idx);

            max_area = max(max_area, w * min_height);
        }

        return max_area;
    }
};