int KMP_matcher(string &pattern, string &text) {
	int m = pattern.size();
	vector<int> border(m);
	border[0] = 0;
	for (int i = 1; i < m; ++i) {
		border[i] = border[i-1];
		while(border[i] > 0 && pattern[i] != pattern[border[i]]) {
			border[i] = border[border[i] - 1];
		}
		if(pattern[i] == pattern[border[i]])
      border[i]++;
	}

	int n = text.size();
	int ans = 0;
	int seen = 0;
	for (int j = 0; j < n; ++j) {
		while(seen > 0 && text[j] != pattern[seen]) {
			seen = border[seen - 1];
		}
		if (text[j] == pattern[seen])
      seen++;
		if (seen == m) {
			ans++;
			seen = border[m - 1];
		}
	}

	return ans; // number of occurrences
}

int main()
{
	int cases;
	string pattern, text;
	cin>>cases;
	for (int caso = 0; caso < cases; ++caso) {
		int ans = 0;
		cin >> text >> pattern;
    int ans = KMP_matcher(pattern, text);
		cout << "Case " << caso+1 << ": " << ans << endl;
	}
	return 0;
}
