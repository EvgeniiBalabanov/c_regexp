/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:24:54 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 09:40:20 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

void		ft_regexp_check_range(t_regexp_range *range)
{
	ft_putstr_fd("range(", 1);
	ft_regexp_check_element(range->elem);
	ft_putstr_fd(", from ", 1);
	if ((int)range->min != -1)
		ft_putnbr_fd((int)range->min, 1);
	ft_putstr_fd(" to ", 1);
	if ((int)range->max != -1)
		ft_putnbr_fd((int)range->max, 1);
	ft_putstr_fd(")", 1);
}
