class Solution {
public:
    int myAtoi(string s) {
        const int pos = 0;
        const int neg = 1 ;
        bool sign=pos;
        int converted = 0;
        int i = 0 ;
        while(s[i]==' ')
            i++;
        if(s[i]=='-'){
            sign = neg;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
        while( ( (int)s[i]<=57 ) && ( (int)s[i]>=48 ) && ( i<s.length() ) ){
            if(sign==pos){
                if(converted> (INT_MAX/10)) {
                    converted = INT_MAX; break ;
                }
                else{
                    converted = converted * 10 ;
                    int delta = INT_MAX-converted;
                    if(delta < (int)s[i]-48){
                        converted = INT_MAX;
                        break;
                    }
                    else{
                        converted = converted + ((int)s[i]-48);
                    }
                }
            }
            else{
                if(converted < (INT_MIN/10)){
                    converted = INT_MIN; break;
                }
                else{
                    converted = converted*10;
                    int delta = INT_MIN-converted;
                    if(48-(int)s[i] < delta){
                        converted = INT_MIN;
                        break;
                    }
                    else{
                        converted = converted - ((int)s[i]-48);
                    }
                }
            }
            ++i;
        }
        return converted;

    }
};