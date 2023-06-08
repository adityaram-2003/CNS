#include <stdio.h>
#include <string.h>

int main()
{
    // Read the data bits
    char plain[100] = "010101101111111111101";
    printf("Before stuffing: %s\n", plain);

    // Initialize a bit stuff
    char stuff[100] = "01111110";
    
    // Add 0 after 5 consecutive 1's
    char copy[100]= {0};
    int pl = strlen(plain);
    int i = 0, j = 0, c = 0;
    for (i = 0; i < pl; i++)
    {
        copy[j++] = plain[i];
        if (plain[i] == '1')
        {
            c++;
        }
        else
        {
            c = 0;
        }
        if (c == 5)
        {
            c = 0;
            copy[j++] = '0';
        }
    }

    // Add stuff before and after plaintext to form a frame
    char frame[100] = {0};
    strcat(frame, stuff);
    strcat(frame, copy);
    strcat(frame, stuff);
    printf("After stuffing: %s\n", frame);
    
    return 0;
}