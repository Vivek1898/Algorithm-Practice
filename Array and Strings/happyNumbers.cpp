class Solution {
public:
  // This function finds our squared sum for the given value
long long sqSum(long long num){
	long long sum = 0;
    while(num){
		sum = sum + (num % 10) * (num % 10);
        num /= 10;
    }
    return sum;
}

bool isHappy(int n){
    int slow = n, fast = n;
    do{
        slow = sqSum(slow);  // One pointer increments by one change.
        fast = sqSum(sqSum(fast));  // One pointer increments by two changes at once.
		if(fast == 1)
			return true;
    }while(slow != fast);
    
    return false;
}
// This approach takes O(logn) time and O(1) space
};