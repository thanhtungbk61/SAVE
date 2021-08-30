// page 62

#include <stdio.h>
#include <string.h>

void deleteChar(char out[], char compare[])
{
    int k =0, j=0;
    for(int i =0; out[i] != '\0'; i++)
    {
        for(j=0; (compare[j] != '\0' && out[i] != compare[j]) ; j++);
        if(out[i] != compare[j])
            out[k++] = out[i];
    }
    out[k] = '\0';
    printf("%d\n", k);
}


void main(void)
{
    char out[] = "clean* *this- *str*-ing *** ---";
    char compare[] = "*-";

    deleteChar(out, compare);
    printf("dataout: %s\n", out);
}



// #include <stdio.h>

// #define MAXCHAR 1000

// /* functions */
// void squeeze(char [], char []);

// void squeeze(char s1[], char s2[])
// {
// 	int i, j, k;

// 	k = 0;
// 	for (i = 0; s1[i] != '\0'; ++i) {
// 		for (j = 0; s2[j] != '\0' && s1[i] != s2[j]; ++j)
// 			;
// 		if (s2[j] == '\0') /* match not found */
// 			s1[k++] = s1[i];
// 	}
// 	s1[k] = '\0';
// }

// int main(void)
// {
// 	char string1[MAXCHAR] = { "clean* *this- *str*-ing *** ---" };
// 	char string2[MAXCHAR] = { "*-" };

// 	squeeze(string1, string2);
// 	printf("%s\n", string1);

// 	return 0;
// }