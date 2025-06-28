class Solution {
  public:
    // Function to check if a string is a palindrome.
    bool isPalindrome(string& s) {
        // code here
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1])
            return false;
        }
        return true;
    }
};