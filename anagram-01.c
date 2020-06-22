#include <stdio.h>
#include <stdlib.h>

int str_len(char *s)
{
  int len = 0;
  while (*s++)
     ++len;
  
  return len;
 
}

// Given two strings, finds the minimum number of character deletions required to make the two strings anagrams.
int main() {
    char s1[10010],s2[10010];
    scanf("%s", s1);
    scanf("%s", s2);
    
    //gets(s2);
    int a[26]={0};
    for(int i=0;i<str_len(s1);i++)
        a[s1[i]-'a']++;
    for(int i=0;i<str_len(s2);i++)
        a[s2[i]-'a']--;
  
    long long int ans = 0;
    for(int i=0;i<26;i++)
        ans += abs(a[i]);
    printf ("\n%lld", ans);
    return 0;
}
