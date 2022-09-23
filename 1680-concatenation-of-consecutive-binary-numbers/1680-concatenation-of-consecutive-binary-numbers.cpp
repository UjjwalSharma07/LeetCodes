class Solution {
public:
       
    int concatenatedBinary(int n) {
        long long ans = 0;
		int M = 1e9+7;
		string num = "";
		// concatinating the numbers
		for(int i = n; i >= 1; i--)
		{
			int t = i;
			while(t)
			{
				num += t%2 + '0';
				t /= 2;
			}
		}
		// evaluating num
		int pow = 1;
		for(int i = 0; i < num.size(); i++)
		{
			long long val = (num[i]-'0')*pow;
			pow *= 2;
			pow %= M;
			ans += val;
			ans %= M;
		}
		return ans%M;
    }
};