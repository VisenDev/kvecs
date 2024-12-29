/*Sparse File*/
#include <stdio.h>

#ifndef SFILE_NAME
#error "SFILE_NAME must be defined"
#endif

#ifndef SFILE_TYPE
#error "SFILE_TYPE must be defined
#endif

typedef struct {
    FILE dense;


} SFILE_NAME;
