#include"readfile.h"
//read files functions
#include<QString>
/*
Lectura d'un fitxer OBJ

Fragments de codi de obj_2_ply.c (C) Greg Turk

-----------------------------------------------------------------------
Copyright (c) 1998 Georgia Institute of Technology.  All rights reserved.

Permission to use, copy, modify and distribute this software and its
documentation for any purpose is hereby granted without fee, provided
that the above copyright notice and this permission notice appear in
all copies of this software and that you do not sell the software.
*/

int ReadFile::max_words = 0;
int ReadFile::num_words = 0;
/* for file reading */
#define BIG_STRING 4096
char ReadFile::str[BIG_STRING];
char ReadFile::str_orig[BIG_STRING];
char**ReadFile::words;

void ReadFile::get_indices ( char *word, int *vindex, int *tindex, int *nindex )

/******************************************************************************

GET_INDICES breaks up a word that may have slash-separated numbers into one or more
numbers.

Entry:
word - word to break up

Exit:
vindex - first number (vertex index)
tindex - second number (texture index)
nindex - third number (normal vector index)
******************************************************************************/
{
    char *null = " ";
    char *ptr;
    char *tp;
    char *np;

    /* by default, the texture and normal pointers are set to the null string */

    tp = null;
    np = null;

    /* replace slashes with null characters and cause tp and np to point */
    /* to character immediately following the first or second slash */

    for (ptr = word; *ptr != '\0'; ptr++) {
        if (*ptr == '/') {
            if (tp == null)
                tp = ptr + 1;
            else
                np = ptr + 1;

            *ptr = '\0';
        }
    }


    QString v(word);
    QString t(tp);
    QString n(tp);

    *vindex = v.toInt();
    *tindex = t.toInt();
    *nindex = n.toInt();
}



char *ReadFile::fetch_line ( FILE *fp )
{
    //int i,j;
    char *ptr;
    char *ptr2;
    char *result;
    //char *comment_ptr;

    /* read in a line */
    result = fgets (ReadFile::str, BIG_STRING, fp);

    /* return NULL if we're at the end-of-file */
    if (result == NULL)
        return ((char *) -1);

    /* convert line-feed and tabs into spaces */
    /* (this guarentees that there will be a space before the */
    /*  null character at the end of the string) */

    ReadFile::str[BIG_STRING-2] = ' ';
    ReadFile::str[BIG_STRING-1] = '\0';

    for (ptr = ReadFile::str; *ptr != '\0'; ptr++) {
        if (*ptr == '\t') {
            *ptr = ' ';
        }
        else if (*ptr == '\n') {
            *ptr = ' ';
            break;
        }
    }

    /* copy the line */
    for (ptr = ReadFile::str, ptr2 = ReadFile::str_orig; *ptr != '\0'; ptr++, ptr2++)
        *ptr2 = *ptr;
    *ptr2 = '\0';

    /* look to see if this is a comment line (first non-space is '#') */

    for (ptr = ReadFile::str; *ptr != '\0'; ptr++) {
        if (*ptr == '#') {
            ptr++;
            while (*ptr == ' ')
                ptr++;
            return (ptr);
        }
        else if (*ptr != ' ') {
            break;
        }
    }

    /* if we get here, we've got a non-comment line */

    /* strip off trailing comments */

    while (*ptr != '\0') {
        if (*ptr == '#') {
            *ptr++ = ' ';
            *ptr = '\0';
            break;
        }
        ptr++;
    }

    return (NULL);
}

int ReadFile::fetch_words ()
{
    char *ptr;

    /* allocate room for words if necessary */
    if (max_words == 0) {
        max_words = 20;
        words = (char **) malloc (sizeof (char *) * max_words);
    }

    /* find the words in the line */

    ptr = ReadFile::str;
    num_words = 0;

    while (*ptr != '\0') {
        /* jump over leading spaces */
        while (*ptr == ' ')
            ptr++;

        /* break if we reach the end */
        if (*ptr == '\0')
            break;

        /* allocate more room for words if necessary */
        if (num_words >= max_words) {
            max_words += 10;
            words = (char **) realloc (words, sizeof (char *) * max_words);
        }

        /* save pointer to beginning of word */
        words[num_words++] = ptr;

        /* jump over non-spaces */
        while (*ptr != ' ')
            ptr++;

        /* place a null character here to mark the end of the word */
        *ptr++ = '\0';
    }

    /* return the number of words */
    return (num_words);
}

std::string ReadFile::getPath(const std::string& filename)
{
    int i=filename.length()-1;
    bool found = false;
    while (i>=0 && !found)
    {
        if (filename[i]=='/' || filename[i]=='\\') found=true;
        else --i;
    }
    return filename.substr(0, i+1);
}
