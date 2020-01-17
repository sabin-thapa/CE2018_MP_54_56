//The teller structure
struct Teller {
	int time;
	int customer_id;
	int count;
	bool is_active;
};

//classes
class Queue{ 
public: 		
	class Node { 			
	public: 			
		int enqueue_time;
		int dequeue_time;
		int customer_id;
		Node *next;				  				
		Node() { 
			// Node constructor					
			enqueue_time = 0;
			dequeue_time = 0;
			customer_id = 0;
			next = NULL;				
		} 		
	}; 
	//end of Node class 
	
	typedef Node *nodePtr;  //creating an alias of Node 
//Default constructor		
	Queue(); 		
	
	
//To add to the back of the queue		
	void enqueue(int &x,int &y); 		
	
//To remove from the front of the queue		
	void dequeue(); 		
	
//Returns the front of the queue		
	nodePtr front()
	{
		if (first) {		
		nodePtr ptr = first;		
		return ptr;	}
	}
//To return the size of the queue		
	int getSize(); 	
//To return the arrival time of a customer
	int enqueueTime(nodePtr p){
		return p->enqueue_time;
	}
	int dequeueTime(nodePtr p){
		return p->dequeue_time;
	}
	int  getId(nodePtr p){
		return p->customer_id;
	}
//Destructor		
	~Queue(); 	
private: 	
	int mySize;
	Node *first;		
	Node *last;		
	 
};
