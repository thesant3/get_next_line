#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int fd;
	char *line;

	fd = open("test", O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		return (1);
	}

	int a = 0;
	while ((line = get_next_line(fd)) != NULL)
	//while (1)
	{
		printf("%d<<%s\n",a, line);
		free(line);
		
	}
        free(line);
	
	close(fd);

	return	(0);
}
