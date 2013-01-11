void pick(short *mas, short size)
{
    if(size > 0)
    {
    if(mas[size-1] == 10)
    {
        mas[size-1] = 0;
        mas[size-2]++;
        pick(mas, size-1);
    }
    pick(mas, size-1);
    }
}

void pattern(short *m_1, short x, short *m_2, short y, short *pat_1, short *pat_2)
{
    short pr(0);
    for(short i(x-1); i >= 0; i--)
    {
        if (pat_1[i] == (-1))
        {
        pat_1[i] = pr;
        for(short k(x-1); k >= 0; k--)
            if(m_1[i] == m_1[k])
                pat_1[k] = pr;
        for(short j(y-1); j>= 0; j--)
            if(m_1[i] == m_2[j])
                pat_2[j] = pr;
        pr++;
        }
    }
    for(short j(y-1); j >= 0; j--)
        if(pat_2[j] == (-1))
        {
            pat_2[j] = pr;
            for(short n(y-1); n >= 0; n--)
                if(m_2[j] == m_2[n])
                    pat_2[n] = pr;
            pr++;
        }
}

bool SUM(short *m_1, short x, short *m_2, short y)
{
    short sum;
    bool next(true);
    for(short i(x-1); i >= 0; i--)
    {
        sum = 0;
        sum = m_1[i] + m_1[i];
        if (x == y)
        {
        if (sum >= 10)
        {
            if (i == 0)
            next = false;
            else
            {
              m_2[i-1] = 1;
              m_2[i] += sum % 10;
            }
        }
        else
        {
            m_2[i] += sum;
        }
        }
        else
        {
            if (sum >= 10)
            {
                  m_2[i+(y-x-1)] = 1;
                  m_2[i+(y-x)] += sum % 10;
            }
            else
            {
                m_2[i+(y-x)] += sum;
            }
        }
    }
    return next;
}

void clear(short *m, short size)
{
    for(short j(0); j < size; j++)
            m[j] = 0;
}
void clear_2(short *m, short size)
{
    for(short j(0); j < size; j++)
            m[j] = -1;
}

bool comp(short *one, short *two, short size)
{
    bool res(true);
    for(short i(0); i < size; i++)
    {
        if (one[i] != two[i])
        {
            res = false;
            break;
        }

    }
    return res;
}

