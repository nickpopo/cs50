#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    
    if(argc!=2)
    {
        fprintf(stderr, "Usage: ./recove input_file\n");
        return 1;
    }
    
    FILE *inFile = fopen(argv[1], "r");
    
    if(inFile==NULL)
    {
        fprintf(stderr, "Can't read the file");
        return 2;
    }
    
    
    char jpegName[8];
    
    int counter = 0;
    
    uint8_t *buffer = malloc(sizeof(uint8_t)*512);
    
    FILE *img = NULL;
    
    while (feof(inFile) == 0)
    {   
        
        fread(buffer, sizeof(uint8_t), 512, inFile);
        
        // for( int i = 0; i < 4; i++)
        //     printf("0x%02x\n", buffer[i]);
        
        if( buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {   
            
            if(img !=NULL)
                fclose(img);
                
            sprintf(jpegName, "%03i.jpg", counter);
                
            img = fopen(jpegName, "w");
            
            if(img == NULL)
            {
                fprintf(stderr, "Can't create file");
                return 3;
            }
            
            counter++;
            
        }
        
        if (img !=NULL)
            fwrite(buffer, sizeof(uint8_t), 512, img);
    }
    
    free(buffer);
    
    fclose(inFile);
    fclose(img);
    
    return 0;
}