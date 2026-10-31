
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>
using namespace std;
bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int sumDigits(int n)
{
    if (n < 0)
        n = -n;
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}
int reverseNumber(int n)
{
    int rev = 0;
    while (n > 0)
    {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n = n / 10;
    }
    return rev;
}
int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int fib(int n)
{
    if (n == 1 || n == 0)
        return n;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++)
    {
        int next = a + b;
        a = b;
        b = next;
    }
    return b;
}
int secondLargest(const vector<int> &v)
{
    int largest = INT_MIN;
    int second = INT_MIN;
    for (int x : v)
    {
        if (x > largest)
        {
            second = largest;
            largest = x;
        }
        else if (x > second && x != largest)
        {
            second = x;
        }
    }
    return second;
}
vector<int> removeDuplicates(const vector<int> &v)
{
    set<int> seen;
    vector<int> result;
    for (int x : v)
    {
        if (seen.count(x) == 0)
        {
            seen.insert(x);
            result.push_back(x);
        }
    }
    return result;
}
void printVector(const vector<int> &v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
void reverseVector(vector<int> &v)
{
    int i = 0;
    int j = v.size() - 1;
    while (i < j)
    {
        swap(v[i], v[j]);
        i++;
        j--;
    }
}
int findMax(const vector<int> &v)
{
    if (v.empty()) // 1. check first: is there anything to look at?
    {
        return 0; // 2. nothing to compare, so give back a safe value
    }
    int maximum = v[0];
    for (int x : v)
    {
        if (x > maximum)
            maximum = x;
    }
    return maximum;
}
int findMin(const vector<int> &v)
{
    if (v.empty()) // 1. check first: is there anything to look at?
    {
        return 0; // 2. nothing to compare, so give back a safe value
    }
    int minimum = v[0];
    for (int x : v)
    {
        if (x < minimum)
            minimum = x;
    }
    return minimum;
}
bool targetFinder(const vector<int> &v, int target)
{

    for (int x : v)
    {
        if (target == x)
            return true;
    }
    return false;
}
int countOccurrences(const vector<int> &v, int target)
{
    int count = 0;
    for (int x = 0; x < v.size(); x++)
    {
        if (target == v[x])
        {
            count++;
        }
    }
    return count;
}
int findFirst(const vector<int> &v, int target)
{
    for (int x = 0; x < v.size(); x++)
    {
        if (target == v[x])
            return x;
    }
    return -1;
}
int findLast(const vector<int> &v, int target)
{
    int last = -1;
    for (int x = 0; x < v.size(); x++)
    {
        if (target == v[x])
        {
            last = x;
        }
    }
    return last;
}
int findSecond(const vector<int> &v, int target)
{

    int count = 0;
    for (size_t x = 0; x < v.size(); x++)
    {
        if (target == v[x])
        {
            count++;

            if (count == 2)
            {
                return static_cast<int>(x);
            }
        }
    }
    return -1;
}
int findNth(const vector<int> &v, int target, int n)
{
    int count = 0;
    for (size_t x = 0; x < v.size(); x++)
    {
        if (target == v[x])
        {
            count++;
            size_t second = x;

            if (count == n)
            {
                return static_cast<int>(x);
            }
        }
    }
    return -1;
}
vector<int> removeAll(const vector<int> &v, int target)
{
    vector<int> result;
    for (size_t x = 0; x < v.size(); x++)
    {
        if (target != v[x])
        {
            result.push_back((v[x]));
        }
    }

    return result;
}
vector<int> replaceAll(const vector<int> &v, int oldVal, int newVal)
{
    vector<int> result;
    for (size_t x = 0; x < v.size(); x++)
    {
        if (oldVal == v[x])
        {
            result.push_back(newVal);
        }
        else
        {
            result.push_back(v[x]);
        }
    }

    return result;
}
bool isSorted(const vector<int> &v)
{
    for (size_t x = 1; x < v.size(); x++)
    {
        if ((v[x]) < (v[x - 1]))

            return false;
    }
    return true;
}
int binarySearch(const vector<int> &v, int target)
{
    int low = 0;
    int high = static_cast<int>(v.size()) - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (target == v[mid])
        {
            return mid;
        }
        else if (target > v[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
pair<int, int> findRange(const vector<int> &v, int target)
{
    if (v.empty())
    {
        return {-1, -1};
    }
    int first = -1;
    int last = -1;

    for (size_t x = 0; x < v.size(); x++)
    {
        if (target == v[x])
        {
            if (first == -1)
            {
                first = x;
            }
            last = x;
        }
    }
    return {first, last};
}
void analyzeVector(const vector<int> &v, int target)
{
    cout << "===== VECTOR ANALYZER =====" << endl;
    cout << "Vector: ";
    printVector(v);
    cout << endl;
    cout << "Maximum: " << findMax(v) << endl;
    cout << "Minimum: " << findMin(v) << endl;
    cout << "Sorted: " << (isSorted(v) ? "Yes" : "No") << endl;
    cout << "Target: " << target << endl;
    cout << "Exists: " << (targetFinder(v, target) ? "Yes" : "No") << endl;
    cout << "Occurrences: " << countOccurrences(v, target) << endl;
    cout << "First occurrence: " << findFirst(v, target) << endl;
    cout << "Last occurrence: " << findLast(v, target) << endl;
    pair<int, int> range = findRange(v, target);
    cout << "Range: " << range.first << " - " << range.second << endl;
}
int readInt(const string &prompt)
{
    int x;
    bool ok;
    do
    {
        cout << prompt;
        cin >> x;
        ok = !cin.fail();
        if (!ok)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Not a number. ";
        }
    } while (!ok);
    return x;
}

vector<int> readVector()
{
    int n;
    do
    {
        n = readInt("Enter vector size: ");
    } while (n <= 0);

    vector<int> values(n);
    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++)
    {
        values[i] = readInt("");
    }
    return values;
}

int main()
{
    vector<int> values; // lives for the whole program
    int choice;

    do
    {
        cout << "\n1. Enter a new vector\n2. Analyze with a target\n3. Binary search\n4. Exit\n";
        choice = readInt("Enter your choice (1-4): ");

        switch (choice)
        {
        case 1:
            values = readVector();
            break;
        case 2:
            if (values.empty())
            {
                cout << "Please enter a vector first." << endl;
            }
            else
            {
                int target = readInt("Enter target: ");
                analyzeVector(values, target);
            }
            break;
        case 3:
            if (values.empty())
            {
                cout << "Please enter a vector first." << endl;
            }
            else
            {
                vector<int> sorted = values;
                sort(sorted.begin(), sorted.end());
                cout << "Sorted copy: ";
                printVector(sorted);
                int key = readInt("Enter value to find: ");
                int pos = binarySearch(sorted, key);
                if (pos == -1)
                    cout << "Not found" << endl;
                else
                    cout << "Found at index " << pos << " in the sorted copy" << endl;
            }
            break;
        case 4:
            cout << "Goodbye" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 4);

    // cout << reverseNumber(1234) << endl;            // 4321
    // cout << reverseNumber(7) << endl;               // 7
    // cout << reverseNumber(1200) << endl;            // 21   (the zeros at the end vanish)
    // cout << reverseNumber(0) << endl;               // 0
    // cout << gcd(18, 12) << endl;                    // 6
    // cout << gcd(7, 13) << endl;                     // 1
    // cout << gcd(100, 25) << endl;                   // 25
    // cout << gcd(9, 0) << endl;                      // 9
    // cout << fib(0) << endl;                         // 0
    // cout << fib(1) << endl;                         // 1
    // cout << fib(6) << endl;                         // 8
    // cout << fib(10) << endl;                        // 55
    // cout << secondLargest({5, 9, 2, 9, 7}) << endl; // 7
    // cout << secondLargest({1, 2}) << endl;          // 1
    // cout << secondLargest({4, 4, 3}) << endl;       // 3
    // cout << secondLargest({-5, -2, -9}) << endl;
    // printVector(removeDuplicates({1, 2, 3, 3, 4, 4, 5, 5, 5}));
    // vector<int> values = {1, 2, 3, 3, 4, 4, 5, 5, 5};
    // reverseVector(values);
    // printVector(values);
    // cout << findMax({7, 2, 9, 4, 1, 8}) << endl;
    // cout << findMin({7, 2, 9, 4, 1, 8}) << endl;
    // cout << targetFinder({4, 7, 2, 9, 5}, 9) << endl; // 1
    // cout << targetFinder({4, 7, 2, 9, 5}, 6) << endl; // 0
    // cout << countOccurrences({1, 2, 3, 3, 4, 3, 5}, 3) << endl;
    // cout << findFirst({5, 2, 7, 2, 9}, 2) << endl;
    // cout << findLast({5, 2, 7, 2, 9, 2}, 2) << endl; // 5
    // cout << findLast({5, 2, 7, 2, 9, 2}, 9) << endl; // 4
    // cout << findLast({5, 2, 7, 2, 9, 2}, 8) << endl; // -1
    // cout << findSecond({5, 2, 7, 2, 9, 2}, 2) << endl;
    // cout << findNth({5, 2, 7, 2, 9, 2}, 2, 1) << endl;               // 1  (first 2)
    // cout << findNth({5, 2, 7, 2, 9, 2}, 2, 2) << endl;               // 3  (second 2)
    // cout << findNth({5, 2, 7, 2, 9, 2}, 2, 3) << endl;               // 5  (third 2)
    // cout << findNth({5, 2, 7, 2, 9, 2}, 2, 4) << endl;               // -1 (only three 2s)
    // cout << findNth({5, 2, 7, 2, 9, 2}, 8, 1) << endl;               // -1 (no 8 at all)
    // cout << findMin({}) << endl;                                     // 0 (no crash)
    // cout << findMin({7, 2, 9}) << endl;                              // 2
    // printVector(removeAll({5, 2, 7, 2, 9, 2}, 2));                   //  5 7 9
    // printVector(removeDuplicates(removeAll({5, 2, 7, 2, 9, 2}, 9))); // 5 2 7
    // printVector(removeDuplicates(removeAll({5, 2, 7, 2, 9, 2}, 8))); // 5 2 7 9
    // printVector(replaceAll({5, 2, 7, 2, 9}, 2, 0));                  // 5 0 7 0 9
    // cout << isSorted({1, 2, 2, 5}) << endl;                          // 1
    // cout << isSorted({1, 3, 2}) << endl;                             // 0
    // cout << isSorted({7}) << endl;                                   // 1
    // cout << isSorted({}) << endl;
    // vector<int> searchValues = {2, 5, 8, 12, 16, 23, 38};
    // cout << binarySearch(searchValues, 23) << endl; // 5
    // cout << binarySearch(searchValues, 2) << endl;  // 0
    // cout << binarySearch(searchValues, 38) << endl; // 6
    // cout << binarySearch(searchValues, 7) << endl;  // -1
    // vector<int> rangeValues = {1, 2, 2, 2, 5, 7, 7, 9};
    // pair<int, int> result = findRange(rangeValues, 2);
    // cout << "First: " << result.first << endl;
    // cout << "Last: " << result.second << endl;
    // cout << findRange(rangeValues, 7).first << " "
    //      << findRange(rangeValues, 7).second << endl;

    // cout << findRange(rangeValues, 9).first << " "
    //      << findRange(rangeValues, 9).second << endl;

    // cout << findRange(rangeValues, 4).first << " "
    //      << findRange(rangeValues, 4).second << endl;

    return 0;
}
