class Solution {
public:
    bool isPalindrome(int x) {
      if(x<0) return false;
      vector<int> numbers;  
      int i = 10;
        while(x/(i/10)>0){
            numbers.push_back((x%i)/(i/10));
            if(i>INT_MAX/10){
                numbers.push_back(x/i);
                break;
            }
            i*=10;
        }
        int k = numbers.size()-1;
        i = 0 ;
        while(k>i){
            if(numbers[k]!=numbers[i])
                return false;
            i++;
            k--;
        }
        return true;
    }
};