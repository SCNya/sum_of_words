//ver. 1.0 by Alexeenko Vsevolod 11.01.13 20:11
#include "functions.h"

int main()
{
    short i, j, x, y, pr(0);
    bool t(false);
    string str_1, str_2;
    cout << "enter the word" << endl;
    cin >> str_1;
    //str_1 = "shine"; //shine + shine = light
    x = str_1.size();
    cout << "enter the result" << endl;
    cin >> str_2;
    //str_2 = "light";
    y = str_2.size();
    short mass_x [x], m_x [x], pat_1[x];
    short mass_y [y], m_y [y], pat_2[y];
    clear(m_y, y);
    clear(m_x, x);
    m_x[0] = 1;
    clear_2(mass_x, x);
    clear_2(mass_y, y);
    clear_2(pat_1, x);
    clear_2(pat_2, y);
    for(i = (x-1); i>=0; i--)
    {
        if (mass_x[i] == (-1))
        {
        mass_x[i] = pr;
        for(short k(x-1); k >= 0; k--)
            if(str_1[i] == str_1[k])
                mass_x[k] = pr;
        for(j = (y-1); j >= 0; j--)
            if(str_1[i] == str_2[j])
                mass_y[j] = pr;
        pr++;
        }
    }
    for(j = (y-1); j>=0; j--)
        if(mass_y[j] == -1)
        {
            mass_y[j] = pr;
            for(short n(y-1); n >= 0; n--)
                if(str_2[j] == str_2[n])
                    mass_y[n] = pr;
            pr++;
        }
    pr = 0;
    while(SUM(m_x, x, m_y, y))
    {
        if (m_y[0] != 0)
        {
        pattern(m_x, x, m_y, y, pat_1, pat_2);
        if ((comp(pat_1, mass_x, x) == true) && (comp(pat_2, mass_y, y) == true))
        {
            cout << endl << endl << "Result:" << endl << endl;
            if (x != y)
                for(i = 0; i < y-x; i++)
                        cout << "  ";
            for(i = 0; i < x; i++)
                    cout << " " << m_x[i];
            cout << endl;
            if (x != y)
                for(i = 0; i < y-x; i++)
                        cout << "  ";
            for(i = 0; i < x; i++)
                    cout << " " << m_x[i];
            cout << endl << endl;
            for(i = 0; i < y; i++)
                    cout << " " << m_y[i];
            pr++;
        }
        }
        (m_x[x-1])++;
        pick(m_x, x);
        if(m_x[0] == 9) t = true;
        if ((m_x[0] == 0) && (t)) break;
        clear(m_y, y);
        clear_2(pat_1, x);
        clear_2(pat_2, y);
    }
    if (pr == 0)
        cout << endl << endl << "No results!" << endl;
    else
        cout << endl << endl << pr << " - results!" << endl;
    return 0;
}
