
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<pair<int, int>>st;
       
       vector<int>ans;
       for(int i=0; i<n; i++){
           int span=1;
           
           while( !st.empty() && st.top().first<=price[i]){
               span=span+st.top().second;
               st.pop();
           }
           
           st.push({price[i],span});
           ans.push_back(span);
       }
       
       
       return ans;
    }
};