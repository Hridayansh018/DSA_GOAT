#include <iostream>
using namespace std;

// Create a class Node
class Node{
    public:
        // create data
        int data;
        // create "next" pointer that will be used to point at next node
        Node* next;

        // Node constructor for initialization - takes a int val as parameter
        Node(int val){
            // set entered data as val
            data = val;
            // set next as null pointer - that does not point anywhere yet
            next = nullptr;
        }
};


// Create a class LinkedList
class LinkedList{
    // initialize head pointer
    Node* head;
public:
    // call the LinkedList constructor
    LinkedList(){
        // assign head as null ptr - it means that it is not yet defined
        head = nullptr;
    };

    // function to add value at the end
    void insert(int val){
        // create a newNode pointer for new Node
        Node * newNode = new Node(val);
        // if there's no head - initialise the head value and return
        if(!head){
            head = newNode;
            return;
        }
        // create a temp of head for traversal
        Node* temp = head;
        // traverse till temp has any next - till the end
        while (temp->next)
            // go to next temp
            temp = temp->next;
        // at the end - add newNode pointer - this will add the value athe end of the LinkedList
        temp->next = newNode;
    };

    // function to remove any value
    void remove(int val){
        // if there's no head, do nothing just return
        if(!head) return;
        // if head is equal to the value - it has to be deleted
        if(head->data == val){
            // create a pointer to point out the deletion Node - and point it to the head
            Node* toDelete = head;
            // point head to next
            head = head->next;
            // delete the head via pointer created for deletion and return
            delete toDelete;
            return;
        }
        // create a temp pointer and point it to the head
        Node* temp = head;
        // traverse till the value of node is not equal to the value we want to delete
        while(temp->next && temp->next->data != val)
            // point to next node till the above condition is satisfied
            temp = temp->next;
        // till next - remove the value from LinkedList
        if(temp->next){
            // create a pointer for deletion and point it to the next
            Node* toDelete = temp->next;
            // set next to the next of the next
            temp->next = temp->next->next;
            // delete the next and return
            delete toDelete;
        }
    };


    // function to add values in sorted order
    void addSorted(int val){
        // create a temp pointer and point it to the head
        Node*temp = head;
        // create a newNode pointer for adding new Node
        Node* newNode = new Node(val);

        // if there's no head or value is less than head - add the desired value as head
        if(!head || val<head->data){
            // point newNode to the nest
            newNode->next = head;
            // point head to newNode and return
            head = newNode;
            return;
        }

        // traverse throuh the LinkedList till the end or found a value that is just greater than the value we want to add
        while(temp->next && temp->next->data < val){
            // point temp to next
            temp = temp->next;
        }

        // assign next of newNode to the next of temp
        newNode->next = temp->next;
        // and assign next of temp to the newNode
        temp->next = newNode;
    }


    // function to display
    void display(){
        Node*temp = head;
        while(temp){
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    };
        
};



int main(){

    LinkedList lst;
    lst.insert(12);
    lst.insert(22);
    lst.insert(32);
    lst.insert(42);
    lst.display();
    lst.remove(22);
    lst.display();
    lst.addSorted(35);
    lst.display();

    
    return 0;
}