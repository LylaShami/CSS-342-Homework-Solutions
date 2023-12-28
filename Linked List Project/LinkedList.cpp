#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

template <class Item>
class LinkedList
{
  template <class U>
  // ostream to output
  friend ostream &operator<<(ostream &stream, const LinkedList<U> &secondList);

public:
  // public constructors
  // emptpy constructor
  LinkedList();
  // parameterized constructor
  LinkedList(const LinkedList &mainList);
  // destructor for Linkedlist class to handle allocation on the heap
  virtual ~LinkedList();

  // operators
  LinkedList operator+(const LinkedList &secondList) const;
  LinkedList &operator+=(const LinkedList &secondList);
  bool operator==(const LinkedList &secondList) const;
  bool operator!=(const LinkedList &secondList) const;
  LinkedList &operator=(const LinkedList &secondList);
  // actions
  bool BuildList(string fileName);
  bool Insert(Item *obj);
  bool Remove(Item target, Item &result);
  bool Peek(Item target, Item &result) const;
  void DeleteList();
  bool isEmpty() const;
  bool Merge(LinkedList &list1);

private:
  struct Node // creating new node
  {
    Item *data = nullptr;
    Node *next = nullptr;
  };
  Node *frontPointer;
};
#endif

template <class Item>
LinkedList<Item>::LinkedList()
{
  frontPointer = nullptr;
}

template <class Item>
LinkedList<Item>::LinkedList(const LinkedList<Item> &secondList)
{
  frontPointer = nullptr;
  *this = secondList;
}

template <class Item>
LinkedList<Item>::~LinkedList()
{
  DeleteList();
}

template <class Item>
LinkedList<Item> LinkedList<Item>::operator+(const LinkedList<Item> &secondList) const
{
  LinkedList<Item> tempList; // creating temporary list
  tempList = *this;
  tempList += secondList;
  return tempList;
}

template <class Item>
LinkedList<Item> &LinkedList<Item>::operator+=(const LinkedList<Item> &secondList)
{
  if (secondList.frontPointer == nullptr) // return if nothing in list
  {
    return *this;
  }
  if (frontPointer == nullptr)
  {
    *this = secondList;
    return *this;
  }
  Node *currentNode = secondList.frontPointer; // Start from the front of the second list
  while (currentNode != nullptr)               // Iterate through the second list
  {
    Insert(currentNode->data);       // Insert the data into the current list
    currentNode = currentNode->next; // Move to the next node in the second list
  }
  return *this;
}

template <class Item>
bool LinkedList<Item>::operator==(const LinkedList<Item> &secondList) const
{

  Node *currentNode1, *currentNode2;      // Create two nodes for each list
  currentNode1 = frontPointer;            // Initialize the first node to the current list's first pointer
  currentNode2 = secondList.frontPointer; // Initialize the second node to the second list's first pointer

  while (currentNode1 != nullptr && currentNode2 != nullptr) // Iterate through both lists
  {
    if (*(currentNode1->data) == *(currentNode2->data)) // Compare data pointed by the nodes
    {
      // Move to the next nodes in both lists
      currentNode1 = currentNode1->next;
      currentNode2 = currentNode2->next;
    }
    else
    {
      return false; // If any data elements are different, return false
    }
  }

  // Return true if both lists have been completely traversed and all data elements were equal
  return true;
}

template <class Item>
bool LinkedList<Item>::operator!=(const LinkedList<Item> &secondList) const
{
  return !(*this == secondList); // return true if its not equal to second list
}

template <class Item>
LinkedList<Item> &LinkedList<Item>::operator=(const LinkedList<Item> &secondList)
{
  if (this == &secondList)
  {
    return *this;
  }
  DeleteList(); // freeing memory on the heap from current list

  Node *currentNode = new Node;                    // Create a new node for the current list
  Item *currentItem = new Item;                    // Create a new item for the current node
  *currentItem = *(secondList.frontPointer->data); // Copy the data from the second list's frontPointer
  currentNode->data = currentItem;
  currentNode->next = nullptr;
  frontPointer = currentNode; // Set the current list's frontPointer

  Node *trackingNode, *sourceNode;
  trackingNode = frontPointer;
  sourceNode = secondList.frontPointer->next;

  while (sourceNode != nullptr) // Iterate through the second list
  {
    currentNode = new Node; // Create a new node for the current list
    currentItem = new Item; // Create a new item for the current node

    *currentItem = *(sourceNode->data); // Copy the data from the second list's node
    currentNode->data = currentItem;
    currentNode->next = nullptr;

    // Link the new node to the current list
    trackingNode->next = currentNode;
    trackingNode = trackingNode->next;
    sourceNode = sourceNode->next;
  }

  return *this; // Return the current list
}

