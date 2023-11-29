#include "get_next_line.h"

int main()
{
    int fd = open("tests/test.txt", O_RDWR);
    char *s = get_next_line(fd);

    if (!s)
        printf("not here");
    while(s)
    {
        printf("[%s]\n", s);
        free(s);
        s = get_next_line(fd);
    }
}