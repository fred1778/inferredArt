#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void weightings(double *rgb, FILE* output);

int main(){

    FILE *hexcolours = fopen("out.txt", "rt");
    char hex[6];
    hex[0] = '\0';
    int line_count = 0;

    FILE *inst;
    inst = fopen("instructions.txt", "w");


    while (fgets(hex, 7, hexcolours) != NULL){
        if(strlen(hex) == 6){
        printf("LINE %i  HEX VAL: %s\n", line_count, hex);
        char colourBit[3];
        colourBit[0] = '\0';
        int cb_index = 0;
        double rgbVals[3];
        int rgb_index = 0;

        for (int i = 0; i < 7; i++){
           colourBit[cb_index] = hex[i];
           cb_index++;
           if (i % 2 != 0 && i > 0)
           {
               char *end;
               colourBit[2] = '\0';

               long int num = strtol((char *)&colourBit, &end, 16);
               rgbVals[rgb_index] = (double)num;
               rgb_index++;
               colourBit[0] = '\0';
               cb_index = 0;
           }
        }
        line_count++;

        weightings(rgbVals, inst);

        }


        hex[0] = '\0';
    }

    fclose(hexcolours);
    fclose(inst);

    return 0;
}

void weightings(double* rgb, FILE* output){

    for (int i = 0; i < 3; i++)
    {
       if(rgb[i] != 0){
          char ratioStr[100];
        double value = rgb[i] / 255.0;
        sprintf(ratioStr, "%.3f", value);
        fprintf(output, (char *)ratioStr);
        fprintf(output, "/");

       } else {
           fprintf(output, "0 /");
       }
    }


    fprintf(output, "\n\n");

}



