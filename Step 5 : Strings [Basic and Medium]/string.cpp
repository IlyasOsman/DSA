int maxDepth(string s)
{
    // Write your code here.
    int currDept = 0;
    int maxiDepth = 0;
    for (char c : s)
    {
        if (c == '(')
        {
            currDept += 1;
            maxiDepth = max(currDept, maxiDepth);
        }
        else if (c == ')')
        {
            currDept--;
        }
    }
    return maxiDepth;
}

class Solution
{
public:
    int maxDepth(string s)
    {
        int currentDepth = 0;
        int maxDepth = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                currentDepth++;
                maxDepth = max(currentDepth, maxDepth);
            }
            else if (c == ')')
            {
                currentDepth--;
            }
        }
        return maxDepth;
    }
};

bool areIsomorphic(string &str1, string &str2)
{
    // Write your code here
    // Check if the lengths of the strings are different
    if (str1.size() != str2.size())
    {
        return false;
    }

    unordered_map<char, char> mapS1S2; // Map to store mappings from characters in str1 to characters in str2
    unordered_map<char, char> mapS2S1; // Map to store mappings from characters in str2 to characters in str1

    for (int i = 0; i < str1.size(); i++)
    {
        // Check if the character in str1 is already mapped
        if (mapS1S2.find(str1[i]) != mapS1S2.end())
        {
            // If the mapping is different, return false
            if (mapS1S2[str1[i]] != str2[i])
            {
                return false;
            }
        }
        else
        {
            // If the character in str1 has not been mapped, create a new mapping
            mapS1S2[str1[i]] = str2[i];
        }

        // Check if the character in str2 is already mapped
        if (mapS2S1.find(str2[i]) != mapS2S1.end())
        {
            // If the mapping is different, return false
            if (mapS2S1[str2[i]] != str1[i])
            {
                return false;
            }
        }
        else
        {
            // If the character in str2 has not been mapped, create a new mapping
            mapS2S1[str2[i]] = str1[i];
        }
    }

    // If no conflicts were found, return true
    return true;
}

bool compare(char a, char b, const unordered_map<char, int> &freq)
{
    return freq.at(a) > freq.at(b) || (freq.at(a) == freq.at(b) && a < b);
}

string sortByFrequency(int n, string &s)
{
    // Write Your Code here
    int low = 0;

    map<char, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }

    for (auto x : mp)
    {
        while (x.second--)
        {

            s[low++] = x.first;
        }
    }
    return s;
}

int romanToInt(string s)
{
    // Write your code here
    unordered_map<char, int> romanValue{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    int result = 0;
    int currentValue = 0;
    int previousValue = 0;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        currentValue = romanValue[s[i]];

        if (currentValue >= previousValue)
        {
            result += currentValue;
        }
        else
        {
            result -= currentValue;
        }
        previousValue = currentValue;
    }

    return result;
}