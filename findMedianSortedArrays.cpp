#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
    vector<int> merged = nums1;
    merged.insert(merged.end(), nums2.begin(), nums2.end());
    sort(merged.begin(), merged.end());
    int n = merged.size();
    if (n % 2 == 1) {
        return merged[n / 2];
    } else {
        return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    }
        
       /*
       if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1); 

        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1) {
                if ((n1 + n2) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return max(l1, l2);
            }
            else if (l1 > r2)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }

        return 0.0; 
        */
}

int main() {
    int n1, n2;
    cout << "Nhap so luong phan tu mang 1: "; cin >> n1;
    vector<int> nums1(n1);
    for (int i = 0; i < n1; i++) {
        cout << "nums1[" << i << "]= "; cin >> nums1[i];
    }
    cout << "Nhap so luong phan tu mang 2: "; cin >> n2;
    vector<int> nums2(n2);
    for (int i = 0; i < n2; i++) {
        cout << "nums2[" << i << "]= "; cin >> nums2[i];
    }
    double trungvi = findMedianSortedArrays(nums1, nums2);
    cout << "Trung vi mang: " << trungvi << endl;
    return 0;
}