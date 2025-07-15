#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int fd;
	char *line;
	int i = 0;

	fd = open("test", O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		
		printf("%d<<%s",i,line);
		free(line);
		i++;
	}
        free(line);
	
	close(fd);

	return	(0);
}
