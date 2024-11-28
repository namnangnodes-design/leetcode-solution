class Solution {
public:
int c[20];int n = 0;
bool isPalindrome(int x){
if(x<0) return false;
do{
	c[n] = x%10; x /= 10; n++;
}while(x > 0);
for(int i =0; i<n/2; i++) if (c[i] != c[n-i-1]) return false;
return true;
}

};
