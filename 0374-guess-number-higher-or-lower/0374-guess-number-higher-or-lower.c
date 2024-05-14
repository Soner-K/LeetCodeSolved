/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n){
	int left = 1;
    int right = INT_MAX;
    int8_t  isNumber = guess(n);

    while (isNumber)
    {
        n = left + (right - left) / 2;
        isNumber = guess(n);
        if (isNumber == 0)
            break ;
        else if (isNumber == 1)
            left = n + 1;
        else
            right = n - 1;
    }
    return (n);
}


