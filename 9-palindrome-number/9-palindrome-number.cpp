class Solution {
public:
    bool isPalindrome(int x) {
      if(x<0) return false;
      int c = x ;
      int i = 1;  
        while(c>=10){
            i*=10;
            c=c/10;
        }
        int k = 1;
        while(k<i){
            if((x%(10*k))/k != (x/i)%10)
                return false;
            k=10*k;
            i=i/10;
        }
        return true;
    }
};