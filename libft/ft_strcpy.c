/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:09:04 by pmartine          #+#    #+#             */
/*   Updated: 2016/01/30 19:04:02 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	int	k;

	k = 0;
	while (src[k])
	{
		dst[k] = src[k];
		k++;
	}
	dst[k] = src[k];
	return (dst);
}
