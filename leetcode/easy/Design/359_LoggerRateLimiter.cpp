#include "..\..\stdafx.h"
using namespace std;
NS(359)
class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, std::string message) {
        auto p = hashmap.insert(make_pair(message, timestamp));
        if (p.second)
        {
            return true;
        }

        if (timestamp - p.first->second < 10) return false;
        p.first->second = timestamp;
        return true;
    }
    
    unordered_map<string, int> hashmap;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */

END_NS