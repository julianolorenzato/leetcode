// https://leetcode.com/problems/roman-to-integer/

int romanToInt(char *s)
{
    int res = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        switch (s[i])
        {
        case 'I':
            if (s[i + 1] == 'V' || s[i + 1] == 'X')
            {
                res -= 1;
            }
            else
            {
                res += 1;
            }
            break;
        case 'V':
            res += 5;
            break;
        case 'X':
            if (s[i + 1] == 'L' || s[i + 1] == 'C')
            {
                res -= 10;
            }
            else
            {
                res += 10;
            }
            break;
        case 'L':
            res += 50;
            break;
        case 'C':
            if (s[i + 1] == 'D' || s[i + 1] == 'M')
            {
                res -= 100;
            }
            else
            {
                res += 100;
            }
            break;
        case 'D':
            res += 500;
            break;
        case 'M':
            res += 1000;
        }
    }

    return res;
}