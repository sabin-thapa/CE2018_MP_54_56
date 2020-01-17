#include <iostream>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>

#include "miniProject.h"

//These are the funcn definitions
Queue::Queue() {
	first = NULL;	
	last = NULL;
	mySize = 0;	
}
void Queue::enqueue(int &x,int &y)
{	
	nodePtr nPtr = new Node();
	nPtr->customer_id = x;
	nPtr->enqueue_time = y;
	nodePtr predPtr = first; 	
	if (first == NULL) { 										//Insert if the queue is empty		
		nPtr->next = first;		
		first = nPtr;	} 
	else { 														//Insert at the end of the queue		
		while (predPtr->next) {			
			predPtr = predPtr->next;		}		
		predPtr->next = nPtr;	}	
	mySize++;	
	last = nPtr; 
} 
void Queue::dequeue() {	
	if (first) {	
		nodePtr dPtr = first;
		first = first->next; 										//To set first to the second node in the list		
		delete dPtr; 												//To delete the node that has been dequeued	
	}	
	mySize--; 
}
int Queue::getSize() {	
	return mySize;
}


//Queue Destructor
Queue::~Queue() {	
	if (first)
	{												//Deallocate all the nodes in the queue		
		nodePtr current = first;		
		nodePtr temp = first; 
		temp = current->next;		
		delete current;		
		current = temp;	
	}
}

