#include <stdio.h>
#include <string.h> 

int main(int argc, char *argv[]){    
    char *input_filename = argv[1]; // name of input file
    char *output_filename = argv[2]; // name of output file
    // YOUR CODE HERE

    FILE *infile, *outfile;
    int num, factor, num_factor;
    infile = fopen(input_filename, "r");
    if (infile == NULL){
        printf("error: cannot open file\n");
        return 0;
    }

    outfile = fopen(output_filename, "w");
    
    while(fscanf(infile, "%d", &num) != EOF){
        fprintf(outfile, "%d = ", num);
        if (num <= 0){
            fprintf(outfile, "%d", num);
            return 0;
        }
        factor = 2;
        num_factor = 0;
        while(num != 1){
            if (num % factor == 0){
                if (num_factor == 0){
                    fprintf(outfile, "%d", factor);
                }
                else {
                    fprintf(outfile, " * ");
                    fprintf(outfile, "%d", factor);
                }
                num /= factor;
                num_factor++;
            } 
            if (num % factor != 0){
                factor++;
            }
        }
        fprintf(outfile, "\n");
    }
    return 0;
}
