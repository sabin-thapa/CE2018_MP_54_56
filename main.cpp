#include "miniProject.cpp"
using namespace std;

int main() {
	//Minimum and Maximum values for user input
	const int    MIN_TRANS_TIME = 0, MAX_TRANS_TIME = 60,
				 MIN_NUM_SERV   = 0, MAX_NUM_SERV   = 10,
				 MIN_SIM_TIME   = 0, MAX_SIM_TIME   = 420,
				 MIN_ARRIV_TIME = 0, MAX_ARRIV_TIME = 100;
				 
	char runAgain = 'Y'; //Set runAgain so the program runs again if the user wishes.
	int simulation_time, transaction_time, num_Serv, arriv_Time; //User input variables
	int i, c_Time; //Counters
	int customers ,wait_Time; //Total customers and integer for waiting time of customers
	srand(time(0));
	while (runAgain != 'N') {
		i = 0; c_Time = 0;
		customers = 0; wait_Time = 0;
		
		Queue bankQ; // object of queue class
	
		cout << "\n#################################################"
			 << "\n**** BANK QUEUE SIMULATION PROGRAM ****"
			 << "\n#################################################";
		
		//Menu information
		cout << "\n\nPlease input the following data(Time in minutes):\n";
		cout << "\nLength of the Simulation(in minutes): ";
		cin >> simulation_time;
		while (simulation_time <= MIN_SIM_TIME || simulation_time > MAX_SIM_TIME) {
			cout << "Invalid input. Please re-enter: ";
			cin >> simulation_time;
		}
			cout << "Average Number of Servers: ";
		cin >> num_Serv;
		while (num_Serv <= MIN_NUM_SERV || num_Serv > MAX_NUM_SERV) {
			cout << "Invalid input. Please re-enter: ";
			cin >> num_Serv;
		}
		cout<<endl;
				
		//Dynamically allocate an array for the teller structure
		Teller * tArray = new Teller[num_Serv];
		
		//Set all the tellers to empty
		for (i = 0; i < num_Serv; i++) {
			tArray[i].is_active = false;
			tArray[i].time = 0;
			tArray[i].customer_id = 0;
			tArray[i].count = 0;
		}
		
		int total_trans_time = 0;
		int arriv_Customers = 0;
		int wait = 0;
		while (c_Time < simulation_time) { //Run until simulation time is reached
			
			arriv_Customers = rand() % 5;  // generating random time for the arrival of customers
			cout << "At time "<< c_Time << " "<< arriv_Customers << " customers arrive at the bank!" << endl;
				for(i = 0 ; i < arriv_Customers; i++)
				{
					bankQ.enqueue(++customers,c_Time);
				}
			
				for (i = 0; i <num_Serv; i++) {
						if (tArray[i].is_active == false && bankQ.getSize() != 0) { //Dequeue if a teller is open
						transaction_time = rand() % 5 + 1;
						total_trans_time  += transaction_time;
						
						tArray[i].is_active = true;
						tArray[i].time = transaction_time;
						tArray[i].customer_id = bankQ.front()->customer_id;
						tArray[i].count++;
						wait = c_Time - bankQ.front()->enqueue_time;
						
						cout <<"Server " << i << "  is serving customer #" << tArray[i].customer_id<< endl;
						cout << "\tWaited time:  " << wait << " minutes. "<< endl << "\tTransaction time: " << transaction_time << " minutes."<<endl;
						bankQ.dequeue();
						cout<<endl;
				}
			
		}
			
			
			for (i = 0; i < num_Serv; i++) {
				if (tArray[i].is_active == true) {
					tArray[i].time--;  //Decrement time spent at teller
				}
				if (tArray[i].time == 0) {
					tArray[i].is_active = false; //Set teller to open if time limit is reached
				}
			}
			wait_Time += bankQ.getSize(); //Set wait time to persons left in Queue*/
			c_Time++;
		}
		//Output user input data
		cout << "\n###############"
			 << "\n* Data Output *"
			 << "\n###############\n";
			 
		cout << setw(40) << left << "Simulation Time: ";
		cout << simulation_time <<" minutes" << endl;
		
		cout << setw(40) << left << "Average Transaction Time: ";
		cout << float(total_trans_time) / (customers - bankQ.getSize()) <<" minutes"  << endl;
		
		cout << setw(40) << left << "Average Number of Servers: ";
		cout << num_Serv <<" servers" << endl;

		
		//Output calculated data
		cout << setw(40) << left  << "Average Total Wait Time: ";
		cout << fixed << setprecision(2)
			 << (float)wait_Time/customers<<" minutes";
		cout << setw(40) << left  << "\nCustomers in line at end of simulation: "
	         << bankQ.getSize() <<" customers" << endl;
		
		cout<<endl;
		cout << "After simulation time : " << endl;
		for(i = 0; i < num_Serv;i++)
		{
			cout << "Server " << i << " is serving customer #" << tArray[i].customer_id << endl;
			cout << "Server " << i << " has served " << tArray[i].count << " customers" << endl;
		}
		//Ask to run the program again
		cout << "\nRun the program again? (y/n): ";
		cin >> runAgain;
		runAgain = (char)toupper(runAgain);
		while (runAgain != 'Y' && runAgain != 'N') {
			cout << "Invalid Entry, please re-enter: ";
			cin >> runAgain;
			runAgain = (char)toupper(runAgain);
		}
		//Deallocate teller structure array
		delete [] tArray;
	}	
	return 0;
}
