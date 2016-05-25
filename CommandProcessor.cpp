#include <iostream>
#include "CommandProcessor.h"
using namespace std;

Command_States CommandProcessor:: command_state = Initial;

Menu* CommandProcessor::menus[NR_CMD_STATES];


void CommandProcessor::Process_Commands()
{
    cout << "Process commands starting\n";


    Create_Menus();

    while (command_state != Done)
    {
        const string* cmd = menus[command_state]->Get_Command();

        switch (command_state)
        {
            case Initial:   Process_Initial_Cmd(*cmd);
                break;

            case CyclicLinkedList:    Process_Venue_Selected_Cmd(*cmd);
                break;

            case DoublyLinkedList: Process_Venue_Selected_Cmd(*cmd);

            case Done:  break;      // Can't happen
        }
    }

    cout << "Command_Processor exiting\n";
    // Process command in Initial command state

}
void CommandProcessor::Process_Initial_Cmd(const string& cmd)
{
    if (cmd == "Cyclic Linked List") {
        //Select_Venue();
        command_state = CyclicLinkedList;
    } else if (cmd == "Doubly Linked List") {
        command_state = DoublyLinkedList;
    } else {
        cout << "Quit command\n";
        command_state = Done;
    }
}

void CommandProcessor::ProcessCyclicLinkedList(const string &cmd) {
    // Create Cyclic Linked List here
    string input;
    while(getline(cin, input) != "q") {
        double data = stod(input);
        // Create SingleNode object and add it to Cyclic Linked List here
        cout << data << endl;
    }
    cout << "Cyclic Linked List process done. " << endl;
}

void CommandProcessor::Create_Menus()
{
    // Menu for Initial command state
    Menu* menu = new Menu("Which linked list do you want to create?");
    menu->Add_Command("Cyclic Linked List");
    menu->Add_Command("Doubly Linked List");
    menu->Add_Command("Cancel");

    menus[Initial] = menu;

    // Menu for Venue Selected
//    menu = new Menu("Select Venue");
//    menus[CyclicLinkedList] = menu;
//
//    menu = new Menu("Enter command number");
//    menu->Add_Command("Display Venue");
//    menu->Add_Command("Select Show");
//    menu->Add_Command("Change Venue");
//    menu->Add_Command("Quit");
//    menus[DoublyLinkedList] = menu;
}
