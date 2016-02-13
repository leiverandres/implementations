#include <bits/stdc++.h>
using namespace std;

string delete_spaces(string &str) {
  str.erase(remove(str.begin(), str.end(), ' '), str.end());
  return str;
}

string to_str(int a) {
  std::stringstream ss;
  ss << a;
  return ss.str();
}

int to_int(string s) {
  istringstream buffer(s);
  int value;
  buffer >> value;;
  return value;
}

int main() {
  string s;
  getline(cin, s);
  cout << "Before: " << s << endl;
  cout << "After: " << delete_spaces(s) << endl;
  return 0;
}
