/*#pragma once
#include <iostream>
#include

class CommandProcessor {
private:
    TiXmlNode* venue_file_node;
public:
    CommandProcessor(TiXmlNode* venue_file_node);
    void firstLevel(TiXmlNode* venue_file_node, Venue** venues);
    void secondLevel(Venue** venues, int numOfVenues);
    void venueOptions(Venue** venues, int venueNumber);
    int quit();
};
*/

#pragma once
#include <string>
#include "Menu.h"
#include "CyclicLinkedList.h"
enum Command_States { Initial, CLinkedList, DoublyLinkedList,  Done };
using namespace std;

class CommandProcessor
{
public:
    static void Process_Commands();

private:
    static const int NR_CMD_STATES = (int)Done + 1;
    static Command_States command_state;
    static Menu* menus[NR_CMD_STATES];

    static void Create_Menus();
    static void Process_Initial_Cmd(const string& cmd);
    //static void Process_Venue_Selected_Cmd(const string& cmd);
    static void ProcessCyclicLinkedList(const string& cmd);
    static void ProcessDoublyLinkedList(const string& cmd);


    CommandProcessor(void) {};
};
