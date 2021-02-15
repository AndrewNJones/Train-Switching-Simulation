//Andrew Jones
//CS 315 - Project 1
//2/12/2021

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//------------------------------------------
//Node Struct Declaration

//this node will be the structure for the cars of our train
struct node{
	//each node contains a value and a pointer to the next and previous nodes
	int value;
        node* next;
        node* prev;
};
//------------------------------------------
//Train Class Declaration
//My doubly linked list is implemented as a class
class train{
	public:
		train();
		void addFront(int value);
		int  deleteFront();
		int  deleteBack();
		int  getSize();
		int getValue();

	private:
		//I use the variable size to keep track of the number of cars for each train
		node* head;
		node* tail;
		int size;
};
//-----------------------------------------
//Train Class Implementation
//
//basic constructor
train::train(){
	head = NULL;
	tail = NULL;
	size = 0;
}

//this function adds a car to the front of our train
void train::addFront(int new_value){

	//allocate memory
	node* newNode = new node;

	//the argument of the function is the value of the car
	newNode->value = new_value;

	//the next pointer of the new node is equal to the old head pointer
	newNode->next = head;
	newNode->prev = NULL;

	//if there is another node in the linked list, its previous pointer points to the new node
	if (head != NULL)
	     head->prev = newNode;
		
	//the head now points to the new node
	head = newNode;

	//if this node is added to an empty train, the tail pointer points to the new node
	if (tail == NULL)
		tail = newNode;
	
	//size is increased
	size++;

//Note: There is no addBack function because carts are always added to the front in this project
}


//this function deletes a car from the front of the train
int train::deleteFront(){

	//this function only happens when the train has at least one car
	if (head != NULL){

		//the value of the node is stored in temp
		int temp = head->value;
		//if there is a node after the one being deleted, its previous pointer is now null
		if (head->next != NULL)
 			head->next->prev = NULL;
		
		//the head pointer now points to the next node
		head = head->next;

		//the size of the train is decreased
		size--;

		//the value of the deleted car is returned
		return temp;
	}
	else
		//this should never happen, but it is here just in case something  goes wrong
		return -1;
}

//this function deletes a car from the back of the train. The semantics are the same as the
//previous function, but head is replaced with tail and next/prev are reversed
int train::deleteBack(){
	if (tail != NULL){
	        int temp = tail->value;
       		if (tail->prev != NULL)
	 		tail->prev->next = NULL;
		tail = tail->prev;
		size--;
		return temp;
	}
	else
	return -1;	
}

//this returns the size of our train (in cars)
int train::getSize(){
return size;
}

//this function returns the value of our train
int train::getValue(){
	int value = 0;
	node* temp = head;

	//this for loop walks down the linked list and adds the value of each car
	for (int i = 1; i <= size; i++){
		value += (temp->value * i);
		temp = temp->next;
	}
	return value;
}
//--------------------------------------------------
//Dice Roll Function

//this function returns our die role, where i is how many sides the die has
int randGen(int i){
	int random_seed;

	//piped in from randGen.pl
	cin >> random_seed;
	random_seed = random_seed % i;
	return random_seed;
}

//--------------------------------------------------
//Main Function

//our main function takes command line arguments
int main(int argc, char* argv[]){

	//these variables are obtained from the command line input
	int num_trains = stoi(argv[1]);
	int num_nodes = stoi(argv[2]);
	int max_steps = stoi(argv[3]);

	//checks to make sure the command line input is valid
	if (num_trains < 1 || num_nodes < 1 || max_steps < 1){
	cout << "Sorry, the parameters entered are invalid. Please try again. \n";
	}
	else {
		//our station is organized as an array of doubly linked lists (trains).
		train station[num_trains];
	
		//this creates our trains initial configurations
		for (int i = 0; i < num_trains; i++){
			for (int j = 0; j < num_nodes; j++){
				station[i].addFront(num_nodes - j);
			}
		}
		
	        //this string is used when we print turns to the standard output
		string side;

		//these two variables are used to let us know when the program needs to end
		int step_count = 0;
		bool isEmpty = false;

		//each iteration of this while loop is a new turn
		while (step_count < max_steps && !isEmpty){
			
			//three dice roles decide the donor, reciever, and side for this turn
			int donor_train = randGen(num_trains);
			int side_donated = randGen(2) + 1;
			int reciever = randGen(num_trains);

			//a dice role of 1 means the car will be deleted from the donor's front
			if (side_donated == 1){

				//the value returned from our deletion function is used as the argument for our add function
				station[reciever].addFront(station[donor_train].deleteFront());
				side = "front";
			}
			else{
				station[reciever].addFront(station[donor_train].deleteBack());
				side = "back";
			}

			//the turn count is increased
			step_count++;

			//the events of the turn are printed to standard output
			cout << "Turn " << step_count << ": train " << donor_train + 1 << " sends a car to train " << reciever + 1 << ", from the " << side << endl;
		       for (int i = 0; i < num_trains; i++){

			       //the values of all trains are printed to standard output
		      		 cout << "          train " << i + 1 << " value: " << station[i].getValue() << endl;
		       }		 



		       //this loop checks if any of the trains are empty after each turn
			for (int i = 0; i < num_trains; i++){
			int size = station[i].getSize();
				if (size <  1)
					isEmpty = true;
				}	

		}

		//these variables will be used to determine the winner when the simulation is over
		int highest_score = 0;
		int winning_train = 0;

		//this for loop checks the winner
		for (int i = 0; i < num_trains; i++){
			if (station[i].getValue() > highest_score){
				highest_score = station[i].getValue();
				winning_train = i + 1;
			}
		}
		cout << "Simulation complete. Train " << winning_train << " has the highest value.\n";


	}

	return 0;
};



