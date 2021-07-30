
#include "ft_printf.h"
/*
* Safe join makes sure no memory leaks appear with using strjoin
* frees str1 and str2 after join, i.e. the input get freed. 
* Returns <rstr>
*/
char    *ft_strfjoin(char *str1, char *str2)
{
    char    *rstr;

    if (!str1 && str2)
        rstr = ft_strjoin("", str2);
    else if (str1 && !str2)
        rstr = ft_strjoin((const char *)str1, "");
    else if (str1 && str2)
        rstr = ft_strjoin((const char *)str1, str2);
    if (str1)
        free(str1);
    if (str2)
        free(str2);
    return (rstr);
}