#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int countVowels(const string &s)
{
    int count = 0;
    for (char c : s)
    {
        if (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u' || c == 'A' ||
            c == 'E' || c == 'I' || c == 'O' || c == 'U')
            count++;
    }
    return count;
}
string cleanText(const string &s)
{
    string cleaned;
    for (char c : s)
    {
        if (isalpha(c))
        {
            cleaned += tolower(c);
        }
    }
    return cleaned;
}
bool isPalindrome(const string &s)
{
    string t = cleanText(s);
    for (int i = 0; i < t.length() / 2; i++)
    {

        if (t[i] = t[t.length() - 1 - i])
        {
            return false;
        }
    }
    return true;
}
int countWords(const string &s)
{
    stringstream ss(s);
    string word;
    int count = 0;
    while (ss >> word)
    {
        count++;
    }

    return count;
}
void printFrequency(const string &s)
{
    map<char, int> freq;
    string t = cleanText(s);
    for (char c : t)
    {
        freq[c]++;
    }

    for (const auto &p : freq)
    {

        cout << p.first << ":" << p.second << endl;
    }
}
char mostFrequent(const string &s)
{
    map<char, int> freq;
    string t = cleanText(s);
    if (t.empty())
    {
        return '\?';
    }

    for (char c : t)
    {
        freq[c]++;
    }

    char biggest = t[0];
    for (const auto &p : freq)
    {
        if (p.second > freq[biggest])
        {
            biggest = p.first;
        }
    }
    return biggest;
}

string longestWord(const string &s)
{
    stringstream ss(s);
    string word;
    string longest = "";
    while (ss >> word)
    {
        if (word.length() > longest.length())
        {
            longest = word;
        }
    }
    return longest;
}

bool isAnagram(const string &a, const string &b)
{
    string cleaned1 = cleanText(a);
    string cleaned2 = cleanText(b);
    sort(cleaned1.begin(), cleaned1.end());
    sort(cleaned2.begin(), cleaned2.end());
    if (cleaned1 == cleaned2)
    {
        return true;
    }
    return false;
}
string anagramMessage(const string &a, const string &b)
{
    if (isAnagram(a, b))
    {
        return "Anagram";
    }
    return "Not Anagram";
}
bool hasDuplicate(const vector<int> &v)
{
    set<int> seen;
    for (int x : v)
    {
        if (seen.count(x) == 1)
        {
            return true;
        }
        seen.insert(x);
    }
    return false;
}
bool hasPairWithSum(const vector<int> &v, int target)
{
    set<int> seen;
    for (int x : v)
    {
        if (seen.count(target - x) == 1)
        {
            return true;
        }
        seen.insert(x);
    }
    return false;
}
string mostCommonWord(const string &s)
{
    stringstream ss(s);
    string word;
    map<string, int> counts;
    while ((ss >> word))
    {
    
        string y = cleanText(word);
        if (y.empty())
        {
            continue;
        }
        counts[y]++;
    }
    string best;
    int bestCount = 0;
        for(const auto &p :counts)
        {
            if (p.second > bestCount)
            {
                bestCount = p.second;
                best = p.first;
            }
        }
    return best;
}
int main()
{
    cout<< countVowels("modernization") << endl;
    cout << isPalindrome("level") << endl
         << isPalindrome("hello") << endl
         << isPalindrome("abxya") << endl
         << isPalindrome("abba") << endl
         << isPalindrome("racecar") << endl
         << isPalindrome("palindrome") << endl
         << isPalindrome("A man a plan a canal Panama") << endl
         << isPalindrome("Was it a car or a cat I saw") << endl
         << isPalindrome("No 'x' in Nixon") << endl
         << isPalindrome("Not a palindrome") << endl
         << isPalindrome("Able was I ere I saw Elba") << endl
         << isPalindrome("Madam In Eden I'm Adam") << endl;
    printFrequency("Banana");
    cout << mostFrequent("Banana") << endl;
    cout << countWords("hello world") << endl;
    cout << countWords("the quick brown fox") << endl;
    cout << countWords("hello") << endl;
    cout << longestWord("the quick brown fox") << endl; // quick
    cout << longestWord("hello") << endl;               // hello
    cout << longestWord("") << endl;
    cout << anagramMessage("listen", "silent") << endl;        // 1
    cout << anagramMessage("hello", "world") << endl;          // 0
    cout << anagramMessage("Dormitory", "Dirty room") << endl; // 1                  // (an empty line)
    cout << hasDuplicate({1, 2, 3, 4}) << endl;                // 0
    cout << hasDuplicate({1, 2, 3, 2}) << endl;                // 1
    cout << hasDuplicate({}) << endl;
    cout << hasPairWithSum({2, 7, 11, 15}, 9) << endl; // 1
    cout << hasPairWithSum({1, 2, 3}, 10) << endl;     // 0
    cout << hasPairWithSum({5}, 10) << endl;
    cout << mostCommonWord("the cat and the dog and the bird") << endl; // the
    cout << mostCommonWord("Go go GO stop") << endl;                    // go
    cout << mostCommonWord("") << endl;                                 // (an empty line)                       // 0
    return 0;
}
