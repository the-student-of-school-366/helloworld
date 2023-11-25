#include <stdio.h>
#include <stdlib.h>

void concatenate_files(const char *file1, const char *file2, const char *output_file) {
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");
    FILE *out = fopen(output_file, "w");

    if (f1 == NULL || f2 == NULL || out == NULL) {
        printf("ERROR\n");
        exit(1);
    }

    char buffer[100];
    while (fgets(buffer, 100, f1) != NULL) {
        fputs(buffer, out);
    }

    while (fgets(buffer, 100, f2) != NULL) {
        fputs(buffer, out);
    }

    fclose(f1);
    fclose(f2);
    fclose(out);
}

int main(int argc, char *argv[]) {
    concatenate_files(argv[1], argv[2], argv[3]);
    printf("Update\n");
    char tmp[128];
    scanf("%s",tmp);
}