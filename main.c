/*****************************************************************
 Basic ceasar cipher that can encrypt and decrypt a file given a
 key. Basic checking for overwrites and memory errors.
 
 @author Joshua Crum
 @version 10/03/17
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include "file_utils.h"



int main(int argc, char** argv) {
    
    
    if (argv[1] == NULL) {
        fprintf(stderr, "Please enter an input file.");
    } else if (argv[2] == NULL) {
        fprintf(stderr, "Please enter a key.");
    } else if (argv[3] == NULL) {
        fprintf(stderr, "Please enter an output file.");
    } else if (argv[4] == NULL) {
        fprintf(stderr, "Enter a '1' for encryption, or a '2'\
                for decryption.");
    } else if (argv[5] != NULL) {
        fprintf(stderr, "Enter an input file, a key, an output file,\
                and either a '1' for encryption or a '2' for\
                decryption.");
    }
    
    /** Char pointer to the user key input. */
    char* key = argv[2];
    
    /** Char pointer to pass to file_read. */
    char* file_buffer = (char*)malloc(sizeof(char));
    if (file_buffer == NULL) {
        fprintf( stderr, "\nMemory allocation failed.\n" );
        return -1;
    }
    
    /** Number of elements in the file. */
    int size = read_file(argv[1], &file_buffer);
    
    //Encrypt or decrypt
    if (strcmp(argv[4], "2")) {
        fileEncrypt(file_buffer, key, size);
        
    } else if (strcmp(argv[4], "1")) {
        fileDecrypt(file_buffer, key, size );
    }
    
    write_file(argv[3], file_buffer, size);
    
    free(file_buffer);
    
    return 0;
}
