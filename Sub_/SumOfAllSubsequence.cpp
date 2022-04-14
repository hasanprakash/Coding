// Sum of all sub-sequences of a number  
// Problem: https://practice.geeksforgeeks.org/problems/sum-of-all-sub-sequences-of-a-number/0
// 11 - March - 2022
class Solution{
public:	
    long long factorial(long long n) {
    long long factorial = 1;
        for (int i = 2; i <= n; i++)
            factorial = factorial * i;
        return factorial;
    }
     
    long long nCr(long long n, long long r) {
        return factorial(n) / (factorial(r) * factorial(n - r));
    }
	long long subsequenceSum(string s) 
	{
	    long long sum = 0;
	    for(char ch : s) {
	        sum += (ch-48);
	    }
	    long long n = s.size();
	    long long ansSum = 0;
	    for(int index=0;index<n;index++) {
	        long long i = index + 1;
	        long long digitCount = ((i * nCr(n, i))/n);
	        ansSum += (digitCount * sum);
	    }
	    return ansSum;
	}
};