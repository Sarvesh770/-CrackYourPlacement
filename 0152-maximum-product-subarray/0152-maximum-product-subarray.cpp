class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto maxProductSubarray = [](vector<int>& v) {
            int n = v.size();
            if (n == 0) return 0; // If the subarray is empty, return 0
            if (n == 1) return v[0]; // If the subarray has only one element, return that element

            int neg = 0; // Count of negative numbers
            for (auto i : v) {
                if (i < 0) neg++;
            }

            int product = 1;
            // If the number of negative numbers is even, the product of the entire subarray is the max product
            if (neg % 2 == 0) {
                for (auto i : v) product *= i;
                return product;
            }

            // Finding the indices of the first and last negative numbers
            int first_neg = -1;
            int last_neg = -1;
            for (int i = 0; i < n; ++i) {
                if (v[i] < 0) {
                    if (first_neg == -1) first_neg = i;
                    last_neg = i;
                }
            }

            // Calculating product excluding first negative and last negative numbers
            int prod1 = 1, prod2 = 1, prod3 = 1, prod4 = 1;
            for (int i = 0; i < first_neg; ++i) {
                prod1 *= v[i];
            }
            for (int i = first_neg + 1; i < n; ++i) {
                prod2 *= v[i];
            }
            for (int i = 0; i < last_neg; ++i) {
                prod3 *= v[i];
            }
            for (int i = last_neg + 1; i < n; ++i) {
                prod4 *= v[i];
            }

            // Return the maximum product obtained from different subarray segments
            return max({prod1, prod3, prod2, prod4});
        };

        vector<vector<int>> subarrays;
        vector<int> temp;
        bool zeroPresent = false;
        int n = nums.size();

        // Splitting the array into subarrays separated by zeroes
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                temp.push_back(nums[i]);
            } else {
                if (!temp.empty()) {
                    subarrays.push_back(temp);
                    temp.clear();
                }
                zeroPresent = true; // Mark that zero is present in the array
            }
        }

        // Push the last subarray if it's non-empty
        if (!temp.empty()) {
            subarrays.push_back(temp);
        }

        int maxProduct = INT_MIN;
        // Calculate max product for each subarray
        for (auto& subarray : subarrays) {
            maxProduct = max(maxProduct, maxProductSubarray(subarray));
        }

        // If zero is present, consider the product of zero
        if (zeroPresent) {
            maxProduct = max(maxProduct, 0);
        }

        return maxProduct;
    }
};