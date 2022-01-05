/*
Find the  total number of squares in N*N chessboard
*/

#include<bits/stdc++.h>
using namespace std;

long long int calcSquares(int n)
{
    long long int ans = (n*(n+1)*(2*n+1))/6;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<calcSquares(n);
    return 0;
}