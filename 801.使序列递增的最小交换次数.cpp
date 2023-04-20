/*
 * @lc app=leetcode.cn id=801 lang=cpp
 *
 * [801] 使序列递增的最小交换次数
 */

// @lc code=start
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int i,n=A.size(),n1=0,s1=1,n2,s2;
        for(i=1;i<n;i++){
            n2=99999,s2=99999;
            if(A[i-1]<A[i]&&B[i-1]<B[i]){
                //此时已经满足条件
                n2=min(n2,n1);//当前位置不交换可以由前一个位置不交换得到
                s2=min(s2,s1+1);//当前位置交换可以由前一个位置交换得到
            }
            if(A[i-1]<B[i]&&B[i-1]<A[i]){
                //此时交换一下必定能满足条件
                n2=min(n2,s1);//当前位置不交换可以由前一个位置交换得到
                s2=min(s2,n1+1);//当前位置交换可以由前一个位置不交换得到
            }
            n1=n2;s1=s2;
        }
        return min(n1,s1);
    }
};
// @lc code=end

