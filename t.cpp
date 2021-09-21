class Solution
{
public:
    int distinctsubseq(string s, string t, int i, string psf, int level)
    {
        if (level == t.length())
        {
            if (psf == t)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int count = 0;
        while (i < s.length())
        {
            if (s[i] == t[level])
            {
                count += distinctsubseq(s, t, i + 1, psf + s[i], level + 1);
            }
            i++;
        }

        return count;
    }
    int numDistinct(string s, string t)
    {

        int ans = 0;
        for (int i = 0; i <= s.length() - t.length(); i++)
        {
            if (s[i] != t[0])
            {
                continue;
            }
            string psf = "";
            ans += distinctsubseq(s, t, i + 1, psf + s[i], 1);
        }
    }
};