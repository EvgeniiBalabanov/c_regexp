/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 07:52:30 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 17:03:46 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

void	ft_regexp_delete_set_char(t_regexp_set_chars *set_char)
{
	if (set_char)
	{
		free(set_char->chars);
		free(set_char);
	}
}
