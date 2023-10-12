#ifndef MAINMENU_H
#define MAINMENU_H

// The MainMenu (.h & .cpp) file contains the function declarations used to 
// Present a main menu which allows a user to view, add, and remove employees.
// The list of employees is implemented with a linked list, and most of the
// processing functions get passed a pointer to the first element of the 
// list (Employee* pHead).

#include <string>

// A command set of operations that can be used with our Menu.
enum class Command{ viewEmployees, addEmployee, removeEmployee, exit, invalid };

// a struct to represent an Employee (each instance forms a node of a linked list
// used to store employees.
struct Employee {
	int id;
	std::string name;
	Employee* pNext;
};

// A struct used to return multiple return values from the getNodeInfo() function.
// getNodeInfo() traverses the list looking for a target node (and its parent node).
// NodeInfo contains info needed to facilitate node insertion & deletion in the list.
struct NodeInfo {
	Employee* pNode;	// a pointer to the "target" node.
	Employee* pParent;	// a pointer to the node prior to pNode (nullptr if node is at the front)
};

// Clear any characters from the (keyboard) input buffer
void ignoreLine();

// Read and return an int from the console. Keep trying until an int is returned.
int getIntFromUser();

// display the main menu
void displayMainMenu();

// fetch and return a menu command from user input
Command getMenuCommand();

// Given a Command, this will determine the appropriate function to call.
// - param 1: (given) a pointer to the front of the list of employees (passed by reference)
// - param 2: a Command (enum) representing the action to be taken.
void handleMenuInput(Employee*& pHead, Command command);


// =============================================================================
// Implement the functions below by following the given directions:	
// As you implement these, you will have to add forward declarations for
// each one in MainMenu.h
// The function name has been given.
// In some cases, the first parameter has been given.
// =============================================================================

// Output a list of all employees to the console.
// If the list is empty (nullptr), print "empty list.\n" 
// If it isn't empty, print each employee's id and name to the console:
//    eg: [id: 5, name: Mary]\n
// Create a pointer to traverse the list, point it at the front of the list,
// process the node (output as shown above), and advance the pointer through the
// list.  Repeat until you process the last node.
// -param 1: (given) a pointer to an Employee struct (representing the front 
//			 of the list of employees.
// return: nothing
// TODO ------------------------------------------------------------------------
void viewEmployees(Employee* pHead);


// Create a new employee struct on the heap.
// Use a static local variable to generate unique employee id's with (initialize
// it and then increment it every time this function is called). 
// Dynamically allocate memory for an employee struct from the heap.  
//		 Initialize it with:
//				-the unique id,
//				-the name passed in as a paramter,
//				-nullptr.
// - param 1: a string - the employee's name.
// - return: a pointer to the dynamically allocated Employee struct 
// TODO ------------------------------------------------------------------------
//createEmployee();


// Create a new employee node, then add it to the list
// Use createEmployee() for node creation.
// Insert the new employee node at the front of the linked list
// It will help to draw this out!
// - param 1: (given) a pointer to the front of the list of employees (passed
//            by reference)
// - param 2: a string - the employee's name.
// - return: nothing
// TODO ------------------------------------------------------------------------
//addNewEmployee(Employee*& pHead);


// Search through the list for a node with the given id.  
// Tip: Use a pointer to iterate through the linked list and another
//      pointer to track the parent. 
// - param 1: (given) a pointer to an Employee struct (representing the front  
//			  of the list of employees
// - param 2: an int (the id of the employee we're searching for). 
// - return: a NodeInfo struct. It contains a pointer to the node that matches  
//			 the id passed in and a pointer to that node's parent. 
//           If node not found, pointers inside NodeInfo should both be nullptr.
//           If node is first in the list, NodeInfo.pParent should be nullptr.
// TODO ------------------------------------------------------------------------
// getNodeInfo(Employee* pHead);


// Removes an employee node with the given id from the list.
// Try to find a node with the given id (use getNodeInfo()). 
//	1) If node not found, output "Error: employee id:# not found\n". 
//  2) If node found, but parent is nullptr, the node is first in the list:
//			-Set the pHead to point to the second node in the list.
//			-Output "removed id:# \n" to the console
//			-Deallocate the node (return it to the heap)
//  3) otherwise the node was found and a parent exists
//			-Set the parent's next pointer to the next pointer of the node we want to delete
//			-Output a "removed id: #n" message to the console
//			-Deallocate the node (return it to the heap).
// - param 1: (given) a pointer to the front of the list of employees (passed by reference)
// - param 2: an int (the id of the employee we're searching for). 
// - return: nothing
// TODO ------------------------------------------------------------------------
//removeEmployee(Employee*& pHead);




#endif
