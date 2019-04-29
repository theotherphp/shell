#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
    while (1) {

        size_t len = 128;
        char *line = malloc(len);
        printf("? ");
        int chars = getline(&line, &len, stdin);
        if (-1 == chars)
            return 0;
        else if (!strcmp(line, "\n"))
            continue;
        line[chars-1] = '\0';
        
        char *a[len]; 
        int n = 0;
        char *t = a[n++] = strtok(line, " ");
        while (t != NULL) {
            t = strtok(NULL, " ");
            a[n++] = t ? t : NULL; 
        }

        if (0 == fork()) 
            execvp(a[0], a);
        else
            wait(NULL);
    }

    return 0;
}
