//
//  main.cpp
//  01背包问题
//
//  Created by 杨子荣 on 2017/10/11.
//  Copyright © 2017年 杨子荣. All rights reserved.
//

#include <iostream>
#define V 1500
unsigned int f[10][V];//全局变量，自动初始化为0
unsigned int weight[8]{42,25,30,35,42,21,26,28};
unsigned int value[8]={261,247,419,133,391,456,374,591};
#define maxSum(x,y) (x)>(y)?(x):(y)
using namespace std;

int main(){
    //N件物品，容量为M
    //int N,M;
    int N=8;
    int M=297;
    //cin>>N>>M;
    //for(int i=1;i<=N;i++)
      //  cin>>weight[i]>>value[i];
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++){
            if(weight[i]<=j)//要加入的第i个物品，容量<当前剩余空间，即，能装下
                f[i][j]=maxSum(f[i-1][j],f[i-1][j-weight[i]]+value[i]);//价值:不装，或是装，减去相应容量，加上相应价值
            else//装不下，则不装，f[i][j]=f[i-1][j]
                f[i][j]=f[i-1][j];
        }
    cout<<f[N][M]<<endl;
    return 0;
}
