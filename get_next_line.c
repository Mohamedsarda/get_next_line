#include "get_next_line.h"

char	*get_buffer_value(int fd)
{
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if(read(fd, buffer, BUFFER_SIZE) < 0 || !buffer)
	{
		free(buffer);
		return (NULL);
	}
	buffer[BUFFER_SIZE + 1] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*str;

	if ((fd < 0 || fd > 1024) && (BUFFER_SIZE <= 0))
		return (NULL);
	str = get_buffer_value(fd);
	return (str);
}

int main()
{
	int fd = open("test.txt", O_RDWR | O_CREAT);
	printf("\n[%s]\n", get_next_line(fd));
	printf("\n[%s]\n", get_next_line(fd));
	// printf("\n[%s]\n", get_next_line(fd));
}
