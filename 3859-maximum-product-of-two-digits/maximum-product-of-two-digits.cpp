class Solution {
public:
    int maxProduct(int n) {
        int rem,max1{-1},max2{-1},temp;
        while(n != 0){
            rem = n%10;
            if(rem >= max1){
                temp = max1;
                max1 = rem;
                max2 = temp; 
            }else if(rem >= max2){
                max2 = rem;
            }
            n = n/10;
        }
        return max1*max2;
    }
};