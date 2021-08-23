#include<iostream>
#include<string>

int main()
{
	int T;
	std::cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		int cnt[3]{ 0, 0, 0 };
		std::string first, second;
		std::cin >> first >> second;
		for (int i = 0; i < first.size(); ++i) {
			if (first[i] != second[i]) {
				cnt[0]++;
				if (first[i] == '1') {
					cnt[1]++;
				}
				else {
					cnt[2]++;
				}
			}
		}
		int min_value = cnt[1] < cnt[2] ? cnt[1] : cnt[2];
		std::cout << cnt[0] - min_value << std::endl;
	}
}