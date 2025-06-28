class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n=arr.size();
        int largest=-1;
        int slargest=-1;
        for(int i=0;i<n;i++){
            if(arr[i]>largest)
            largest=arr[i];
        }
        for(int i=0;i<n;i++){
            if(arr[i]>slargest && arr[i]!=largest){
                slargest=arr[i];
            }
        }
        return slargest;
    }
};