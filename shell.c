#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
    while (1) {

        size_t len = 128;
        char *line = malloc(len);
        printf("? ");
        int chars;
        if (-1 == (chars = getline(&line, &len, stdin)))
            return 0;
        line[chars-1] = '\0';
        
        char *a[len]; 
        int n = 0;
        char *t = a[n++] = strtok(line, " ");
        while (t != NULL) {
            t = strtok(NULL, " ");
            a[n++] = t ? t : NULL; 
        }
        
        fork() == 0 ? execvp(a[0], a) : wait(NULL);
        free(line);
    }

    return 0;
}
