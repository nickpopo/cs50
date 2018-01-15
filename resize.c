#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if(argc != 4)
    {
        fprintf(stderr, "Usage: ./resize factor infile outfile\n");
        return 1;
    }
    
    int n = atoi(argv[1]);
    
    if(n < 0 || n > 100)
    {
       fprintf(stderr, "Usage: n must be a positive and less or equal 100\n");
       return 2;
    }
    
    if (n==0)
    {
        n = 1;
    }
    
    FILE *inFile = fopen(argv[2], "r");
   
    if (inFile == NULL)
    {
        fprintf(stderr, "Can not open input file.\n");
        return 3;
    }
    
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inFile);
    
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inFile);
    
    if(bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || bi.biBitCount != 24 || bi.biCompression != 0)
    {   
        fclose(inFile);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    FILE *outFile = fopen(argv[3], "w");
    
    if (outFile == NULL)
    {   
        fprintf(stderr, "Can't open the output file for writing\n");
        return 5;
    }
    
    // remember inFile's biWidth and biHeight
    int  biWidthIn = bi.biWidth;
    int biHeightIn = abs(bi.biHeight);
    
    // inFile's padding for scanlines
    int paddingIn =  (4 - (biWidthIn * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // change needed info for outFile's headers
    bi.biWidth *= n;
    bi.biHeight *= n;
    
    // outFile's padding for scanlines
    int paddingOut =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // biWidth, biHeight, biSize, bfSize
    // biWidth *= n, biHeight *=n; biSize * = n2; bfSize = biSize + BITMAPFILEHEADER + BITMAPINFOHEADER;
    bi.biSizeImage = abs(bi.biWidth * bi.biHeight * 3 + paddingOut * bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outFile);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outFile);
    
    
    // iterate over inFile's scanline
    for (int i=0; i < biHeightIn; i++)
    {   
        int t = 0;
        // repeat n times
        do {
            
            // iterate scanline pixels
            for (int j = 0; j < biWidthIn; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
                
                fread(&triple, sizeof(RGBTRIPLE), 1, inFile);
                
                int times = 0;
                
                do{
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outFile);
                    times++;
                }while(times<n);
                
            }
            
            // then add it back (to demonstrate how)
            for (int k = 0; k < paddingOut; k++)
            {
                fputc(0x00, outFile);
            }
            
            t++;
            
            if(n != t)
            {
                // need restart position of pointer
                fseek(inFile, -(sizeof(RGBTRIPLE)*biWidthIn), SEEK_CUR);
            }
        }
        while(t < n);
        
        // skip over padding, if any
        fseek(inFile, paddingIn, SEEK_CUR);
        
    }
    
    fclose(inFile);
    fclose(outFile);
    
    return 0;
}

