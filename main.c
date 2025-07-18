/*#include <fcntl.h>
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
}*/

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

/*int main(void)
{
	int fd1 = open("test", O_RDONLY);
	int fd2 = open("test2", O_RDONLY);

	char *line1 = get_next_line(fd1);
	char *line2 = get_next_line(fd2);
	char *line3 = get_next_line(fd1);
	char *line4 = get_next_line(fd2);

	printf("FD1: %s", line1);
	printf("FD2: %s", line2);
	printf("FD1: %s", line3);
	printf("FD2: %s", line4);

	free(line1); free(line2); free(line3); free(line4);
	close(fd1); close(fd2);
}
*/


#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int     main(void)
{
        int fd1 = open("test", O_RDONLY);
       	int fd2 = open("test2", O_RDONLY);
	int fd3 = open("test3", O_RDONLY);

        if(fd1 < 0 || fd2 < 0 || fd3 < 0)
        {
                perror("open");
                return (1);
        }


       	char *line1 = NULL;
    	char *line2 = NULL;
    	char *line3 = NULL;

    while (1)
    {
        int printed = 0;

       // printf("1------------->line1: %s\n",line1);
	line1 = get_next_line(fd1);
       // printf("2------------->line1: %s\n",line1);
       	if (line1)
        {
            printf("fd1 --> %s", line1);
            //printf("-------->antes de free1");
	    free(line1);
            printed = 1;
        }

       line2 = get_next_line(fd2);
        if (line2)
        {
            printf("fd2 --> %s", line2);
            free(line2);
            printed = 1;
        }

        line3 = get_next_line(fd3);
        if (line3)
        {
            printf("fd3 --> %s", line3);
            free(line3);
            printed = 1;
        }

        if (!printed)
            break;
    }

    close(fd1);
    close(fd2);
    close(fd3);


        return  (0);
}

