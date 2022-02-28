#include "../headers/dotToPngConverter.h"


void convertDotToPng(const char* const dotFileName, const char* const imageFileName){
    /*
    *   Currently, we use system() function to do the task but it's not a correct way,
    *   Anyway it satisfy our needs at this moment.
    */
    char* command = calloc(strlen("dot  -Tpng -o ") + strlen(dotFileName) + 
                            strlen(imageFileName) + 1, 1);
    sprintf(command, "dot %s -Tpng -o %s", dotFileName, imageFileName);
    errno = 0;
    int result = system(command);
    if(result == -1){
        perror("Error! Unable to convert dot file to png file,"
                "Please make sure you have 'dot' program installed on your system");
        return;
    }
    return;
}
