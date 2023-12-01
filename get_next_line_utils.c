#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *)s + ft_strlen(s));
	else
		return (0);
}

char	*ft_strdup(const char *str)
{
	char	*duplicate;
	int		length;

	length = ft_strlen(str);
	duplicate = (char *)malloc((length + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	ft_strlcpy(duplicate, str, length + 1);
	return (duplicate);
}

size_t	newline_index(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0' && s[n] != '\n')
		n++;
	return (n);
}

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	char	*temp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = (char *)malloc((ft_strlen(s1)
				+ ft_strlen(s2) + 1)  * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	temp = new_str;
	ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
	new_str += ft_strlen(s1);
	ft_strlcpy(new_str, s2, ft_strlen(s2) + 1);
	return (temp);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destination;
	char	*source;
	size_t	i;

	destination = (char *)dest;
	source = (char *)src;
	i = 0;
	if (destination < source)
		ft_strlcpy(destination, source, n);
	else if (destination > source)
	{
		i = n;
		while (i > 0)
		{
			destination[i - 1] = source[i - 1];
			i--;
		}
	}
	return (destination);
}
