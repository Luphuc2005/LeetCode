/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
void swap(vector<int>& a){
    int n=a.size();
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(a[minIndex]>a[j]){
                minIndex=j;
            }
        }
        if(i!=minIndex){
            int tmp=a[i];
            a[i]=a[minIndex];
            a[minIndex]=tmp;
        }
    }
}
vector<vector<int>> threeSum(vector<int>& nums){
    int n=nums.size();
    int target=0;
    vector<vector<int>>result;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-2;i++){
        if(i>0&&nums[i]==nums[i-1]){
            continue;
        }
        int l=i+1;
        int r=n-1;
        while(l<r){
            int sum = nums[i]+nums[l]+nums[r];
            if(sum>target){
                r=r-1;
            }
            else if(sum<target){
                l=l+1;
            }
            else{
                result.push_back({nums[i],nums[l],nums[r]});
                while(l<r and nums[l] == nums[l+1]){
                    l++;
                }
                while(l<r && nums[r]==nums[r-1]){
                    r--;
                }
                l++;
                r--;
            }
        }
    }
    return result;
}
int main(){
    cout << "so luong phan tu cua nums: ";
    int n;      cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cout <<"Nhap nums ["<< i<< "] : ";
        cin >> nums[i];
    }
    vector<vector<int>>result= threeSum(nums);
    for(const auto& triplet:result){
        for(int num:triplet){
            cout <<num<< " ";
        }
        cout <<endl;
    }
    return 0;
}