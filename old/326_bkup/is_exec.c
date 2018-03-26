#include "header.h"

char *is_exec(char **path, char *name)
{
        char *str;
        int ret_stat;

        while (*path)
        {
                str = append(*path, name);
                if (access(name, F_OK) != -1)
                        return(name);
                if (access(str, F_OK) != -1)
                        return (str);
                else
                        path++;
        }
        return ("File doesn't exist or it hit null");
}
