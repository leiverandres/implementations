#include <bits/stdc++.h>

using namespace std;

// First method. complexity (-)(logn) (theta log n)
int count_set_bits(unsigned int x) {
  int count = 0;
  while (x) {
    count += x & 1;
    x >>= 1;
  }
  return count;
}
// Brian Kernighan’s Algorithm O(logn)
int set_bits(unsigned int x) {
  int count = 0;
  while (x) {
    x &= (x - 1);
    count++;
  }
  return count;
}
/*
  You are given two numbers A and B. Write a program to count
  number of bits needed to be flipped to convert A to B.
*/
int main() {
  unsigned int a, b;
  cin >> a >> b;
  int a_xor_b = a ^ b;
  cout << "A needs: " << set_bits(a_xor_b) << endl;
  return 0;
}
