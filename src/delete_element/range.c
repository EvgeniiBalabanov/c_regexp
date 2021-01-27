/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:35:09 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 17:03:07 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

void	ft_regexp_delete_range(t_regexp_range *range)
{
	if (range)
	{
		ft_regexp_delete_element(range->elem);
		free(range);
	}
}
