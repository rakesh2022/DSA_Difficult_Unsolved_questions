//  https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/

string smallestSubsequence(string s, int k, char letter, int rep) {
    int extra = count(begin(s), end(s), letter) - rep, remove = s.size() - k;
    string mono, res;
    for (auto ch : s) {
        while (!mono.empty() && mono.back() > ch && remove) {
            if (mono.back() == letter && extra == 0)
                break;
            extra -= mono.back() == letter;
            --remove;
            mono.pop_back();
        }
        mono += ch;
    }
    for (int i = 0; res.size() < k; ++i) {
        if (mono[i] != letter && res.size() + max(0, rep) >= k)
            continue;
        res += mono[i];
        rep -= mono[i] == letter;
    }
    return res;
}