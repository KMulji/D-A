
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <unordered_map>
#include <set>
#include <algorithm>
using std::set;
using std::string;
using std::unordered_map;
using std::vector;

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
int kDistChars(string s, int k)
{
    int maxLength = std::numeric_limits<int>::min();
    unordered_map<char, int> window;
    int start = 0;

    for (int end = 0; end < s.size(); end++)
    {
        window[s[end]]++;
        while (window.size() > k)
        {
            window[s[start]]--;
            if (window.find(s[start])->second == 0)
            {
                window.erase(s[start]);
            }
            start++;
        }
        maxLength = std::max(end - start + 1, maxLength);
    }

    return maxLength == std::numeric_limits<int>::min() ? 0 : maxLength;
}
int MaxFruits(vector<char> &fruits)
{
    int MaxFruits = 0;
    unordered_map<char, int> basket;
    int start = 0;

    for (int end = 0; end < fruits.size(); end++)
    {
        basket[fruits[end]]++;
        while (basket.size() > 2)
        {
            basket[fruits[start]]--;
            if (basket.find(fruits[start])->second == 0)
            {
                basket.erase(fruits[start]);
            }
        }
        MaxFruits = std::max(end - start + 1, MaxFruits);
    }
    return MaxFruits;
}
int LongestDistinct(string &s)
{
    int LongestLength = 0;
    int start = 0;
    set<char> window;

    for (int end = 0; end < s.size(); end++)
    {

        while (window.find(s[end]) != window.end())
        {
            window.erase(s[start]);
            start++;
        }
        LongestLength = std::max(end - start + 1, LongestLength);
        window.insert(s[end]);
    }

    return LongestLength;
}
int LetterReplace(string s, int k)
{
    int maxLength = 0;
    int start = 0;
    unordered_map<char, int> window;

    for (int end = 0; end < s.size(); end++)
    {
        window[s[end]]++;
        while ((end - start + 1) - std::max_element(window.begin(), window.end(), [](const std::pair<char, int> &p1, const std::pair<char, int> &p2)
                                                    { return p1.second < p2.second; })
                                       ->second >
               k)
        {
            window[s[start]]--;
            if (window.find(s[start])->second == 0)
            {
                window.erase(s[start]);
            }
            start++;
        }
        maxLength = std::max(maxLength, end - start + 1);
    }
    return maxLength;
}
int BinaryReplace(vector<int> &nums, int k)
{
    int rem = k;
    int start = 0;
    int maxLength = 0;
    for (int end = 0; end < nums.size(); end++)
    {
        if (nums[end] == 0)
        {
            rem--;
        }
        while (rem < 0)
        {
            if (nums[start] == 0)
            {
                rem++;
            }
            start++;
        }
        maxLength = std::max(end - start + 1, maxLength);
    }
    return maxLength;
}
bool PermutationString(string s, string pattern)
{
    unordered_map<char, int> one;
    unordered_map<char, int> window;
    int start = 0;
    for (auto x : pattern)
    {
        one[x]++;
    }
    for (int end = 0; end < s.size(); end++)
    {
        window[s[end]]++;
        if (end - start + 1 == pattern.size())
        {
            if (window == one)
            {
                return true;
            }
            window[s[start]]--;
            if (window.find(s[start])->second == 0)
            {
                window.erase(s[start]);
            }
            start++;
        }
    }
    return false;
}
int atMostK(vector<int> &nums, int k)
{
    int start = 0;
    int res = 0;
    unordered_map<int, int> count;
    for (int end = 0; end < nums.size(); end++)
    {
        count[nums[end]]++;
        if (count.find(nums[end])->second == 1)
        {
            k--;
        }
        while (k < 0)
        {
            count[nums[start]]--;
            if (count.find(nums[start])->second == 0)
            {
                k++;
            }
            start++;
        }
        res += end - start + 1;
    }
    return res;
}
int subarraysWithKDistinct(vector<int> &A, int K)
{
    int i = atMostK(A, K);
    int j = atMostK(A, K - 1);
    return i - j;
}
int AtMost2(vector<int> &nums, int k)
{

    int start = 0;
    int res = 0;

    for (int end = 0; end < nums.size(); end++)
    {
        // if its odd
        if (nums[end] % 2 != 0)
        {
            k--;
        }

        while (k < 0)
        {
            if (nums[start] % 2 != 0)
            {
                k++;
            }

            start++;
        }
        res += (end - start) + 1;
    }
    return res;
}
int numberOfSubarrays(vector<int> &nums, int k)
{
    int i = AtMost2(nums, k);
    int j = AtMost2(nums, k - 1);
    return i - j;
}
int AtMost3(vector<int> &nums, int goal)
{
    int start = 0;
    int res = 0;
    int windowSum = 0;

    for (int end = 0; end < nums.size(); end++)
    {
        windowSum += nums[end];

        while (windowSum > goal)
        {
            windowSum -= nums[start];
            start++;
        }
        res += (end - start) + 1;
    }
    return res;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int i = AtMost3(nums, goal);
    int j = AtMost3(nums, goal - 1);
    return i - j;
}
int main()
{
    vector<int> test = {0, 0, 0, 0, 0};
    numSubarraysWithSum(test, 0);
    return 0;
}