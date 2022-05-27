#include "opend.h"

// Figure 17.24 The cli_args function
// It verifies that the client sent the right number of arguments and stores the pathname and
// open mode in global variables.

/*
 * This function is called by buf_args(), which is called by
 * handle_request().  buf_args() has broken up the client's
 * buffer into an argv[]-style array, which we now process.
 */
int cli_args(int argc, char **argv)
{
    if (argc != 3 || strcmp(argv[0], CL_OPEN) != 0)
    {
        strcpy(errmsg, "usage: <pathname> <oflag>\n");
        return (-1);
    }

    pathname = argv[1];        /* save ptr to pathname to open */
    oflag = atoi(argv[2]);

    return (0);
}
