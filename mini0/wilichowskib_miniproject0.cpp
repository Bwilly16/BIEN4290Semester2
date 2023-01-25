/* Author: Ben Wilichowski
 * Date Created: 1/20/2023
 * Purpose: The purpose of this program is to hack time
 * */
#include "wilichowskib_miniproject0.hpp"

Hacking::TimeHacking::TimeHacking(std::string hack1){
   this->objectToHack = hack1;
}

 void Hacking::TimeHacking::setTimeToHack(int seconds){
   this->time_to_hack = seconds;
 }

int Hacking::TimeHacking::getTimeToHack(){
   return (this->time_to_hack);
 }

std::string Hacking::TimeHacking::getObjectToHack(){
   return (this->objectToHack);
}

 void Hacking::TimeHacking::hackTime(){
      std::cout << "Time is being hacked..." << std::endl;
      sleep(this->time_to_hack);
      std::cout << "Time was hacked!" << std::endl;

 }

 int main(){
    std::string hackstring;
    int timetemp;

    std::cout << "What object do you want to hack?" << std::endl;
    std::cin >> hackstring;
   // std::cout << "You want to hack: \n" << hackstring << std::endl;

    std::cout << "\nHow much time?" << std::endl;
    std::cin >> timetemp;
   //  scanf("%d", &timetemp);
    //std::cout << "You want to hack for " << timetemp << " seconds.\n"<< std::endl;

   // std::cout << "\n Object: " << hackstring << "\n Time: " << timetemp << std::endl;

   Hacking::TimeHacking HackingTime(hackstring);
   HackingTime.setTimeToHack(timetemp);
   std::cout << "The time entered to hack was " << HackingTime.getTimeToHack() << std::endl;
   std::cout << "The thing you want to hack was " << HackingTime.getObjectToHack() << std::endl;
   HackingTime.hackTime();
   
   return 0;

 }