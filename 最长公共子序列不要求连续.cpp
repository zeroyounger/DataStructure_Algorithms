//
//  main.cpp
//  最长公共子序列
//
//  Created by 杨子荣 on 2017/10/11.
//  Copyright © 2017年 杨子荣. All rights reserved.
//

/*
 最长公共子序列，不要求连续
 定义table[i][j]为：
 strA[0~i]和strB[0~j]的最长公共子序列
 table 的大小为 (n + 1) x (m + 1) ，这多出来的一行和一列是第 0 行和第 0 列，初始化为 0
 
 当我们要求table[ i ][ j ]，我们要先判断A[ i ]和B[ j ]是否相同，如果相同他就是table[ i - 1 ][ j - 1 ] + 1
 否则最长公共字串取table[ i ][ j - 1 ] 和table[ i - 1 ][ j ] 中大者。
 */

#include <iostream>
#include <vector>
using namespace std;

class LCS {
public:
    int findLCS(string A, int n, string B, int m) {
        // write code here
        vector<vector<int>> f(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j){
                if(A[i]==B[j])
                    f[i+1][j+1]=f[i][j]+1;
                else
                    f[i+1][j+1]=max(f[i][j+1],f[i+1][j]);
            }
        return f[n][m];
    }
};

int main(int argc, const char * argv[]) {

    cout << "Hello, World!\n";
    return 0;
}
