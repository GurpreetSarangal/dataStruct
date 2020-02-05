#include <iostream>
using namespace std;

#define ll long long int

/*
After the release of Avengers, Ironman and Thor got into a fight and Ironman challenged Thor to find out the number of numbers between 1 and n
which are divisible by any of the prime numbers less than 20. Ironman being great at maths quickly answered the question but then Thor asked him 
to write a program for it. Ironman however found it quite difficult as he did not wanted to write so many lines of code. he knows that you are 
smart and can code this up easily. Can you do it?

Input Format
The first line consists of number of test cases t. then follow t lines which consists of number n for each test case.
Constraints

1 <= test cases <= 10 1 <= n <= 10^18

Output Format
the answer to each test case each in different line

Sample Input

5
5
10
12
15
18

Sample Output

4
9
11
14
17

Explanation

for n = 5 2 and 4 are divisible by 2 and 3 is divisible by 3 and 5 by 5. hence ans = 4.

*/

int main()
{

    int t;
    cin >> t;

    ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19};

    while (t--)
    {

        ll n;
        cin >> n;
        ll ans = 0;
        ll subsets = (1 << 8) - 1;
        for (ll i = 1; i <= subsets; i++)
        {
            ll denominator = 1ll;
            ll set_bits = __builtin_popcount(i);

            for (ll j = 0; j <= 7; j++)
            {
                if (i & (1 << j))
                {
                    denominator = denominator * primes[j];
                }
            }

            if (set_bits & 1)
            {

                ans += n / denominator;
            }
            else
            {
                ans -= n / denominator;
            }
        }

        cout << ans << "\n";
    }
}