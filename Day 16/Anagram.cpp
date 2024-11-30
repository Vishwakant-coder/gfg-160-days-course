//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& a, string& b) {
        // Your code here
        map<char,int> ch1,ch2;
        int i=0,j=0;
        int len1=a.size();
        int len2=b.size();
        if(len1!=len2){
            return false;
        } 
        for(i=0;i<len1;i++){
            ch1[a[i]]++;
            ch2[b[j]]++;
            j++;
        }
        for (auto it : ch1) {
        if (ch2[it.first] != it.second) {
            return false;
        }
    }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends