#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
/* compares strings for alphabetical ordering */
int strcmpi (char *s, char *t)
{
  while (*s && tolower (*s) == tolower (*t))
    {
      s++;
      t++;
    }
  return tolower (*s) - tolower (*t);
}
/* allocates memory with a check for successful allocation */
void *dmalloc (size_t size)
{
  void *p = malloc (size);
  if (!p)
    {
      printf ("memory allocation failed\n");
      exit (1);
    }
  return p;
}
