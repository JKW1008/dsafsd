/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:20:06 by kjung             #+#    #+#             */
/*   Updated: 2024/04/08 17:19:57 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	char	*result;
	size_t	str_len;

	str_len = ft_strlen(str);
	if (start >= str_len)
		return (ft_strdup(""));
	else if (len + start > str_len)
		substr = (char *)malloc((str_len - start + 1) * sizeof(char));
	else
		substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	result = substr;
	while (*(str + start) && len-- > 0)
		*substr++ = *(str + start++);
	*substr = '\0';
	return (result);
}
