#include <iostream>
#include "CommandProcessor.h"
#include "CyclicLinkedList.h"
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

            case CLinkedList: ProcessCyclicLinkedList(*cmd);
                break;

            //case DoublyLinkedList: ProcessDoublyLinkedList(*cmd);
//                break;

            case Done:  break;      // Can't happen
        }
    }

    cout << "Command_Processor exiting\n";
    // Process command in Initial command state

}
void CommandProcessor::Process_Initial_Cmd(const string& cmd)
{
    if (cmd == "Cyclic Linked List") {
        command_state = CLinkedList;
    } //else if (cmd == "Doubly Linked List") {
        //command_state = DoublyLinkedList;
   // }
     else {
        cout << "Quit command\n";
        command_state = Done;
    }
}

void CommandProcessor::ProcessCyclicLinkedList(const string &cmd) {
    // Create Cyclic Linked List here
    CyclicLinkedList<double> * linkedlist = new CyclicLinkedList<double>();
    if (cmd == "Add Node to Front") {
        string input;
        double value;
        cout << "Enter value of data in node: " << endl;
        getline(cin,input);
        stringstream(input) >> value;
        linkedlist->push_front(value);
        linkedlist->printList();
    }else if (cmd == "Add Node to Back") {
        string input;
        double value;
        cout << "Enter value of data in node: " << endl;
        getline(cin,input);
        stringstream(input) >> value;
        linkedlist->push_back(value);
    }else if (cmd == "Delete Node at Front"){
        linkedlist->pop_front();
    }else if( cmd == "Delete Value") {
        string input;
        double value;
        cout << "Enter value to be deleted: " << endl;
        getline(cin,input);
        stringstream(input) >> value;
        linkedlist->erase(value);
    }else if(cmd == "Get Size of List") {
        linkedlist->getSize();
    }else if(cmd == "Is List Empty") {
        linkedlist->empty();
    }else if(cmd == "Get Front Node") {
        linkedlist->front();
    }else if(cmd == "Get Back Node"){
        linkedlist->back();
    }else if(cmd == "Get Head Pointer ;)"){
        linkedlist->getHead();
    }else if(cmd == "Get Tail Pointer"){
        linkedlist->getTail();
    }else if(cmd == "Get Count"){
        string input;
        double value;
        cout << "Insert value to count: ";
        getline(cin,input);
        stringstream(input) >> value;
        linkedlist->getCount(value);
    }else if(cmd == "Print List"){
        linkedlist->printList();
    }else if(cmd == "Delete List"){
        linkedlist->~CyclicLinkedList();
    }else if(cmd == "Exit"){
        exit(0);
    }else{
        cout << "Error" << endl;
    }
}

void CommandProcessor::Create_Menus()
{
    // Menu for Initial command state
    Menu* menu = new Menu("Which linked list do you want to create?");
    menu->Add_Command("Cyclic Linked List");
    menu->Add_Command("Doubly Linked List");
    menu->Add_Command("Cancel");

    menus[Initial] = menu;

    //Menu for  Cyclic Linked List
    menu = new Menu("Enter command number:\n");
    menu->Add_Command("Add Node to Front");
    menu->Add_Command("Add Node to Back");
    menu->Add_Command("Delete Node at Front");
    menu->Add_Command("Delete Value");
    menu->Add_Command("Is List Empty");
    menu->Add_Command("Get Front Node");
    menu->Add_Command("Get Back Node");
    menu->Add_Command("Get Head Pointer ;)");
    menu->Add_Command("Get Tail Pointer");
    menu->Add_Command("Get Size of List");
     menu->Add_Command("Get Count");
    menu->Add_Command("Print List");
    menu->Add_Command("Delete List");
    menu->Add_Command("Exit");
    menus[CLinkedList] = menu;

    //Menu for Doubly Linked List
    menu = new Menu("Enter command number:\n");
    menu->Add_Command("Add Node to Front");
    menu->Add_Command("Add Node to Back");
    menu->Add_Command("Delete Node at Front");
    menu->Add_Command("Delete Value");
    menu->Add_Command("Is List Empty");
    menu->Add_Command("Get Front Node");
    menu->Add_Command("Get Back Node");
    menu->Add_Command("Get Head Pointer ;)");
    menu->Add_Command("Get Tail Pointer");
    menu->Add_Command("Get Size of List");
    menu->Add_Command("Get Count");
    menu->Add_Command("Print List");
    menu->Add_Command("Delete List");
    menu->Add_Command("Exit");
    menus[DoublyLinkedList] = menu;
}
