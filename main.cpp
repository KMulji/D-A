
#include <iostream>
#include <vector>
#include <string>
#include <limits>
using std::vector;
using std::string;

int maxSubArraySizeK(vector<int> &nums, int k)
{
    int windowSum = 0;
    int maxSum = std::numeric_limits<int>::min();
    int start = 0;

    for (int end = 0; end < nums.size(); end++)
    {
        windowSum += nums[end];
        if (end - start + 1 == k)
        {
            maxSum = std::max(maxSum, windowSum);
            windowSum -= nums[start];
            start++;
        }
    }

    return maxSum;
}
int minSubArrayLen(int target, vector<int> &nums)
{
    int minLength = std::numeric_limits<int>::max();
    int windowSum = 0;
    int start = 0;
    for (int end = 0; end < nums.size(); end++)
    {
        windowSum += nums[end];
        while (windowSum >= target)
        {
            minLength = std::min(minLength, end - start + 1);
            windowSum -= nums[start];
            start++;
        }
    }
    return minLength == std::numeric_limits<int>::max() ? 0 : minLength;
}
int kDistChars(string s,int k){
    int maxLength = std::numeric_limits<int>::min();
}
int main()
{
    vector<int> maxSumTest1 = {2, 1, 5, 1, 3, 2};
    vector<int> maxSumTest2 = {2, 3, 4, 1, 5};
    int k1 = 3;
    int k2 = 2;
    std::cout << "test 1 is->" << maxSubArraySizeK(maxSumTest1, k1) << std::endl;
    std::cout << "test 2 is->" << maxSubArraySizeK(maxSumTest2, k2) << std::endl;
    return 0;
}