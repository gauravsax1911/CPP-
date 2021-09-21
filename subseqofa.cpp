#include <bits/stdc++.h>
using namespace std;

int noofsubseq(string s, int idx, int i, int j, int k)
{
    if (idx == s.length())
    {
        if (i != 0 && j != 0 && k != 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (i == 0)
    {
        int c2 = 0, c1 = 0;
        if (s[idx] == 'a')
        {
            c1 = noofsubseq(s, idx + 1, i + 1, j, k);
        }
        c2 = noofsubseq(s, idx + 1, i, j, k);
        return c1 + c2;
    }

    else if (j == 0)
    {
        int c2 = 0, c3 = 0;
        if (s[idx] == 'b')
        {
            c3 = noofsubseq(s, idx + 1, i, j + 1, k);
        }
         c2 = noofsubseq(s, idx + 1, i, j, k);
        return c2 + c3;
    }

    else if (k == 0)
    {
        int c4 = 0, c2 = 0;
        if (s[idx] == 'c')
        {
            int c4 = noofsubseq(s, idx + 1, i, j, k + 1);
        }
        c2 = noofsubseq(s, idx + 1, i, j, k);
        return c2 + c4;
    }
    else
    {
        int c1 = 0, c2 = 0;
        if (s[idx] == 'a')
        {

            c1 = noofsubseq(s, idx + 1, i + 1, j, k);
        }

        else if (s[idx] == 'c')
        {
            c1 = noofsubseq(s, idx + 1, i, j, k + 1);
        }
        else if (s[idx] == 'b')
        {
            c1 = noofsubseq(s, idx + 1, i, j + 1, k);
        }
        c2 = noofsubseq(s, idx + 1, i, j, k);
        return c1 + c2;
    }

}

int noofsubseq(string s)
{
  return  noofsubseq(s,0,0,0,0);

}
int main()
{
    string s = "abbc";
    cout<<noofsubseq(s);
}