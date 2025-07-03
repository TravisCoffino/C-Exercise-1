#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 32

int main() {
    char str[MAX];
    char ch;
    float dec = 1;
    FILE *inp_f;
    FILE *out_p;
    float sum = 0;
    float avg = 0;
    int n = 0;

    if ((inp_f = fopen("input.txt.txt", "r")) == NULL) {
        printf("Error opening input file");
        exit(1);
    }

    if ((out_p = fopen("output.txt.txt", "w")) == NULL) {
        printf("Error writing to output file");
        exit(1);
    }

    while ((ch = fgetc(inp_f)) != EOF) {
        int i = 0;
        int sign = 1;
        int e_sign = 1;
        int exponent = 0;

        if ((ch >= '0' && ch <= '9') || ch == '.' || ch == '-' || ch == '+') {
            str[i++] = ch;
            while (((ch = fgetc(inp_f)) != EOF) && ((ch >= '0' && ch <= '9') || ch == '.')) {
                str[i++] = ch;
            }
            str[i] = '\0';

            // Parse the decimal number
            float dec_num = strtof(str, NULL);

            // Check if there's an exponent
            if (ch == 'E' || ch == 'e') {
                ch = fgetc(inp_f);
                if (ch == '+') {
                    ch = fgetc(inp_f);
                } else if (ch == '-') {
                    e_sign = -1;
                    ch = fgetc(inp_f);
                }
                i = 0;
                while (ch >= '0' && ch <= '9') {
                    str[i++] = ch;
                    ch = fgetc(inp_f);
                }
                str[i] = '\0';
                exponent = atoi(str);
            }

            // Adjust the decimal number based on the exponent
            dec_num *= pow(10, e_sign * exponent);

            sum += dec_num;
            n++;

            // Write the decimal number to the output file
            fprintf(out_p, "%f\n", dec_num);
        }
    }

    if (n > 0) {
        avg = sum / n;
        fprintf(out_p, "Sum: %f\n", sum);
        fprintf(out_p, "Average: %f\n", avg);
    } else {
        fprintf(out_p, "No valid numbers found in the input file.\n");
    }

    fclose(inp_f);
    fclose(out_p);

    return 0;
}