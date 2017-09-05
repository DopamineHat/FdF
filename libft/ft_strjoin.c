/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:42:05 by adeletan          #+#    #+#             */
/*   Updated: 2016/12/06 13:26:10 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, int flag)
{
	char	*ret;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((ret = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	ft_strcpy(ret, s1);
	*(ret + ft_strlen(s1)) = '\0';
	ft_strcat(ret, s2);
	*(ret + len) = '\0';
	if (flag == 1 || flag == 4)
		ft_strdel((char**)&s1);
	if (flag == 2 || flag == 4)
		ft_strdel((char**)&s2);
	return (ret);
}
