#include <stdio.h>
#include <stdlib.h>

 int main(void)
{
    // open the given file
    FILE *file = fopen("card.raw", "r");

    // condition to check if file is opened or not
    if (file == NULL)
    {
        fprintf(stderr, "OOPS FILE IS NULL");
        return 0;
    }
    // contains the values present in raw
    unsigned char buffer[512];
    // work as the flag if current file data is reading
    int num_files = 0;
    // used to give the name to the new jpg files
    int num_image = 0;

    // temp variable to create & write new files
    FILE *file_temp = NULL;

    // iterate over raw file
     while ( fread(buffer, 512, 1, file) == 1)
    {
        // check for the jpg header
       if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (num_image == 1)
                fclose(file_temp);
            else
                num_image = 1;

            char filename[8];
            sprintf(filename, "%03d.jpg", num_files);
            file_temp = fopen(filename, "a");
            num_files++;
        }

        if (num_image == 1)    fwrite(&buffer, 512, 1, file_temp);

    }


    fclose(file);
    fclose(file_temp);
}
