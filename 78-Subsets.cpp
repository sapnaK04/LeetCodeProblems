#include <iostream>
#include <vector>

class Solution {
public:
    // Backtracking function to generate subsets
    void backtrack(std::vector<int>& nums, std::vector<std::vector<int>>& result, std::vector<int>& current, int start) {
        // Add the current subset to the result
        result.push_back(current);
        
        // Iterate through the elements starting from `start` index
        for (int i = start; i < nums.size(); ++i) {
            // Include nums[i] in the current subset
            current.push_back(nums[i]);
            // Recursively generate subsets starting from the next element
            backtrack(nums, result, current, i + 1);
            // Backtrack by removing nums[i] (undo the inclusion for the next iteration)
            current.pop_back();
        }
    }

    // Main function to generate subsets
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(nums, result, current, 0); // Start backtrack from index 0
        return result;
    }
};

int main() {
    // Test example
    std::vector<int> nums = {1, 2, 3};
    
    Solution solution;
    std::vector<std::vector<int>> result = solution.subsets(nums);
    
    // Print the result
    std::cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j];
            if (j < result[i].size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]";
        if (i < result.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
    
    return 0;
}
