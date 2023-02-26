#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char *prompt(char *line, int size) {
    char *retval;

    do {
        printf(">> ");
        retval = fgets(line, size, stdin);
    } while (retval && *line == '\n'); // 如果输入回车，就继续等待输入
    line[strlen(line) - 1] = '\0';

    return retval;
}

int main(int argCount, char *grav[]){
    int size = 4096, max = size >> 1, argc;
    char buffer[size];
    char *line = buffer;
    char **ap, *args[max];

    while (prompt(line, size)) {
        argc = 0;

        /* Return the next DELIM-delimited token from *STRINGP,
           terminating it with a '\0', and update *STRINGP to point past it.  */
        for (ap = args; (*ap = strsep(&line, " \t")) != NULL;) {
            if (**ap != '\0') {
                if (argc >= max) break;
                if (strcasecmp(*ap,"quit") == 0 || strcasecmp(*ap,"exit") == 0)
                    exit(0);
                ap++;
                argc++;
            }
            printf("times one\n");
        }
        int i;
        printf("参数个数:%d\n", argc);
        for (i=0; i< argc; i++){
            printf("第%d个参数是:%s\n", i, args[i]);
        }
        line = buffer;
    }
    exit(0);
}
