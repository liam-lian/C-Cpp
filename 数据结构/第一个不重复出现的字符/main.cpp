#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char *s="asdasdasdasddq";
    int a[26]={0};
    for(int i=0;i<strlen(s);i++)
        a[s[i]-'a']++;
    for(int i=0;i<26;i++)
        if(a[i]==1)
    {
        cout<<char(i+'a');
        break;
    }
    return 0;
}
