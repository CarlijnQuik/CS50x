/**
 * recover.c
 *
 * Edited by student Carlijn Quik 11334231
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>

#define BLOCKSIZE 512

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 1)
    {
        printf("Usage: ./recover\n");
        return 1;
    }
    // open memory card file
    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        printf("Could not open\n");
        return 2;
    }
    
    unsigned char data[BLOCKSIZE];
    FILE* img;
    int counter = 0;
    char title[8];
    // read memory card
    while (fread(&data, BLOCKSIZE, 1, inptr) > 0)
    {
        // find beginning of jpg
        if (data[0] == 0xff && data[1] == 0xd8 && data[2] == 0xff && (data[3] >= 0xe0 && data[3] <= 0xef))
        {
            if (counter > 0)
            {
                // close img when open
                fclose(img);
            }
            // open a new jpg
            sprintf(title, "%03d.jpg", counter);
            img = fopen(title, "a");
            counter++;
        }
        if (counter > 0)
        {
            // write to img
            fwrite(&data, BLOCKSIZE, 1, img);
        }
    }
    // close files
    fclose(img);
    fclose(inptr);
    return 0;
}
