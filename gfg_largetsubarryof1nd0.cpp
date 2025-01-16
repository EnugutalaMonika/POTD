class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // o(n^2) time limit exceeded
        int n=arr.size();
        int sum;int ans=0;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=i;j<n;j++){
                if(arr[j]==0){arr[j]=-1;}
                sum=sum+arr[j];
                if(sum==0){ans=max(ans,j-i+1);}
            }
        }
        return ans;
        // o(n) using hashing & prefix sum
         int n=arr.size();
        int prefixsum=0;
        int ans=0;
        map<int,int>m;
        for(int i=0;i<n;i++){
            if(arr[i]==0){arr[i]=-1;}
            prefixsum+=arr[i];
            if(prefixsum==0){ans=i+1;}
            if(m.find(prefixsum)!=m.end()){ans=max(ans,i-m[prefixsum]);}
            else m[prefixsum]=i;
        }
        return ans;
    }
};
