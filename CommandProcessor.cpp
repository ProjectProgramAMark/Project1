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

            case CyclicLinkedList: ProcessCyclicLinkedList(*cmd);
                break;

            case DoublyLinkedList: ProcessDoublyLinkedList(*cmd);

            case Done:  break;      // Can't happen
        }
    }

    cout << "Command_Processor exiting\n";
    // Process command in Initial command state

}
void CommandProcessor::Process_Initial_Cmd(const string& cmd)
{
    if (cmd == "Cyclic Linked List") {
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
    CyclicLinkedList cycliclinkedlist;
    if (cmd == "Add Node to Front") {
        double data;
        cout << "Enter value of data in node: " << endl;
        cin >> data;
        cycliclinkedlist.push_front(data);
    }else if (cmd == "Add Node to Back") {
        double data;
        cout << "Enter value of data in node: " << endl;
        cin >> data;
        cycliclinkedlist.push_back(data);
    }else if (cmd == "Delete Node at Front"){
        cycliclinkedlist.pop_front();
    }else if( cmd == "Delete Value") {
        double data;
        cout << "Enter value to be deleted: " << endl;
        cin >> data;
        cycliclinkedlist.erase(data);
    }else if(cmd == "Get Size of List"){
        cycliclinkedlist.getSize();
    }else if(cmd == "Print List"){
        cycliclinkedlist.printList();
    }else if(cmd == "Delete List") {
        cycliclinkedlist.~CyclicLinkedList();
    }else if(cmd == "Exit"){
                                                                                                                                                                                                                                                                  "else if(cmd == "Exit"){
        menus[Initial] = menu;
    }
    else{
        cout << "Error" << endl;
        return 0;
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
    menu->Add_Command("Add Node to Back")
    menu->Add_Command("Delete Node at Front");
    menu->Add_Command("Delete Value");
    menu->Add_Command("Get Size of List");
    menu->Add_Command("Print List");
    menu->Add_Command("Delete List");
    menu->Add_Command("Exit");
    menus[CyclicLinkedList] = menu;

    //Menu for Doubly Linked List
    menu = new Menu("Enter command number:\n");
    menu->Add_Command("Add Node to Front");
    menu->Add_Command("Add Node to Back")
    menu->Add_Command("Delete Node at Front");
    menu->Add_Command("Delete Value");
    menu->Add_Command("Get Size of List");
    menu->Add_Command("Print List");
    menu->Add_Command("Delete List");
    menu->Add_Command("Exit");
    menus[DoublyLinkedList] = menu;
}
