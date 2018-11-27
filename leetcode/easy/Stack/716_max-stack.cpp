#include "..\..\stdafx.h"
using namespace std;
NS(716)
//class MaxStack {
//private:
//    stack<int> _stack;
//    stack<int> _maxStack;
//public:
//    /** initialize your data structure here. */
//    MaxStack() {
//
//    }
//
//    void push(int x) {
//        _stack.push(x);
//        if (!_maxStack.empty())
//            _maxStack.push(max(x, _maxStack.top()));
//        else
//            _maxStack.push(x);
//    }
//
//    int pop() {
//        int v = _stack.top();
//        _stack.pop();
//        _maxStack.pop();
//        return v;
//    }
//
//    int top() {
//        return _stack.top();
//    }
//
//    int peekMax() {
//        return _maxStack.top();
//    }
//
//    int popMax() {
//        int v = _maxStack.top();
//        stack<int> temp;
//        while (!_maxStack.empty() && _maxStack.top() == v)
//        {
//            int value = _stack.top();
//            _maxStack.pop();
//            _stack.pop();
//            if (value != v)
//                temp.push(value);
//            else
//            {
//                break;
//            }
//        }
//
//        while (!temp.empty())
//        {
//            push(temp.top());
//            temp.pop();
//        }
//        return v;
//    }
//};

// using one stack
class MaxStack {
private:
    stack<pair<int, int>> s;
public:
    /** initialize your data structure here. */
    MaxStack() {
    }

    void push(int x) {
        if (s.empty()) s.push(make_pair(x, x));
        else s.push(make_pair(x, max(x, s.top().second)));
    }

    int pop() {
        auto v = s.top();
        s.pop();
        return v.first;
    }

    int top() {
        return s.top().first;
    }

    int peekMax() {
        return s.top().second;
    }

    int popMax() {
        int maxValue = s.top().second;
        stack<int> temp;
        while (s.top().second == maxValue)
        {
            int value = s.top().first;
            s.pop();
            if (value != maxValue) temp.push(value);
            else break;
        }

        while (!temp.empty())
        {
            push(temp.top());
            temp.pop();
        }
        return maxValue;
    }
};

void Test()
{
    MaxStack ms;
    ms.push(5);
    ms.push(1);
    ms.push(5);
    int x = ms.top();
    int y = ms.popMax();
}
/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
END_NS