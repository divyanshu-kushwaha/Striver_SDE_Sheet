// https://leetcode.com/problems/powx-n/submissions/

class Solution
{
public:
    double myPow(double x, int n)
    {
        bool flag1 = 0, flag2 = 0, flag3 = 0;
        if(x<0) flag1 = 1;
        if(n<0) flag2 = 1;
        x = abs(x);
        n = abs(n);
        if(n%2) flag3 = 1;
        double res = 1;
        while (n > 0)
        {
            if (n & 1)
                res = res * x;
            x = x * x;
            n >>= 1;
        }
        cout << res << "\n";
        if(flag2) res = 1/res;
        
        if(flag1 and flag3) res = -res;
        return res;
    }
};