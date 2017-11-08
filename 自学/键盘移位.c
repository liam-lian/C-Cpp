#include <stdio.h>
#include <stdlib.h>
char *s="`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";//常量数组
int main()
{
    int i;
    char c;
    while((c=getchar())!='\n'){
       for( i=1;s[i]&&s[i]!=c;i++);//找到i的位置
       if(s[i]) putchar(s[i-1]);
       else putchar(c);
    }
    return 0;
}
