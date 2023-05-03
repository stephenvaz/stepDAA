#include <stdio.h>
#include <string.h>

void matchString(char str[], char pat[], int q)
{
    int pat_len = strlen(pat);
    int str_len = strlen(str);
    int pat_hash = 0, str_hash = 0, h = 1, d = 256;
    int i, j;

    // Compute the value of h to be used later
    for (i = 0; i < pat_len - 1; i++)
    {
        h = (h * d) % q;
    }

    // Compute the hash values of the pattern and the first substring of the same length in the string
    for (i = 0; i < pat_len; i++)
    {
        pat_hash = (d * pat_hash + pat[i]) % q;
        str_hash = (d * str_hash + str[i]) % q;
    }

    // Check each substring of the same length as the pattern in the string for a match
    for (i = 0; i <= str_len - pat_len; i++)
    {
        // If the hash values match, check the actual characters for a match
        if (pat_hash == str_hash)
        {
            for (j = 0; j < pat_len; j++)
            {
                if (str[i + j] != pat[j])
                {
                    break;
                }
            }

            // If all characters match, print the index at which the match occurs in the string and return
            if (j == pat_len)
            {
                printf("\nMatch Found at index: %d \n", i);
                return;
            }
        }

        // Compute the hash value of the next substring using the previous substring's hash value
        if (i < str_len - pat_len)
        {
            str_hash = (d * (str_hash - str[i] * h) + str[i + pat_len]) % q;

            if (str_hash < 0)
            {
                str_hash = (str_hash + q);
            }
        }
    }

    // If no match is found, print a message indicating so
    printf("\nMatch Not Found\n");
}


int main()
{
    char str[100], pat[100];
    printf("\nString: ");
    scanf("%[^\n]s", str);
    getchar();
    printf("\nPattern: ");
    scanf("%[^\n]s", pat);
    int q = 269;
    matchString(str, pat, q);
    return 0;
}