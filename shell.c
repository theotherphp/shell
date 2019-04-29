#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
    while (1) {

        char *line;
        size_t len;
        printf("? ");
        if (-1 == getline(&line, &len, stdin))
            return 0;
        else if (!strcmp(line, "\n"))
            continue;
        else {
            char *l = line;
            while (*l != '\n') l++;
            *l = '\0';
        }
        
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
