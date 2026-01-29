#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Helper to add two large string numbers
string addStrings(string num1, string num2)
{
    string sum = "";
    int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry)
    {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int currentSum = digit1 + digit2 + carry;
        sum += to_string(currentSum % 10);
        carry = currentSum / 10;
    }
    reverse(sum.begin(), sum.end());
    return sum;
}

// Helper to subtract two large string numbers (assuming num1 >= num2)
string subtractStrings(string num1, string num2)
{
    string diff = "";
    int n1 = num1.length(), n2 = num2.length();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int carry = 0;
    for (int i = 0; i < n2; i++)
    {
        int sub = ((num1[i] - '0') - (num2[i] - '0') - carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        diff.push_back(sub + '0');
    }
    for (int i = n2; i < n1; i++)
    {
        int sub = ((num1[i] - '0') - carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        diff.push_back(sub + '0');
    }
    reverse(diff.begin(), diff.end());
    return diff;
}

// Helper to pad zeros for equal length
int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0; i < len2 - len1; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
            str2 = '0' + str2;
    }
    return len1;
}

long long multiplySingleBit(string a, string b) { return (a[0] - '0') * (b[0] - '0'); }

// Main Karatsuba Function
string karatsuba(string X, string Y)
{
    int n = makeEqualLength(X, Y);

    if (n == 0)
        return "0";
    if (n == 1)
        return to_string(multiplySingleBit(X, Y));

    int fh = n / 2;  // First half length
    int sh = n - fh; // Second half length

    string Xl = X.substr(0, fh);
    string Xr = X.substr(fh, sh);
    string Yl = Y.substr(0, fh);
    string Yr = Y.substr(fh, sh);

    // Recursively calculate the three products
    string P1 = karatsuba(Xl, Yl);
    string P2 = karatsuba(Xr, Yr);
    string P3 = karatsuba(addStrings(Xl, Xr), addStrings(Yl, Yr));

    // P3 - P1 - P2
    string middle = subtractStrings(P3, addStrings(P1, P2));

    // P1 * 10^(2*sh) + middle * 10^sh + P2
    for (int i = 0; i < 2 * sh; i++)
        P1.append("0");
    for (int i = 0; i < sh; i++)
        middle.append("0");

    return addStrings(addStrings(P1, middle), P2);
}

int main()
{
    string num1, num2;
    cout << "Enter two large numbers: ";
    cin >> num1 >> num2;

    auto start = high_resolution_clock::now();
    string result = karatsuba(num1, num2);
    auto end = high_resolution_clock::now();

    // Remove leading zeros
    result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));

    cout << "Product: " << result << endl;
    cout << "Karatsuba Time: "
         << duration_cast<nanoseconds>(end - start).count()
         << " nanoseconds" << endl;
    return 0;
}