#include "../includes/ft_tester.h"

char	*append_to_str(char *s1, char *s2)
{
	char	*new;

	new = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (!new)
		return (NULL);
	new[0] = '\0';
	strcat(new, s1);
	strcat(new, s2);
	return (new);
}
