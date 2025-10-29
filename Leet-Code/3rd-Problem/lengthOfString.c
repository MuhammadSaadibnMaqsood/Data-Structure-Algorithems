#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s)
{
    char str[100] = "";
    int length = strlen(s);
    int max = 0;
    int k = 0;

    for (int i = 0; i < length; i++)
    {
        int equal = 0;

        for (int j = 0; j < k; j++)
        {
            if (s[i] == str[j])
            {
                equal = 1;
                break;
            }
        }

        if (equal)
        {

            if (k > max)
                max = k;
            memset(str, 0, sizeof(str));
            k = 0;
        }

        str[k] = s[i];
        k++;
        str[k] = '\0';
    }

    if (k > max)
        max = k;

    printf("Longest substring: %s\n", str);
    return max;
}

int main()
{
    char *string = "pwwkew";
    int digits = lengthOfLongestSubstring(string);

    printf("Length of longest substring without repeat: %d\n", digits);
    return 0;
}
