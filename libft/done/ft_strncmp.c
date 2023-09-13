#include "libft.h"

int	strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while ((count < n) && (s1[count] == s2[count]))
		count++;
	return (s1[count] - s2[count]);
}

#include <stdio.h>

int main() {
    char str1[] = "apple";
    char str2[] = "apple";

    int result = strncmp(str1, str2, 3);
    
    if (result == 0) {
        printf("The strings are equal.\n");
    } else if (result < 0) {
        printf("str1 comes before str2.\n");
    } else {
        printf("str1 comes after str2.\n");
    }
    
    return 0;
}

