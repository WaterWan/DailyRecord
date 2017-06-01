#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int
isleap(int y)
{
    return y%4==0 && (y%100 != 0 || y%400 == 0);
}

int mtab[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/* return length of month m in year y */
int
mlen(int y, int m)
{
    if(m == 1)    /* february */
        return mtab[m]+isleap(y);
    else
        return mtab[m];
}

void
main(void)
{
    FILE *fin, *fout;
    int i, m, dow, n, y;
    int ndow[7];

    fin = fopen("friday.in", "r");
    fout = fopen("friday.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d", &n);

    for(i=0; i<7; i++)
        ndow[i] = 0;

    dow = 0;    /* day of week: January 13, 1900 was a Saturday = 0 */
    for(y=1900; y<1900+n; y++) {
        for(m=0; m<12; m++) {
            ndow[dow]++;
            dow = (dow+mlen(y, m)) % 7;
        }
    }

    for(i=0; i<7; i++) {
        if(i)
            fprintf(fout, " ");
        fprintf(fout, "%d", ndow[i]);
    }
    fprintf(fout, "\n");

    exit(0);
}
