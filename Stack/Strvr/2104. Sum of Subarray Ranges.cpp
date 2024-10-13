class Solution {
public:



     vector<int> NSE( vector<int>&arr, int n){
        stack<int>st;
        vector<int>nse( n, n);
        for( int i=n-1; i>=0 ;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }

            nse[i]=(st.empty())?(n):(st.top());
            st.push(i);
        }

        return nse;
    }

    vector<int> PSEE( vector<int>&arr, int n){
        stack<int>st;
        vector<int> psee(n, -1);
        for( int i=0; i<n; i++){

            while( !st.empty() && arr[st.top()] >arr[i]){
                st.pop();
            }

            psee[i]=(st.empty())? -1 :st.top();

            st.push(i);
        }

        return psee;
    }

    long long sumSubarrayMins(vector<int>& arr) {

        int n= arr.size();
        //find the nse arr;
        vector<int> nse=NSE(arr,n);
        // finding psee ( equal case is also include to remove the double cnt of [1,1] int arr=[1,1])
        vector<int> psee=PSEE(arr,n);

        long long total=0;
    

        for( int i=0; i<n; i++){

             long long leftPart=i-psee[i];
             long long rightPart=nse[i]-i;

           total = (total + (long long)arr[i] * leftPart * rightPart);

        
            
        }

        return total;

       
        
    }


         vector<int> NGE( vector<int>&arr, int n){
        stack<int>st;
        vector<int>nge( n, n);
        for( int i=n-1; i>=0 ;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }

            nge[i]=(st.empty())?(n):(st.top());
            st.push(i);
        }

        return nge;
    }

    vector<int> PGEE( vector<int>&arr, int n){
        stack<int>st;
        vector<int> pgee(n, -1);
        for( int i=0; i<n; i++){

            while( !st.empty() && arr[st.top()] <arr[i]){
                st.pop();
            }

            pgee[i]=(st.empty())? -1 :st.top();

            st.push(i);
        }

        return pgee;
    }

    long long  sumSubarrayMaxs(vector<int>& arr) {

        int n= arr.size();
        //find the nse arr;
        vector<int> nge=NGE(arr,n);
        // finding psee ( equal case is also include to remove the double cnt of [1,1] int arr=[1,1])
        vector<int> pgee=PGEE(arr,n);

         long long total=0;
        // int mod=(int)(1e9+7);

        for( int i=0; i<n; i++){

             long long leftPart=i-pgee[i];
             long long rightPart=nge[i]-i;

           total = (total + (long long)arr[i] * leftPart * rightPart);

        
            
        }

        return total;

       
        
    }

    long long subArrayRanges(vector<int>& nums) {


  return (sumSubarrayMaxs(nums) - sumSubarrayMins(nums));



        
    }
};