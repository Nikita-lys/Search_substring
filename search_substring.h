//  search_substring.h

#ifndef search_substring_h
#define search_substring_h

#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::ifstream;

const int charcount = 256;
const int maxplen = 401;
bool hasch[charcount];

void computing(string p, int f[maxplen][charcount])
{
    int m = p.length();
    for(int i = 0; i <= m; i++)
    {
        for(int j = 1; j < charcount; j++)
        {
            if (hasch[j])
            {
                int k = 0;
                if (m >= i + 1)
                    k = i + 1;
                else
                    k = m;
                
                while (k > 0)
                {
                    --k;
                    char c = p[k];
                    if ((k >= 0) && c == j)
                    {
                        int t1 = k, t2 = i;
                        while ((t1 > 0) && (p[t1] == p[t2]))
                        {
                            t1 = t1 - 1;
                            t2 = t2 - 1;
                        }
                        
                        if (t1 == 0)
                        {
                            k++;
                            break;
                        }
                    }
                }
                f[i][j] = k;
            }
        }
    }
}

int match(string t, int f[maxplen][charcount], int m)
{
    int n = t.length();
    int v = 0, q = 0;
    for (int i = 0; i < n; i++)
    {
        char c = t[i];
        v = f[q][c];
        q = f[q][c];
        if (v == m)
        {
            // cout << "Нашёл! ";
            return 1;
        }
    }
    return 0;
}

int allcomputing(string name, string p)
{
    int f[maxplen][charcount];
    int count = 0;
    string elem;
    ifstream in(name);
    while (true)
    {
        in >> elem;
        if (in.eof())
            break;
        transform(elem.begin(), elem.end(), elem.begin(), ::tolower);
        for(int j = 0; j < p.length(); j++)
        {
            char c = p[j];
            hasch[c] = true;
        }
        computing(p, f);
        count += match(elem, f, p.length());
    }
    return count;
}

#endif /* search_substring_h */
