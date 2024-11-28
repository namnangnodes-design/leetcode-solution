class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x<0:
            return False
        else:
            strNum = str(x)
            revStr = strNum[::-1]
            if strNum == revStr:
                return True
            else:
                return False
