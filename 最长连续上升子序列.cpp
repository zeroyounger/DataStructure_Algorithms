//
//  main.cpp
//  最长连续上升子序列
//
//  Created by 杨子荣 on 2017/10/11.
//  Copyright © 2017年 杨子荣. All rights reserved.
//

/*
 对于arr，生成dp，dp[i]表示在必须以arr[i]这个数结尾的情况下，arr[o...i]中的最大递增子序列长度

dp[0]=1
对于dp[i],所有比arr[i]小的数都可以作为倒数第2个数，其中，哪个数的dp最大，则将其作为倒数第2个数
dp[i]=max{dp[j]+1 (0<=j<1,arr[j]<arr[i])}
返回dp中最大的数
 */

#include <iostream>
#include <vector>
using namespace std;

class AscentSequence {
public:
    int findLongest(vector<int> A, int n) {
        // write code here
        vector<int> dp(n,0);
        int res=0;
        dp[0]=1;
        for(int i=0;i!=n;i++){
            int max=0,j=0;
            while(j<i){
                if(A[j]<A[i]&&dp[j]>max)
                    max=dp[j];
                j++;
            }
            dp[i]=max+1;
        }
        for(int i=0;i!=n;i++)
            if(res<dp[i])
                res=dp[i];
        return res;
    }
};

int main(int argc, const char * argv[]) {

    cout << "Hello, World!\n";
    return 0;
}
