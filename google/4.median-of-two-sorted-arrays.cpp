/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n{int(a.size())}, m{int(b.size())};
        // if(n <= 1 && m <= 1)
        // {
        //     if(n == 1 && m == 0) return a[0];
        //     else if(n == 0 && m == 1) return b[0];
        //     return ((a[0] + b[0]) * 1.0) / 2;
        // }
        if(n < m) return findMedianSortedArrays(b, a);
        if(n == m && a[0] > b[0]) return findMedianSortedArrays(b, a);
        if(m == 0)
        {
            if(n&1) return (a[n/2]);
            else return (((a[n/2] + a[n/2 - 1]) * 1.0)/2);
        }

        int s{}, mid{}, e{n};
        int sz = ((n+m)&1) ? ((n+m)/2)+1 : (n+m)/2;
        // e = sz;
        while(s <= e)
        {
            
            mid = (e - s)/2 + s;
            // cout << mid << " " << sz-mid << endl;
            if(sz - mid < 0) 
            {
                e = mid-1;
                continue;
            }
            if(sz - mid > m)
            {
                s = mid + 1;
                continue;
            }
            int l1 = (mid > 0) ? a[mid-1] : INT_MIN;
            int l2 = ((sz - mid) - 1 >= 0) ? b[(sz - mid) - 1] : INT_MIN;

            int r1 = (mid == n) ? INT_MAX : a[mid];
            int r2 = ((sz - mid) < m && (sz-mid) >= 0) ? b[(sz - mid)] : INT_MAX;

            if(l1 <= r2 && l2 <= r1)
            {
                if((n+m)&1)
                {
                    return max(l1, l2);
                }
                else
                {
                    // cout << l1 << ' ' << l2 << ' ' << r1 << ' ' << r2 << '\n';
                    return ((min(r1, r2) + max(l1, l2)) * 1.0) / 2.0;
                }
            }
            else if(l1 > r2)
            {
                e = mid-1;
            }
            else s = mid+1;
        }
        return a[0];
    }
};
// @lc code=end

