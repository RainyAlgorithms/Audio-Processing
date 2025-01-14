#include <stdio.h>
#include <stdlib.h>
#define HEADER_SIZE 44

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <sourcewav> <destwav>\n", argv[0]);
        return 1;
    }

    FILE *sourceFile = fopen(argv[1], "rb");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return 1;
    }

    FILE *destFile = fopen(argv[2], "wb");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile);
        return 1;
    }

    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, sourceFile);
    fwrite(header, sizeof(unsigned char), HEADER_SIZE, destFile);

    short left, right;
    while (fread(&left, sizeof(short), 1, sourceFile) &&
           fread(&right, sizeof(short), 1, sourceFile)) {
        short combined = (left - right) / 2;
        fwrite(&combined, sizeof(short), 1, destFile);
        fwrite(&combined, sizeof(short), 1, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
