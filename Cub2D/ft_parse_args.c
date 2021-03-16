#include "./includes/cub.h"

static int ft_check_str(char *str, char *s, int num)
{
	size_t len;
	len = 0;
	if (*str && (len = ft_strlen(str)))
	{
		if (len < 5)
			return (0);
		if (!(ft_strncmp(&str[len - num], s, num)))
			return (1);
	}
	return (0);
}

int ft_parse_args(int ac, char *filename, char *save)
{
	int flag;
	flag = 0;
	if (!(ft_check_str(filename, ".cub", 4)))
		ft_error(ERR_FILENAME);
	if (ac == 2 && !save)
		flag = 1;
	else if (ac == 3 && save != NULL)
		flag = ft_check_str(save, "--save", 6);
	if (!flag)
		ft_error(ERR_ARG_SAVE);
	return (1);
}
