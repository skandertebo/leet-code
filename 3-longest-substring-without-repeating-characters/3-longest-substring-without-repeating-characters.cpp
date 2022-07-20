class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        int max = 1 ;
        for(int i=0 ; i<s.length();i++){
            int maxlength = s.length()-i;
            int c = 0 ;
            while(c!=maxlength){
                for(int j = c+1 ; j<maxlength ; j++){
                    if(s[i+j]==s[i+c]){
                        maxlength=j;
                    }
                }
                c++;
            }
            if(maxlength>max){
                max = maxlength;
            }   
        }
        return max;
    }
};