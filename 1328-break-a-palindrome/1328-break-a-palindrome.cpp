class Solution {
public:
    string breakPalindrome(string palindrome) {

        int n = palindrome.size();
        if(n == 1) return "";
        
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            char ch = palindrome[i];
            
            if(ch!='a')
            {
                if(i == n/2)break;  //case : aabaa
                palindrome[i] = 'a';
                flag = 1;
                break;
            }
        }
        
		//case : aaaa 
        if(flag == 0)
            palindrome[n-1] = palindrome[n-1]+1;
        
        return palindrome;
    }
};