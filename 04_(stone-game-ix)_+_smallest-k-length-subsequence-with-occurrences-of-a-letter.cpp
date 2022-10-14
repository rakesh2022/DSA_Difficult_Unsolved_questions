//https://leetcode.com/contest/weekly-contest-261/problems/stone-game-ix/    (this question is different but of same contest) 
//https://leetcode.com/problems/burst-balloons/   (burst balloon)
//   https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/discuss/1455070/Simulation-(DP-Alternative)
//      https://leetcode.com/problems/largest-component-size-by-common-factor/discuss/1592263/C%2B%2B-3-Simple-Solution-w-Explanation-or-Disjoint-Set-Union-%2B-Sieve-of-Eratosthenes
//   https://leetcode.com/problems/gcd-sort-of-an-array/discuss/1445632/C%2B%2B-Union-Find
//  https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

//   https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
//   https://leetcode.com/contest/biweekly-contest-59/problems/number-of-ways-to-separate-numbers/




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
