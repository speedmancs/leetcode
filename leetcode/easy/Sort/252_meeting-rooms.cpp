#include "..\..\stdafx.h"
using namespace std;
NS(937)
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b)
        {
            return a.end < b.end;
        });

        int n = intervals.size();
        if (n == 0) return true;
        int i = 1;
        int ending = intervals[0].end;
        while (i < n)
        {
            if (intervals[i].start < ending)
                return false;
            ending = intervals[i].end;
            i++;
        }
        return true;
    }
};
END_NS