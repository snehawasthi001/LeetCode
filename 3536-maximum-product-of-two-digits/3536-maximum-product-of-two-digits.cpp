class Solution {
public:
    int maxProduct(int n) {
        int largest = 0;
        int secondlargest = 0;
        while(n!=0){
            int temp = n%10;
            if(temp>largest){
                secondlargest = largest;
                largest = temp;
            }
            else if(temp>secondlargest){
                secondlargest = temp;
            }
            n = n/10;
        }
        return largest*secondlargest;
    }
};