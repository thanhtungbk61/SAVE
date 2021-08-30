#include <stdio.h>
#include <stdlib.h>

// void main(void)
// {
//     int c;
//     int count=0;
//     while((c =getchar()) != EOF)
//     {
//         if(count == 0)
//         {
//             printf("%c", c);
//         }
//         if(c == ' ')
//             count ++;
//         else
//             count =0;

//     }
//     printf("%d\n", c);
// }

// github code

#include <stdio.h>

#define YES 1
#define NO  0

int main(void)
{
	int c;          /* current input character */
	int blank;      /* flag for the status of the previous character */

	blank = NO;
	while ((c = getchar()) != EOF) {
		if (c != ' ')
			blank = NO;
		if (!blank)
			putchar(c);
		if (c == ' ')
			blank = YES;

        // 1.10
        if(c == '\t')
            printf("\\t");
	}
	return 0;
}