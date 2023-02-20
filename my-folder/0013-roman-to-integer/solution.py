class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans=0
        numArr=[]

        for _ in s:
            if _ == "I":
                numArr.append(1)
            if _ == "V":
                numArr.append(5)
            if _ == "X":
                numArr.append(10)
            if _ == "L":
                numArr.append(50)
            if _ == "C":
                numArr.append(100)
            if _ == "D":
                numArr.append(500)
            if _ == "M":
                numArr.append(1000)
        
         

        for i in range(len(numArr)):
            if i<len(numArr)-1:
                if (numArr[i]<numArr[i+1]):
                    ans-=int(numArr[i])
                else:
                    ans+=int(numArr[i])
            else:
                ans+=int(numArr[i])
        
        return ans
