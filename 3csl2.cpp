//Program to implement insert,delete and countItems functions in a circular linked list
#include<iostream>    //library header

using namespace std;    //namespace

class Node
{
	public:
		//stores data
		int data;
		
		//pointer to move to next node
		Node *next;
		
		//constructor to initialize next pointer to NULL;
		Node()
		{
			next = NULL;
		}
	
};

class CLL
{
	public:
		//head pointer to point to first node
		Node *head;
		//tail pointer to point to node just before head
		Node *tail;
		
		//constructor to initialize head to itself
		CLL()
		{
			head = NULL;
			tail = NULL;
		}
		
		//inserts node at the end of the linked list
		void insert(int value)
		{
			//create new node
			Node *temp = new Node;
			//sets value as data for temp
			temp->data = value;
			//modify links
			
			//condition for inserting first link
			if(head == NULL)
			{
				head = temp;
			}
			
			else
			{
				temp->next = head;
				tail->next = temp;
			}
			
			tail = temp;
			cout<<endl;
		}
		
		//deletes node from the end
		void deletion()
		{
			//set Node pointer temp as the node to be deleted
			Node *temp = tail;
			
			//node just before temp should point to head
			Node *current = head;
			while(current->next != tail)
			{
				current = current->next;
			}                                     //now current points to node just before tail
			
			//modify links
			current->next = head;
			
			//update tail
			tail = current;
			
			//delete temp
			delete temp;
		}
		
		//inserts nodes at a given position specified by the user
		void insertAt(int pos, int value)
		{
			int count = 1;     //keeps track of number of nodes (initialized as 1 and not 0 since linked list is linked circularly
			//move current pointer till node just before last node
			Node *current = head;
			while(current != tail)
			{
				count++;
				current = current->next;
			}
			
			if(pos>count+1)
			{
				cout<<endl;
				cout<<"Linked List does not have that many elements\n";
			}
			
			else
			{
				//to add node at first position
				if(pos == 1)
				{
					//create new node
					Node *temp = new Node;
					//set data of new node as value
					temp->data = value;
					//modify tail pointer to point to new node
					tail->next = temp;
					//link new node to head
					temp->next = head;
					//update head
					head = temp;
				}
				
				else
				{
					//create new node
					Node *temp = new Node;
					//set data of the node as value
					temp->data = value;
					//move current pointer upto node just before position
					Node *current = head;
					int i = 1;
					while(i<pos-1)
					{
						i++;
						current = current->next;
					}
					//modify links
					temp->next = current->next;
					current->next = temp;
				}
			}
		}
		
		//deletes node at a position specified by the user
		void deletionAt(int pos)
		{
			if(pos == 1)
			{
				//create temp pointer and initialize it with head
				Node *temp = head;
				//modify tail pointer to point to node next to head
				tail->next = head->next;
				//update head
				head = head->next;
				//delete temp
				delete temp;
			}
			
			else
			{
				//move current pointer upto node just before position
				Node *current = head;
				int i = 1;
				while(i<pos-1)
				{
					i++;
					current = current->next;
				}
				
				//create new node and set it as the node to be deleted
				Node *temp = new Node;
				temp = current->next;
				
				//modify links
				current->next = temp->next;
				//delete temp
				delete temp;
			}
		}
		
		//returns the number of nodes in the circular linked list
		int countItems()
		{
			//create counter variable to store number of nodes 
			int count = 0;
			//create current pointer and move it to last node and simulataneously increment count
			Node *current = head;
			while(current->next != head)
			{
				count++;
				current = current->next;
			}
			
			//returns count
			return count+1;
		}
		
		//displays the contents of the linked list
		void display()
		{
			//create current pointer and initialize it as node next to head
			Node *current = head->next;
			//displays content of first node
			cout<<head->data<<"->";
			//move current pointer upto last node and display the contents of each node
			while(current != head)
			{
				cout<<current->data<<"->";
				current = current->next;
			}
			
			cout<<"NULL";
			cout<<endl;
		}
};


//driver function
int main()
{
		CLL cll1;              //declaration of doubly linked list
	for(int i= 1; i < 11; i++){
        cll1.insert(i);
    }
	cll1.display();
	cll1.deletion();
	cll1.display();
	cll1.insertAt(2,11);
	cll1.display();
	cll1.insertAt(5,27);
	cll1.display();
    cll1.deletionAt(3);
    cll1.display();
    cll1.deletionAt(5);
    cll1.display();
    cll1.insertAt(15,13);
    
	cout<<"Number of nodes are "<<cll1.countItems()<<endl;
	
	cll1.insertAt(11,56);
	cll1.display();

	
	return 0;
}