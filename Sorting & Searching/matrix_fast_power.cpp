// 根據 fib(n) = fib(n-1) + fib(n-2) 可以推導出一系列公式
// 其中 定義 A 矩陣為 [[1, 1], [1, 0]] 
// fib(n) = A^n-1[0][0]

#include <bits/stdc++.h>
#define int long long
using namespace std;

// 定義矩陣快速冪
const int p = 1e9+7, n = 2, m = 2;
struct mat{
    int A[n][m];

    mat operator * (const mat &B) const {
        mat ret = {{{0, 0}, {0, 0}}};
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    ret.A[i][j] = (ret.A[i][j] + A[i][k] * B.A[k][j] % p) % p;
                
        return ret;
    }
} M = {{{1, 1}, {1, 0}}};

mat fast_pow(int n){
    if (n == 0 || n == 1)
        return M;
    
    if (n % 2){
        mat t = fast_pow((n-1)/2);
        return t*t*M;
    }

    mat t = fast_pow(n/2);
    return t*t;
}