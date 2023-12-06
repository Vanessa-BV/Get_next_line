#include "get_next_line.h"

int	string_char(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (size > 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
			size--;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	char	*temp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = (char *)malloc((ft_strlen(s1) \
				+ ft_strlen(s2) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	temp = new_str;
	ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
	new_str += ft_strlen(s1);
	ft_strlcpy(new_str, s2, ft_strlen(s2) + 1);
	return (temp);
}