template <class Item>
bool LinkedList<Item>::BuildList(string fileName)
{
  ifstream inFile;
  inFile.open(fileName);
  if (!inFile)
  {
    // Check if the file could not be opened
    cout << "Error: Could not open the file. Please make sure the file name is entered correctly." << endl;
    return false;
  }
  // Declare a variable to hold data read from the file
  Item data;
  // Read items from the file and insert them into the linked list
  while (inFile >> data)
  {
    // Insert the read data into the linked list
    Insert(&data);
  }
  inFile.close();
  return true;
}

template <class ItemType>
bool LinkedList<ItemType>::Insert(ItemType *obj)
{
  if (obj == nullptr)
  {
    return false;
  }
  if (Peek(*obj, *obj)) // if the object is already in the list
  {
    return false;
  }
  Node *newNode = new Node;         // Create a new node to insert
  ItemType *newData = new ItemType; // Create a new data object to insert
  *newData = *obj;
  newNode->data = newData;
  newNode->next = nullptr;

  if (frontPointer == nullptr) // If the list is empty
  {
    frontPointer = newNode;
    return true; // Successfully inserted
  }
  else if (*(newNode->data) < *(frontPointer->data)) // If the new object should be inserted at the front
  {
    newNode->next = frontPointer;
    frontPointer = newNode;
    return true; // Successfully inserted
  }
  else
  {
    Node *prevNode = nullptr;
    Node *currentNode = frontPointer;

    while (currentNode != nullptr && *(newNode->data) > *(currentNode->data))
    {
      prevNode = currentNode;
      currentNode = currentNode->next;
    }
    newNode->next = currentNode;
    prevNode->next = newNode;
  }
  return true; // Successfully inserted
}

template <class Item>
bool LinkedList<Item>::Remove(Item target, Item &result)
{
  if (frontPointer == nullptr) // checking if list is null
  {
    return false;
  }

  if (*frontPointer->data == target) // Check if the target is at the front
  {

    Node *tempNode = frontPointer;
    frontPointer = frontPointer->next;
    result = *tempNode->data;
    delete tempNode->data;
    delete tempNode;
    return true; // Successfully removed
  }

  Node *currentNode = frontPointer;
  while (currentNode->next != nullptr)
  {
    if (*currentNode->next->data == target) // Check if the target is found in the next node
    {
      Node *tempNode = currentNode->next;
      currentNode->next = currentNode->next->next;
      result = *tempNode->data;
      delete tempNode->data;
      delete tempNode;
      return true; // Successfully removed
    }
    currentNode = currentNode->next;
  }

  return false; // Target not found in the list
}

template <class Item>
bool LinkedList<Item>::Peek(Item target, Item &result) const
{
  if (frontPointer == nullptr) // if the list is empty
  {
    return false;
  }
  Node *currentNode = frontPointer; // Create a pointer to traverse the list

  while (currentNode != nullptr) // Traverse through the list
  {
    if (*(currentNode->data) == target) // Check if the current node is the target
    {
      result = *(currentNode->data); // Save the data of the result
      return true;                   // result found
    }
    currentNode = currentNode->next; // Move to the next node
  }

  return false; // Target not found in the list
}

template <class Item>
void LinkedList<Item>::DeleteList()
{
  Node *temp;
  while (frontPointer != nullptr) // iterating through the list
  {
    temp = frontPointer;               // creating variable to front pointer
    frontPointer = frontPointer->next; // moving pointer to next
    delete temp->data;                 // delete data
    delete temp;                       // deleting node
  }
  frontPointer = nullptr; // after clearing list, clear pointer
}

template <class Item>
bool LinkedList<Item>::isEmpty() const
{
  return (frontPointer == nullptr); // return true if list is empty
}

