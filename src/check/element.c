/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:22:48 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 09:40:12 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

void ft_regexp_check_element(t_regexp_elem *elem)
{
	((void (*)(void *))elem->check)(elem->content);
}
