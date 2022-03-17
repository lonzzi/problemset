#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

string longestWord(vector<string> &words) {
  sort(words.begin(), words.end(), [](string i, string j) -> bool {
    return (i.size() < j.size()) || (i.size() == j.size() && i > j);
  });
  // for (auto &word : words) {
  //     cout << word << endl;
  // }
  string ans = "";
  unordered_set<string> letters;
  letters.insert("");
  for (int i = 0; i < words.size(); i++) {
    if (letters.find(words[i].substr(0, words[i].size() - 1)) !=
        letters.end()) {
        ans = words[i];
        letters.insert(ans);
    }
  }
  return ans;
}

int main() {
  vector<string> vec({"yo", "ew", "fc", "zrc", "yodn", "fcm", "qm", "qmo",
                      "fcmz", "z", "ewq", "yod", "ewqz", "y"});

  cout << longestWord(vec) << endl;

  return 0;
}