class Solution{
    public:
      vector<int> search(string text , string pattern){
         string concatenatedArray = pattern + "$" + text;
         int n=concatenatedArray.length();
         vector<int> zValues(n); 
         int l=0,r=0;
         for(int i=1;i<n;i++){
            if(i>r){
               l=r=i;
               while(r<n && concatenatedArray[r]==concatenatedArray[r-l])
                     r++;
               zValues[i]=r-l;
               r--;
            }
            else{
               int rel_ind=i-l;
               if(zValues[rel_ind]+i<=r)
                     zValues[i]=zValues[rel_ind];
               else{
                     l=i;
                     while(r<n && concatenatedArray[r]==concatenatedArray[r-l])
                        r++;
                     zValues[i]=r-l;
                     r--;
               }
            }
         }
         vector<int> result;
         int m = pattern.length();         
         for (int i = m + 1; i < n; ++i) {
            if (zValues[i] == m) {
                  result.push_back(i - m - 1);
            }
         }         
         return result;

      }
};

