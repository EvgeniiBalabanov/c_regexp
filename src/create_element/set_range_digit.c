/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_range_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 07:18:41 by telron            #+#    #+#             */
/*   Updated: 2020/12/10 14:30:35 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

t_regexp_elem	*ft_regexp_create_set_range_digit(void)
{
	return (ft_regexp_create_set_range('0', '9'));
}
