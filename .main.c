#include "get_next_line.h"

int main()
{
    int fd = open("tests/test.txt", O_RDONLY);
    //
    char *s = get_next_line(fd);

    if (!s)
        printf("str : [%s]\n", s);
    while (s)
    {
        printf("[%s]\n", s);
        free(s);
        s = get_next_line(fd);
    }
    // printf("[%s]\n", get_next_line(fd_1));
    // printf("[%s]\n", get_next_line(fd));
    // while (1)
    //     ;
}