template <class ItemType>
bool LinkedList<ItemType>::Merge(LinkedList<ItemType> &list1)
{
  if (this == &list1 || list1.frontPointer == nullptr) // Check if the lists are the same or if the list1 is empty
  {
    return false; // Cannot merge or nothing to merge
  }
  if (frontPointer == nullptr) // If this list is empty
  {
    frontPointer = list1.frontPointer; // Assign the front pointer of the list1
    list1.frontPointer = nullptr;      // Clear the list1's front pointer
    return true;                       // Merged successfully
  }

  Node *trackingNodeOther;
  trackingNodeOther = list1.frontPointer; // Create a tracking node for the list1

  if ((*frontPointer->data) >= *(trackingNodeOther->data)) // Check if this list's front data is greater than or equal to the list1's front data
  {
    list1.frontPointer = list1.frontPointer->next;         // Move to the next node in the list1
    if (*frontPointer->data == *(trackingNodeOther->data)) // Check if the data of the two front nodes is equal
    {
      // Clean up memory on the heap
      delete (trackingNodeOther->data);
      delete trackingNodeOther;
    }
    else
    {
      trackingNodeOther->next = frontPointer;
      frontPointer = trackingNodeOther;
    }
  }

  Node *trackingNodeThis;
  trackingNodeThis = frontPointer; // Create a tracking node for this list

  while (list1.frontPointer != nullptr) // Iterate through the list1
  {
    if (trackingNodeThis->next != nullptr)
    {
      // If there is a next node in the current lis
      trackingNodeOther = list1.frontPointer;
      if (*(trackingNodeOther->data) < *(trackingNodeThis->next->data))
      {
        // If data in the current node of list1 is less than the next node in the current list
        list1.frontPointer = list1.frontPointer->next; 
        //connect current node of list 1 to next node in current list
        trackingNodeOther->next = trackingNodeThis->next;
        //connect the current node of current list to the new node from list1
        trackingNodeThis->next = trackingNodeOther;
        trackingNodeThis = trackingNodeOther;
        trackingNodeOther = nullptr; //make tracking node null to reset list1
      }
          // If data of list1 is equal to the next in current list
      else if (*(trackingNodeOther->data) == *(trackingNodeThis->next->data))
      {
        //move over to next node in list1
        list1.frontPointer = list1.frontPointer->next; 
        //cleam up memory in heap
        delete trackingNodeOther->data;
        delete trackingNodeOther;
        trackingNodeOther = nullptr;  //make tracking node null to reset list1
      }
      else
      {
        trackingNodeThis = trackingNodeThis->next; //if not move to next node
      }
    }
    else
    {
      //if their are no nodes remaning in current list 
      //connect the nodes left in the list1  to current list
      trackingNodeThis->next = trackingNodeOther;
      list1.frontPointer = nullptr; //reset
      return true;
    }
  }
  return true;
}
template <class U>
ostream &operator<<(ostream &stream, const LinkedList<U> &currentPointerList)
{

  class LinkedList<U>::Node *currentNode = currentPointerList.frontPointer;

  while (currentNode != nullptr)
  {
    stream << *(currentNode->data);  // Output the data pointed to by the current node
    currentNode = currentNode->next; // Move to the next node
  }
  return stream; // Return the output stream
}

#include "Child.h"
// #include "LinkedList.cpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
  Child c1("Angie", "Ham", 7), c2("Pradnya", "Dhala", 8),
      c3("Bill", "Vollmann", 13), c4("Cesar", "Ruiz", 6);
  Child c5("Piqi", "Tangi", 7), c6("Pete", "Rose", 13),
      c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
  Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11;
  LinkedList<Child> class1, class2, soccer, chess;
  int a = 1, b = -1, c = 13;
  class1.Insert(&c1);
  class1.Insert(&c2);
  class1.Insert(&c3);
  class1.Insert(&c4);
  class1.Insert(&c5);
  class1.Insert(&c6);
  class1.Insert(&c5);
  cout << "class1: " << class1 << endl;
  if (class1.Insert(&c1))
  {
    cout << "ERROR::: Duplicate" << endl;
  }
  class2.Insert(&c4);
  class2.Insert(&c5);
  class2.Insert(&c6);
  class2.Insert(&c7);
  class2.Insert(&c10);
  cout << "Class2: " << class2 << endl;
  class1.Merge(class2);
  class2.Merge(class1);
  class1.Merge(class2);
  class1.Merge(class1);
  cout << "class1 and 2 Merged: " << class1 << endl;
  if (!class2.isEmpty())
  {
    cout << "ERROR:: Class2 should be empty empty" << endl;
  }
  class1.Remove(c4, c11);
  class1.Remove(c5, c11);
  class1.Remove(c11, c11);
  if (class1.Remove(c1, c11))
  {
    cout << "Removed from class1, student " << c11 << endl;
  }
  cout << "class1: " << class1 << endl;
  soccer.Insert(&c6);
  soccer.Insert(&c4);
  soccer.Insert(&c9);
  cout << "soccer: " << soccer << endl;
  soccer += class1;
  cout << "soccer += class1 : " << soccer << endl;
  LinkedList<Child> football = soccer;
  if (football == soccer)
  {
    cout << "football: " << football << endl;
  }
  if (
      football.Peek(c6, c11))
  {
    cout << c11 << " is on the football team" << endl;
  }
  soccer.DeleteList();
  if (!soccer.isEmpty())
  {
    cout << "ERROR: soccer should be empty" << endl;
  }
  LinkedList<int> numbers;
  numbers.Insert(&a);
  numbers.Insert(&b);
  numbers.Insert(&c);
  cout << "These are the numbers: " << numbers << endl;
  numbers.DeleteList();
  return 0;
}
