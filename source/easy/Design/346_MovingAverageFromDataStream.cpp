#include <queue>
using namespace std;
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sumSoFar = 0;
        count = 0;
        capacity = size;
    }
    
    double next(int val) {
        sumSoFar += val;
        window.push(val);
        if (count < capacity){
            count ++;
        }
        else
        {
            sumSoFar -= window.front();
            window.pop();
        }

        return sumSoFar / (double)count;
    }
    int sumSoFar;
    int count;
    int capacity;
    queue<int> window;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */