#include "regexp.h"

int		main(void)
{
	const char			*string;
	const char			*pattern;
	char				*group_0;
	char				*group_1;
	char				*group_2;
	char				*group_3;
	t_regexp			*regexp_struct;

	string = "RE    \t 1234 840   \nSE     ./path to dest.cub";
	pattern = "RE[ \t]+(\d+)[ \t]+(\d+)[ \t]+\n+SE[ \t]+(*+)";
	regexp_struct = ft_regexp_parse(string, pattern);
	if (regexp_struct)
	{
		group_0 = ft_regexp_group(0, regexp_findall_struct);
		group_1 = ft_regexp_group(1, regexp_findall_struct);
		group_2 = ft_regexp_group(2, regexp_findall_struct);
		group_3 = ft_regexp_group(3, regexp_findall_struct);
		printf("\"%s\"\n\"%s\"\n\"%s\"\n\"%s\"\n", group_0, group_1, group_2, group_3);
		ft_regexp_free(regexp_struct);
	else
		printf("Error map!");
	/*
	**	"RE \t 1234 840   \nSE ./path to dest.cub"
	**	"1234"
	**	"840"
	**	"./path to dest.cub"
	*/
	return (0);
}