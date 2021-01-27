/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   natural.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:04:59 by telron            #+#    #+#             */
/*   Updated: 2020/12/10 14:05:18 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

void	ft_regexp_delete_natural(t_regexp_natural *natural)
{
	if (natural)
		free(natural);
}
