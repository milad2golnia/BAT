#ifndef __DOTTOPNGCONVERTER__INCLUDED__
#define __DOTTOPNGCONVERTER__INCLUDED__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


/*
*   Get the dot file name and converts it to a png image, the image will be saved by the
*       given name.
*   @param dotFileName  -   The name of dot file.
*   @param imageFileName    -   The name of output image, should have png extension.
*/
void convertDotToPng(const char* const dotFileName, const char* const imageFileName);


#endif