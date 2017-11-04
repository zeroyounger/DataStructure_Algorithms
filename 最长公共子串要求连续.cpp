//
//  main.cpp
//  最长公共子串
//
//  Created by 杨子荣 on 2017/10/11.
//  Copyright © 2017年 杨子荣. All rights reserved.
//

/*
用一个矩阵记录字符串所有位置两个字符之间的匹配情况，匹配则为1，否则为0，看对角线最长的1序列

改进，匹配时，赋上其左上角元素的值+1，然后找最大的元素位置
*/
#include <iostream>
#include <vector>
using namespace std;

class LongestSubstring {
public:
    int findLongest(string A, int n, string B, int m) {
        // write code here
        vector<vector<int>> f(n+1,vector<int>(m+1,0));
        int maxlen=0;
        for(int i=n-1;i>-1;--i)
            for(int j=m-1;j>-1;--j){
                if(A[i]==B[j]){
                    f[i][j]=f[i+1][j+1]+1;
                    maxlen=max(maxlen,f[i][j]);
                }
            }
        return maxlen;
    }
};

int main(int argc, const char * argv[]) {

    cout << "Hello, World!\n";
    return 0;
}
