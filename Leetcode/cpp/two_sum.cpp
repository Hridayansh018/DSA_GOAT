#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        vector<int> twosum(vector<int>& arr, int x){
        vector<int> res(2);
        int n = arr.size();
        for(int i = 0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[i] + arr[j] == x){
                    res[0] = arr[i];
                    res[1] = arr[j];
                    return res;
                }
            }
        }
        return res;
    }
};


int main(){
    Solution s;
    vector<int> arr = {2,7,16,8};
    int target = 9;

    vector<int> ans = s.twosum(arr, target);
    if (ans[0] != -1)
        cout << "Pair found: " << ans[0] << " + " << ans[1] << " = " << target << endl;
    else
        cout << "No pair found for target " << target << endl;

    return 0;
}