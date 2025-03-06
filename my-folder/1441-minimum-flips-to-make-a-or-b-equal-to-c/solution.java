class Solution {
    public int minFlips(int a, int b, int c) {
        int result = 0;
        
        for (int i = 0; i < 32; i++) 
        {
            int sla = (a >> i) & 1;
            int slb = (b >> i) & 1;
            int slc = (c >> i) & 1;

            if (slc == 0)
            {
                result += slb + sla;
            }
            else
            {
                result += (slb | sla) ^ 1;
            }
        }
        return result;
    }
}
