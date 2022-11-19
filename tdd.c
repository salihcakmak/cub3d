/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 01:47:31 by scakmak           #+#    #+#             */
/*   Updated: 2022/10/23 10:33:23 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <sys/stat.h>
#include <string.h>

/*
./cub3d
./cub3d ""
./cub3d "     "
./cub3d kkkkxxxtt
./cub3d "kkkxxxxtt" "llalal"
./cub3d "tttttt" "./map/map.cub"
./cub3d "./map/map.cub" "./map/map2.cub"
./cub3d "./map/map.txt" or ./cub3d "./map/map.ber" ... 

True
./cub3d ./map/map.cub
*/

void	test_all(void)
{
	test_my_strlen();
	test_ends_with();
}

void	test_my_strlen(void)
{
	int		i;
	char	*str[] = {"", "XFHH", NULL, "1", "fsaereaf efaewa fatafdsaf ew rsfaef wefsdfa ewa ", 0};
	int		must[] = {0, 4, 0, 1, 48};
	
	printf("%smy_strlen test starting...\n\n%s", YELLOW, RESET);
	i = 0;
	while (i < 5)
	{
		if (my_strlen(str[i]) == must[i])
			printf("%sTest Case %d SUCCESS\n%s", GREEN, i + 1, RESET);
		else
			printf("%sTest Case %d FAILURE\n%s", RED, i + 1, RESET);
		i++;
		//sleep(1);
	}
	printf("%s\nstrlen test ending...\n%s", YELLOW, RESET);
}

void	test_ends_with(void)
{
	int		i;
	char	*str[] = {"", NULL, "a", "  space	 ", "file", "file.txt", "map.ber", "map.cub", "\0hello space", "", NULL, "docker"};
	char	*suffix[] = {"lorem", "ipsum", ".jpg", "ace", "nafile", "xt", ".ber", "map.cub", "space", "", NULL, ""};
	int		must[] = {0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1};
	
	printf("%sends_with test starting...\n\n%s", YELLOW, RESET);
	i = 0;
	while (i < 12)
	{
		if (ends_with(str[i], suffix[i]) == must[i])
			printf("%sTest Case %d SUCCESS\n%s", GREEN, i + 1, RESET);
		else
			printf("%sTest Case %d FAILURE\n%s", RED, i + 1, RESET);
		i++;
		//sleep(1);
	}
	printf("%s\nends_with test ending...\n%s", YELLOW, RESET);
}



void	test_get_file_descriptor(void)
{
	char	*dirname = "testdir";
	int	fd[5];

	if (mkdir(dirname, 0777) < 0)
	{
		perror("mkdir ");
		exit(1);
	}
	fd [0] = open("testDir/file", O_CREAT);
	fd [1] = open("testDir/file.txt", O_CREAT);
	fd [2] = open("testDir/file.cub", O_CREAT);
	fd [3] = open("testDir/file.ber", O_CREAT);
	fd [4] = open("testDir/file.c", O_CREAT);
	int	j = 0;
	while (j < 5)
		close(fd[j++]);
	
	
	 int	i;
	char	*filename[] = {"", NULL, "testDir/file", "testDir/file.txt", "testDir/file.cub", "testDir/file.ber", "testDir/file.c"};
	
	if (remove("testDir/file") < 0 || remove("testDir/file.txt") < 0 || remove("testDir/file.cub") < 0 || remove("testDir/file.ber") < 0 || remove("testDir/file.c") < 0)
	{ 
		perror("remove ");
		exit(1);
	}
	if (rmdir(dirname) < 0)
	{
		perror("rmdir ");
		exit(1);
	}
}
