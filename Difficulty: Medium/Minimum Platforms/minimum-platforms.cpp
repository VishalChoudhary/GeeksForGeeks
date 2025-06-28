class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=0,j=0;
        int cnt=0,max_cnt=INT_MIN;
        while(i<arr.size()){
            if(arr[i]<=dep[j]){
                cnt+=1;
                i++;
            }
            else {
                cnt-=1;
                j++;
            }
            max_cnt=max(cnt,max_cnt);
        }
        return max_cnt;
    }
};
