/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regexp_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:30:34 by telron            #+#    #+#             */
/*   Updated: 2020/12/14 16:31:31 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

t_process	*ft_regexp_parse(const char *pattern, const char *string)
{
	t_regexp_elem	*regexp;
	size_t			index_group;
	t_process		process;
	t_process		*result;

	process.string = (char *)string;
	process.start = 0;
	process.stop = ft_strlen(process.string);
	index_group = 0;
	regexp = ft_regexp_parse_group(ft_regexp_create_natural(pattern, 0, ft_strlen(pattern)), &index_group);

	ft_putstr_fd("pattern -> ", 1);
	ft_putstr_fd((char *)pattern, 1);
	ft_putstr_fd("\nresult  -> ", 1);
	ft_regexp_check_element(regexp);

	result = ft_regexp_process_element(regexp, &process);
	if (result)
		if (!(result = ft_malloc_content(&process, sizeof(t_process))))
			ft_regexp_delete_element(regexp);
	return (result);
}
