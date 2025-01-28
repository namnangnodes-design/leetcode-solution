/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long int low = 0;
        long long int high = n;
        long long int mid = (high + low) / 2;
        int pick = guess(mid);
        while (pick != 0)
        {
            if (pick == -1)
            {
                high = mid - 1;
            }
            else if (pick == 1)
            {
                low = mid + 1;
            }
            mid = (high + low) / 2;
            pick = guess(mid);
        }
        return mid;
    }
};
