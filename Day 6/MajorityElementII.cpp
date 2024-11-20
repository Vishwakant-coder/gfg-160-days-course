//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        vector<int>ans;
        int n=arr.size(),cand1,cand2=0,counter1=0,counter2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==cand1){
                counter1++;
            }else if(arr[i]==cand2){
                counter2++;
            }else if(counter1==0){
                cand1=arr[i];
                counter1++;
            }else if(counter2==0){
                cand2=arr[i];
                counter2++;
            }else {
                counter1--;
                counter2--;
            }
        }
        counter1=0;
        counter2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==cand1)
                counter1++;
            else if(arr[i]==cand2)
                counter2++;
        }
        if(counter1>(n/3)) 
            ans.push_back(cand1);
        if(counter2>(n/3))
            ans.push_back(cand2);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends