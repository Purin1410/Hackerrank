/*
Given an array of integers, find the sum of its elements.

For example, if the array , , so return .

Function Description

Complete the simpleArraySum function in the editor below. It must return the sum of the array elements as an integer.

simpleArraySum has the following parameter(s):

ar: an array of integers
Input Format

The first line contains an integer, , denoting the size of the array.
The second line contains  space-separated integers representing the array's elements.

Constraints


Output Format

Print the sum of the array's elements as a single integer.

Sample Input

6
1 2 3 4 10 11
Sample Output

31
Explanation

We print the sum of the array's elements
1 + 2 + 3 +4 + 10 + 11 = 31
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'simpleArraySum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY ar as parameter.
 */


int simpleArraySum(vector<int> ar) {
    int sum_ar = 0;
    for (int i = 0; i < ar.size(); i++) {
        sum_ar += ar[i];
    }
    return sum_ar;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ar_count_temp;
    getline(cin, ar_count_temp);

    int ar_count = stoi(ltrim(rtrim(ar_count_temp)));

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split(rtrim(ar_temp_temp));

    vector<int> ar(ar_count);

    for (int i = 0; i < ar_count; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = simpleArraySum(ar);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
