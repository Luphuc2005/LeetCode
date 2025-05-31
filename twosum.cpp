/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 */

 #include<vector>;
 #include<unordered_map>;
 #include<iostream>;
 #include<algorithm>
 using namespace std;
 vector<int> twoSum(vector<int>& nums, int target){
    /*
    unordered_map<int,int> numMap; // lưu các chỉ số key và value của mảng. <100,200> key =100, value=200. 
    int n=nums.size(); // số lượng phần tử của mảng nums
    for(int i=0;i<n;i++){
        int complement = target - nums[i]; //tìm giá trị cần thiết 
        if(numMap.find(complement)!=numMap.end()){  // tìm các complement trong numMap so với .end(): là các index của mảng nums
            return {numMap[complement], i}; // nếu tìm thấy thì trả về giá trị của complement và i
        }
        numMap[nums[i]] = i; // nếu không tìm thấy thì lưu giá trị của nums[i] vào numMap với chỉ số i      
    }
    return {}; // nếu không tìm thấy cặp nào thì trả về mảng rỗn
    */
    int n=nums.size();
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++){
        arr.push_back({nums[i],i}); // với nums[i] là giá trị mamngr, i là chỉ số.. ta có pair<key,value> giống với map
    }
    sort(arr.begin(), arr.end());
    int l=0,r=n-1;
    while(l<r){
        int total=arr[l].first+arr[r].first;
        if(total<target){
            l=l+1;
        }else if(total>target){
            r=r+1;
        }
        else{
            return {arr[l].second, arr[r].second};
        }
    }
    return {};
 }
 int main(){
    int n;
    cout <<"Nhap so luong phan tu cua mang nums= "; 
    cin >> n;
    vector<int> nums(n); // tạo mảng nums với kích thước n
    for(int i=0;i<n;i++){
        cout <<"Nhap nums[" << i << "]= ";
        cin>>nums[i]; // nhập các giá trị của mảng nums
    }
    cout << "Nhap target= ";
    int target; cin >> target; // nhập giá trị target   
    vector<int> result=twoSum(nums,target);
    cout << "Cac chi so cua hai so trong mang la: ";
    for(int i=0;i<result.size();i++){
        cout << result[i] << " "; // in ra các chỉ số của hai số trong mảng
    }
 }