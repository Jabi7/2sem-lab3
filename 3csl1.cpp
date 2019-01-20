//Program to insert,delete and count no. of elements of a doubly linked list
#include<iostream>    //library header

using namespace std;         //namespace

class Node
{
	public:
		
		//the data
		int data;
		//pointers to move to next node and previous node
		Node *next;
		Node *prev;
		
		//default constructor to set both of the pointers to NULL
		Node()
		{
			next = NULL;
			prev = NULL;
		}
};

class DLL
{
	//Head and circles (nodes) linked to each another
	public:
		//head and tail pointers for DLL
		Node *head;
		Node *tail;
		
		//constuctor that initializes head and tail as NULL
		DLL()
		{
			head = NULL;
			tail = NULL;
		}
		
		//Circles inside linked to one another (both links to move forward and backward present)
		
		//inserts new nodes to the DLL at the end
		void insert(int value)
		{
			//create new node
			Node *temp = new Node;
			//set value as data of new node
			temp->data = value;
			
			//indicates first node being added
			if(head == NULL)
			{
				head = temp;
			}
			
			else
			{
				//use tail ptr to modify the link
				tail->next = temp;   //forward link
				temp->prev = tail;   //backward link
		        }
			
			tail = temp;
			cout<<endl;
		}
		
		//deletes nodes present at the end
		void deletion()
		{
			//creates temp pointer to store node at end
			Node *temp = tail;
			//create another pointer to move forward till end but the last node
			Node *current = head;
			while(current->next != tail)
			{
				current = current->next;             
			}
			
			//link modification to set current as tail and it points to NULL
			current->next = NULL;
			current = tail;
			
			
			//delete temp
			delete temp;
			cout<<endl;
		}
		
		//inserts node at a specific position in the linked list
		void insertAt(int pos,int value)
		{
			int count = 0;     //keeps count of number of nodes in the doubly linked list
			Node *current = head;     //initializes current pointer with head
			//move current pointer upto last node and increment count
			while(current!=NULL)
			{
				count++;
				current = current->next;
			}
			
			if(pos>count)
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
					//set value as data of the node
					temp->data = value;
					//modify links
					temp->next = head;    //forward link
					head->prev = temp;          //backward link
					//update head
					head = temp;
				}
				
				else
				{
					//set current pointer as head
					Node *current = head;
					//current pointer goes upto node just before the position (set as parameter)
					int i=1;
					while(i<pos-1)
					{
						i++;
						current=current->next;
					}
					//new node is created
					Node *temp = new Node;
					
					//sets value as data of the node
					temp->data = value;
					
					//links re-established
					temp->next = current->next;          //forward link
					current->next = temp;                //forward link
					temp->next->prev = temp;             //backward link
					temp->prev = current;                //backward link
			         }
		    }
		    
		    cout<<endl;
		}
		
		//deletes nodes at a specific position in the linked list
		void deletionAt(int pos)
		{
			//extra condition for deleting first node
			if(pos==1)
			{
				//sets temp pointer as head
				Node *temp = head;
				
				//update head
				head = head->next;
				
				//delete temp
				delete temp;
			}
			
			else
			{
				//set current pointer as head
				Node *current = head;
				//move current pointer upto position just before the node to be deleted
				int i=1;
				while(i<pos-1)
				{
					i++;
					current = current->next;
				}
				//set temp pointer as node to be deleted
				Node *temp = new Node;
			        temp = current->next;
			    
			        //re-establish link
			        current->next = temp->next;           //forward link
			        temp->next->prev = current;           //backward link
			    
			        //delete temp
			        delete temp;
		         }
		    cout<<endl;
		}
		
		//displays the contents of the linked list
		void display()
		{
			//set current pointer as head
			Node *current = head;
			//keep moving current pointer and printing the contents
			while(current != NULL)
			{
				cout<<current->data<<"->";
				current = current->next;
			}
			cout<<"NULL";
		}
		
		//displays the number of nodes in the linked list
		void countItems()
		{
			//counter variable to keep count of number of nodes
			int count = 0;
			//sets current pointer as head
			Node *current = head;
			//move current pointer till last node and simultaneously increase count
			while(current != NULL)
			{
				count++;
				current = current->next;
			}
			
			cout<<"Number of elements: "<<count<<endl;
		}	
};

int main()    //main function
{
	DLL dll1;              //declaration of doubly linked list
	for(int i= 1; i < 11; i++){
        dll1.insert(i);
    }
	dll1.display();
	dll1.deletion();
	dll1.display();
	dll1.insertAt(2,11);
	dll1.display();
	dll1.insertAt(5,27);
	dll1.display();
    dll1.deletionAt(3);
    dll1.display();
    dll1.deletionAt(5);
    dll1.display();
    dll1.insertAt(15,13);
    dll1.countItems();
    
	return 0;       //returns zero
}