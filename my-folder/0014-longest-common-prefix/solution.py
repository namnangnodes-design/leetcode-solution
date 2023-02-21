class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        comStr=""
        preStr=""
        i = 0
        common = True
        while(common==True):
            if len(preStr)>len(comStr):
                comStr=preStr
            if i==len(strs[0]):
                break
            preStr+=strs[0][i]
            for str in strs:
                if str.startswith(preStr)==False:
                    common=False
                    break
            i+=1


        return comStr
