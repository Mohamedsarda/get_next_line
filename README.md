# GET NEXT LINE
Calling your function get_next_line in a loop will therefore allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines. Therfore, make sure that your function behaves well when it reads from a file, from the standard output, from a redirection etc. For the mandatory part, no call to another function will be done on the file descriptor between 2 calls of get_next_line.

Finally we consider that get_next_line has an undefined behavior when reading from a binary file. You may make this work accordingly, but its not part of the bonus nor is it required.
