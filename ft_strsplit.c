/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 08:51:56 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/13 14:07:25 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**filltab(char **list, char *s, char c)
{
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			y = 0;
			while (s[i] != c && s[i] != '\0')
			{
				list[x][y] = s[i];
				i++;
				y++;
			}
			list[x][y] = '\0';
			x++;
		}
	}
	return (list);
}

static char	**lenword(char *s, char **list, char c)
{
	int		i;
	int		a[2];
	int		j;

	j = 0;
	a[0] = 0;
	a[1] = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		a[0] = i;
		while (s[i] != c && s[i])
			i++;
		a[1] = i;
		if ((a[1] - a[0]) != 0)
		{
			if (!(list[j] = (char *)malloc(sizeof(char) * (a[1] - a[0]))))
				return (0);
			list[j][a[1] - a[0]] = '\0';
		}
		j++;
	}
	return (list);
}

static int	countword(char const *s, char c)
{
	int		i;
	int		count;

	if (s[0] != c)
		count = 1;
	else
		count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			if (s[i + 1] != c && s[i + 1] != '\0')
				count++;
			i++;
		}
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**list;
	int		mot;

	if (!(s))
		return (NULL);
	if (s[0] == '\0')
		return (NULL);
	mot = countword(s, c);
	if (!(list = (char **)malloc(sizeof(char *) * (mot + 1))))
		return (NULL);
	list = lenword((char *)s, list, c);
	if (!(list[mot] = (char *)malloc(sizeof(char) * 1)))
		return (0);
	list = filltab(list, (char *)s, c);
	list[mot] = NULL;
	return (list);
}
