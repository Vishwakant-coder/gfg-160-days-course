//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int s1=0,e1=arr.size()-1;
        int first=-1;
        while(s1<=e1){
            int mid1=(s1+e1)/2;
            if(arr[mid1]==target){
                first=mid1;
                e1=mid1-1;
            }
            else if(arr[mid1]>target)
                e1=mid1-1;
            else
                s1=mid1+1;
        }
        
        int s2=0,e2=arr.size()-1;
        int last=-1;
        while(s2<=e2){
            int mid2=(s2+e2)/2;
            if(arr[mid2]==target){
                last=mid2;
                s2=mid2+1;
            }
            else if(arr[mid2]>target)
                e2=mid2-1;
            else
                s2=mid2+1;
        }
        if(last+first==-2)
            return 0;
        return last-first+1;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends