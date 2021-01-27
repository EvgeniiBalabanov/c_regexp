/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_or_more.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:52:54 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 08:16:30 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

t_regexp_elem	*ft_regexp_create_one_or_more(t_regexp_elem *element)
{
	return (ft_regexp_create_range(element, 1, -1));
}
