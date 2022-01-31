#include <iostream>
#include <string>

using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll characterHealth, characterAttack, MonsterHealth, MonsterAttack, k, w, a;
        cin >> characterHealth >> characterAttack >> MonsterHealth >> MonsterAttack;
        cin >> k >> w >> a;

        bool Winner = false;

        for (ll i = 0; i <= k; i++)
        {
            ll curr = i;
            ll temp1 = characterAttack + (w * curr);
            ll temp2 = characterHealth + (a * (k - curr));
            ll val1 = MonsterHealth / temp1;
            ll val2 = temp2 / MonsterAttack;
            if (MonsterHealth % temp1)
            {
                val1++;
            }
            if (temp2 % MonsterAttack)
            {
                val2++;
            }
            if (val1 <= val2)
            {
                Winner = true;
                break;
            }
        }

        if (Winner)
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
}