/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 06:33:55 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 17:03:55 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

void	ft_regexp_delete_set_range(t_regexp_set_range *set_range)
{
	if (set_range)
		free(set_range);
}
