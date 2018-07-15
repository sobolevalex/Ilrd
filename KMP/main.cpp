// C++ program for implementation of KMP pattern searching
// algorithm
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
 
void computeLPSArray(const char *pat, int M, int *lps);
 
// Prints occurrences of txt[] in pat[]
int KMPSearch(const char *pat, const char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int ret = -1;
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int *lps = new int[M];
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
 
        if (j == M)
        {
            printf("Found pattern at index %d \n", i-j);
            ret = i-j; 
            j = lps[j-1];
        }
 
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    delete[] lps;
    return ret; 
}
 
// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(const char *pat, int M, int *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar 
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
 
// Driver program to test above function
int main()
{
    const char *txt = "ABABDABACDABABCABAB";
    const char *pat = "ABABCABAB";
    int result = KMPSearch(pat, txt);
    std::cout << "Index of dplication :" << result << std::endl;
    getchar();
    return 0;
}