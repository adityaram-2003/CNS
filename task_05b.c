#include <stdio.h>
#include <string.h>

int main()
{
    // Read the input string
    char plain[100] = "conrodlemar";
    printf("Before stuffing: %s\n", plain);

    // Define the start flag, esc flag and end flag
    char start[100] = "dlestx", esc[100] = "dle", end[100] = "dleetx";

    // Escape the escape character
    int pl = strlen(plain), el = strlen(esc);
    int i = 0, j = 0;
    char copy[100] = {0};
    for (i = 0; i < pl; i++)
    {
        if (strncmp(plain + i, esc, el) == 0)
        {
            strcat(copy, esc);
            strcat(copy, esc);
            i += 2;
            continue;
        }
        strncat(copy, plain + i, 1);
    }

    // Add stuffing to frame
    char frame[100] = {0};
    strcat(frame, start);
    strcat(frame, copy);
    strcat(frame, end);
    printf("After stuffing: %s\n", frame);

    return 0;
}