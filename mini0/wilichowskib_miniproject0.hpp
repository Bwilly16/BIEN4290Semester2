/* Author: Ben Wilichowski
 * Date Created: 1/20/2023
 * Purpose: The purpose of this program is to hack time
 * */

#ifndef VARNAME
#define VARNAME

#include <iostream>
#include <unistd.h>
#include <stdio.h>


namespace Hacking{
    class TimeHacking{
        public:
            TimeHacking(std::string objectToHack);
            void setTimeToHack(int seconds);
            int getTimeToHack();
            std::string getObjectToHack();
            void hackTime();
        
        private:
            int time_to_hack = 0;
            std::string objectToHack;
    };
}

#endif
