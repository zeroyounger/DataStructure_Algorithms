//
//  main.cpp
//  整数找零
//
//  Created by 杨子荣 on 2017/10/11.
//  Copyright © 2017年 杨子荣. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int countWays(vector<int> v,int n,int x){
    if(n==0||x<0)
        return 0;
    vector<vector<int>> f(n+1,vector<int>(x+1,-1));
    for(int i=0;i<n;i++)
        f[i][0]=1;//组成0元的方法都为1
    
    for(int i=0;i<x+1;i++)
        f[0][i]=(i%v[0]==0)?1:0;
    
    for(int i=1;i<n;i++)
        for(int j=1;j<x+1;j++)
            if((j-v[i])>=0)
                f[i][j]=f[i][j-v[i]]+f[i-1][j];
            else
                f[i][j]=f[i-1][j];
    return f[n-1][x];
}

int main(int argc, const char * argv[]) {
    int a[3]={1,2,3};
    vector<int> arr(a,a+3);
    cout<<countWays(arr, 3, 3)<<endl;
    return 0;
}
