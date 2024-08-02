//Here’s a C++ implementation for finding the maximum sum subarray using Kadanes's Algorithm:

int kadaneAlgorithm(const std::vector<int>& nums) {
    int maxCurrent = nums[0];
    int maxGlobal = nums[0];
    
    for (size_t i = 1; i < nums.size(); ++i) {
        // Update maxCurrent to be the maximum of the current element
        // or the sum of maxCurrent and the current element
        maxCurrent = std::max(nums[i], maxCurrent + nums[i]);
        
        // Update maxGlobal to be the maximum of itself or maxCurrent
        maxGlobal = std::max(maxGlobal, maxCurrent);
    }
    
    return maxGlobal;
}

int main() {
    std::vector<int> nums = {1, -2, 3, 4, -1, 2, 1, -5, 4};
    std::cout << "Maximum sum subarray: " << kadaneAlgorithm(nums) << std::endl;
    return 0;
}

//// kadanes but reverse kadane's algorithms Minimum Subarray Sum (Negative Kadane's) in c++ code 
int minSubarraySum(const std::vector<int>& nums) {
    int min_so_far = INT_MAX; // Initialize to the maximum possible value
    int min_ending_here = 0;

    for (int num : nums) {
        min_ending_here += num; // Add the current element to the running total
        min_so_far = std::min(min_so_far, min_ending_here); // Update the minimum so far
        if (min_ending_here > 0) {
            min_ending_here = 0; // Reset if positive, as we're looking for minimum
        }
    }

    return min_so_far;
}

int main() {
    std::vector<int> nums = {3, -4, 2, -3, -1, 7, -5};
    std::cout << "Minimum Subarray Sum: " << minSubarraySum(nums) << std::endl;
    return 0;
}


 // Kadane's algorithm to find the maximum sum with all numbers inverted
    int kadane_inverse(const std::vector<int>& nums) {
        int max_so_far = INT_MIN;
        int max_ending_here = 0;
        for (int num : nums) {
            max_ending_here -= num; // Inverting the sign
            max_so_far = std::max(max_so_far, max_ending_here);
            if (max_ending_here < 0) {
                max_ending_here = 0;
            }
        }
        return max_so_far;
    }
##Subarray with Maximum Product:  explain with kadane;s algo 
int maxProduct(const std::vector<int>& nums) {
    if (nums.empty()) return 0;

    int maxSoFar = nums[0];
    int maxEndingHere = nums[0];
    int minEndingHere = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        int num = nums[i];

        // If the current number is negative, max and min swap
        if (num < 0) {
            std::swap(maxEndingHere, minEndingHere);
        }

        // Update maxEndingHere and minEndingHere
        maxEndingHere = std::max(num, maxEndingHere * num);
        minEndingHere = std::min(num, minEndingHere * num);

        // Update maxSoFar
        maxSoFar = std::max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

int main() {
    std::vector<int> nums = {2, 3, -2, 4};
    std::cout << "Maximum Product Subarray: " << maxProduct(nums) << std::endl;
    return 0;
}

####   Finding the Subarray with the Given Sum:  give me kadanes apporach 
subarrayWithGivenSum(const std::vector<int>& nums, int S) {
    std::unordered_map<int, int> prefixSumMap;
    int currentSum = 0;

    for (int i = 0; i < nums.size(); ++i) {
        currentSum += nums[i];

        // Check if the current prefix sum is equal to S
        if (currentSum == S) {
            return std::vector<int>(nums.begin(), nums.begin() + i + 1);
        }

        // Check if currentSum - S exists in the map
        if (prefixSumMap.find(currentSum - S) != prefixSumMap.end()) {
            return std::vector<int>(nums.begin() + prefixSumMap[currentSum - S] + 1, nums.begin() + i + 1);
        }

        // Store the current prefix sum in the map
        prefixSumMap[currentSum] = i;
    }

    // If no subarray found, return an empty vector
    return {};
}

int main() {
    std::vector<int> nums = {10, 2, -2, -20, 10};
    int targetSum = -10;

    std::vector<int> result = subarrayWithGivenSum(nums, targetSum);

    if (!result.empty()) {
        std::cout << "Subarray with given sum: ";
        for (int num : result) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No subarray found with given sum." << std::endl;
    }

    return 0;
}
##Largest subarray with 0 sum
Difficulty: MediumAccuracy: 41.84%Submissions: 312K+Points: 4
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.///###


int findMaxLenRec(vector<int>& arr, int n, int start) {
    // Base case: If start index reaches the end of the array
    if (start == n) {
        return 0;
    }

    int maxLen = 0;
    int sum = 0;

    // Check all subarrays starting from `start`
    for (int end = start; end < n; ++end) {
        sum += arr[end];
        if (sum == 0) {
            maxLen = max(maxLen, end - start + 1);
        }
    }

    // Recursively check for the next starting point
    return max(maxLen, findMaxLenRec(arr, n, start + 1));
}

int maxLen(vector<int>& arr, int n) {
    return findMaxLenRec(arr, n, 0);
}

///longestConsecutive(vector<int>& nums)
  int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        int cnt = 1;
        int max_length = 1;
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1] + 1) {
                cnt++;
            } else if (nums[i] != nums[i-1]) {
                cnt = 1; // Reset count if the numbers are not consecutive
            }
            max_length = max(max_length, cnt);
        }

        return max_length;
    }
