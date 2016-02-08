#include <bits/stdc++.h>
using namespace std;

string delete_spaces(string &str) {
  str.erase(remove(str.begin(), str.end(), ' '), str.end());
  return str;
}

int main() {
  string s;
  getline(cin, s);
  cout << "Before: " << s << endl;
  cout << "After: " << delete_spaces(s) << endl;
  return 0;
}
