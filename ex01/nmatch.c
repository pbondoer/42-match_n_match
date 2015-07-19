/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 23:05:09 by pbondoer          #+#    #+#             */
/*   Updated: 2015/07/19 23:30:44 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (!(*s1 == '\0' || *s2 == '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		nmatch(char *s1, char *s2)
{
	if (ft_strcmp(s2, "*") == 0 || ft_strcmp(s1, s2) == 0)
		return (1);
	if (ft_strlen(s1) == 0)
		return (0);
	if (s1[0] == s2[0])
		return 1 + (nmatch(s1 + 1, s2 + 1));
	if (s2[0] == '*')
		return 1 + (nmatch(s1 + 1, s2) || nmatch(s1, s2 + 1));
	return (0);
}
