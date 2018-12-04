#include "..\..\stdafx.h"
using namespace std;
NS(170)
// use set
//class TwoSum {
//private:
//    unordered_map<int, int> intMaps;
//public:
//    /** Initialize your data structure here. */
//    TwoSum() {
//
//    }
//
//    /** Add the number to an internal data structure.. */
//    void add(int number) {
//        intMaps[number] ++;
//    }
//
//    /** Find if there exists any pair of numbers which sum is equal to the value. */
//    bool find(int value) {
//        for (auto it = intMaps.begin(); it != intMaps.end(); it++)
//        {
//            int other = value - it->first;
//            auto it2 = intMaps.find(other);
//            if (it2 != intMaps.end())
//            {
//                if (other != it->first || it->second > 1)
//                    return true;
//            }
//        }
//        return false;
//    }
//};

// Use array
class TwoSum {
private:
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        // assuming nums is sorted
        // insert 
        nums.push_back(number);
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] > number) i--;
        // i < 0 or nums[i] <= number
        int j = n - 1;
        while (j >= i + 2)
        {
            nums[j] = nums[j - 1];
            j--;
        }
        nums[j] = number;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        int n = nums.size();
        if (n < 2) return false;
        int i = 0;
        int j = n - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] == value) return true;
            if (nums[i] + nums[j] > value) j--;
            else i++;
        }
        return false;
    }
};
END_NS
