#include<iostream>
#include<math.h>
#include<string>
#include <chrono> // Thư viện để đo thời gian
using namespace std;

string longestPalindrome(string s) {
        int len=s.length();
        int start=0;
        int maxLen=1;
        if(len<=1){
            return s;
        } 
        auto expandAroundCenter=[&](int left, int right){
            while(left>=0 && right<len && s[left]==s[right]){
                int curr=right-left+1;
                if(curr>maxLen){
                    start=left;
                    maxLen=curr;
                }
                left--;
                right++;
            }
        };
        for(int i=0;i<len;i++){
            expandAroundCenter(i,i);
            if(i<len-1){
                expandAroundCenter(i,i+1);
            }
        }
        return s.substr(start,maxLen);
    }
        /*
       bool check(string &s, int low, int high) {
    while (low < high) {
        if (s[low] != s[high]) {
            return false;
        }
        low++;
        high--;
    }
    return true;
}

string longestPalindrome(string s) {
    int len = s.length();
    int start = 0;
    int maxLen = 1;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (check(s, i, j) == true && (j - i + 1) > maxLen) {
                start = i;
                maxLen = j; // Lỗi: maxLen nên là j - i + 1
            }
        }
    }
    return s.substr(start, maxLen);
}
    */
int main(){
    string s = "khadccdhea"; // Ví dụ đầu vào

    // Đo thời gian bắt đầu
    const int iterations = 10000;
    auto total_duration_ns = chrono::nanoseconds(0);

    // Chạy hàm nhiều lần để đo thời gian chính xác
    for (int i = 0; i < iterations; i++) {
        auto start_time = chrono::high_resolution_clock::now();
        string result = longestPalindrome(s);
        auto end_time = chrono::high_resolution_clock::now();
        total_duration_ns += chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
    }

    // Tính thời gian trung bình
    auto avg_duration_ns = total_duration_ns / iterations;
    auto avg_duration_us = chrono::duration_cast<chrono::microseconds>(avg_duration_ns);
    auto avg_duration_ms = chrono::duration_cast<chrono::milliseconds>(avg_duration_ns);
    // In kết quả
    string result = longestPalindrome(s);
    cout << "Chuoi con palindrome dai nhat: " << result << endl;
    cout << "Do dai: " << result.length() << endl;
    cout << "Thoi gian trung binh (nano-giay): " << avg_duration_ns.count() << " ns" << endl;
    cout << "Thoi gian trung binh (micro-giay): " << avg_duration_us.count() << " us" << endl;
    cout << "Thoi gian trung binh (mili-giay): " << avg_duration_ms.count() << " ms" << endl;

    return 0;
}