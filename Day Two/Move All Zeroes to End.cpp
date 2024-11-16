//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int i=0,j=0,k=1;
	    for ( i = 0; i < arr.size(); i++) {
            if(k){
                if(arr[i]==0){
                    j=i; 
                    k--; 
                }
            }
            if(arr[j]==0 && arr[i]!=0){
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                j++;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends