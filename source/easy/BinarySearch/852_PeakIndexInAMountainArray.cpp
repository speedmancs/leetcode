class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int N = A.size();
        int start = 0; 
        int end = N;
        while (end - start >= 3)
        {
            int mid = start + (end - start) / 2;
            if (A[mid] <= A[start]) end = mid;
            else if(A[mid + 1] > A[mid]) start = mid;
            else end = mid + 1;
        }
        return max_element(A.begin() + start, A.begin() + end) - A.begin();
    }
};