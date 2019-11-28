#include <stdlib.h>
#include <ft_string.h>


static void free_all(char **ws, size_t cw)
{
    size_t  i;

    i = 0;
    while (i < cw)
    {
        free(ws[i]);
        i++;
    }
    free(ws);
}

static size_t count_words(const char *s, int sep)
{
    size_t  count;

    count = 0;
    while (*s && *s == sep)
        s++;
    while (*s)
    {
        count++;
        while (*s && *s != sep)
            s++;
        while (*s && *s == sep)
            s++;
    }
    return (count);
}

char    *get_word(const char *s, int sep, size_t *len_skip)
{
    const char    *word_start;
    const char    *word_end;

    word_start = s;
    while (*word_start && *word_start == sep)
        word_start++;
    if (*word_start == '\0')
        return (NULL);
    word_end = word_start;
    while (*word_end && *word_end != sep)
        word_end++;
    *len_skip = word_end - s;
    return (strndup(word_start, word_end - word_start));
}


char    **ft_strsplit(const char *s, int sep)
{
    size_t  cw;
    char    **ws;
    size_t  i;
    size_t  skip_len;

    while (*s && *s == sep)
        s++;
    cw = count_words(s, sep);
    if ((ws = (char **)malloc(sizeof(char**) * (cw + 1))) == NULL)
        return (NULL);
    i = 0;
    while (i < cw)
    {
        if ((ws[i] = get_word(s, sep, &skip_len)) == NULL)
        {
            free_all(ws, i);
            return (NULL);
        }
        s += skip_len;
        i++;
    }
    ws[i] = NULL;
    return (ws);
}
