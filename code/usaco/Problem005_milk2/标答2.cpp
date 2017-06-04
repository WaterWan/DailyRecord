#include <fstream.h>
#include <stdlib.h>

struct event
{
 long seconds;   /* seconds since 5 am */
 signed char ss; /* start = 1, stop = -1 (delta number of farmers milking)
*/
};

int eventcmp (const event *a, const event *b)
{
 if (a->seconds != b->seconds)
  return (a->seconds - b->seconds); /* 300 before 500 */

 return (b->ss - a->ss); /* 1 (start) before -1 (stop) */
}

int main ()
{
 ifstream in;
 ofstream out;

 in.open("milk2.in");
 out.open("milk2.out");

 int num_intervals, num_events, i;
 event events[5000 * 2];

 in >> num_intervals;
 num_events = num_intervals * 2;
 for (i = 0; i < num_intervals; ++i)
 {
  in >> events[2*i  ].seconds; events[2*i  ].ss = 1;
  in >> events[2*i+1].seconds; events[2*i+1].ss = -1;
 }

 qsort(events, num_events, sizeof(event),
  (int(*)(const void*, const void*)) eventcmp);

/* for (i = 0; i < num_events; ++i)
  out << events[i].seconds
    << (events[i].ss == 1 ? " start" : " stop") << endl; */

 int num_milkers = 0, was_none = 1;
 int longest_nomilk = 0, longest_milk = 0;
 int istart, ilength;

 for (i = 0; i < num_events; ++i)
 {
  num_milkers += events[i].ss;

  if (!num_milkers && !was_none)
  {
   /* there are suddenly no milkers. */
   ilength = (events[i].seconds - istart);
   if (ilength > longest_milk)
    longest_milk = ilength;
   istart = events[i].seconds;
  }
  else if (num_milkers && was_none)
  {
   /* there are suddenly milkers. */
   if (i != 0)
   {
    ilength = (events[i].seconds - istart);
    if (ilength > longest_nomilk)
     longest_nomilk = ilength;
   }
   istart = events[i].seconds;
  }

  was_none = (num_milkers == 0);
 }

 out << longest_milk << " " << longest_nomilk << endl;

 return 0;
}
