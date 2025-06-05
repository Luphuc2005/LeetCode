#include<iostream> 
#include<string.h>
#include<algorithm>
#include<unordered_set>
using namespace std;
int lengthOfLongestSubstring(string s){
    int left=0;
    int maxLength=0;
    int len=s.length();
    unordered_set<char> tmp; // mang tmp7
    for(int right=0; right<len;right++){
        while(tmp.find(s[right]) != tmp.end()){
            tmp.erase(s[left]);
            left++;
        }
        tmp.insert(s[right]);
        maxLength=max(maxLength, right-left+1);
    }
    cout << s.substr(left,maxLength)<<endl;
    return maxLength;
}
int main(){
    int dem=lengthOfLongestSubstring("hellotoine");
    cout<<"so ki tu dai nhat: "<<dem;
    return 0;
}