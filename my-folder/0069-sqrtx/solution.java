class Solution {
    public int mySqrt(int x) { 
        if (x==0 || x == 1) return x;
        long start = 1;
        long end = x;
        while (start <= end) {
            long mid = start + (end - start)/2;
            if (mid * mid > (long)x) {
                end = mid - 1;
            } else if (mid * mid < (long)x) {
                start = mid + 1;
            } else {
                return (int)mid;
            }
        }
        return (int)end;
    }
}
