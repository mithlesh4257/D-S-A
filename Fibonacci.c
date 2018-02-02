------------------------------------------
      New Method more optimized
------------------------------------------
#include<stdio.h>

void multiply(int F[2][2], int M[2][2]);
void power(int F[2][2],int n);

int fib(int n){
	int F[2][2] = {{1,1},{1,0}};
	if(n==0)
		return 0;
	power(F,n-1);
	return F[0][0];
}

void power(int F[2][2],int n){
	if(n==0||n==1){
		return;
	}
	int M[2][2] = {{1,1},{1,0}};

	power(F,n/2);
	multiply(F,F);

	if(n%2 !=0)
		multiply(F,M);
}
void multiply(int f[2][2],int M[2][2]){
	int x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
	int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

int main(){
	int n=10;
	printf("%d\n",fib(n));
	getchar();
	return 0;
}



------------------------------------------
      New Method more optimized
------------------------------------------

// C++ Program to find n'th fibonacci Number in
// with O(Log n) arithmatic operations
#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 1000;
 
// Create an array for memoization
int f[MAX] = {0};
 
// Returns n'th fuibonacci number using table f[]
int fib(int n)
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);
 
    // If fib(n) is already computed
    if (f[n])
        return f[n];
 
    int k = (n & 1)? (n+1)/2 : n/2;
 
    // Applyting above formula [Note value n&1 is 1
    // if n is odd, else 0.
    f[n] = (n & 1)? (fib(k)*fib(k) + fib(k-1)*fib(k-1))
           : (2*fib(k-1) + fib(k))*fib(k);
 
    return f[n];
}
 
/* Driver program to test above function */
int main()
{
    int n = 9;
    printf("%d ", fib(n));
    return 0;
}
