#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

//C:\Users\lpdtd\Downloads\customers.txt


//struct for each customer in the overbooked list
struct customer {
    public:
    string customerName;
    int totalMileage;
    int flierYears;
    int sequenceNumber;
    int priorityNumber;


    //constructor no arg

    customer() {
        this->customerName = "John Marston";
        this->totalMileage = 0;
        this->flierYears = 0;
        this->sequenceNumber = 0;
        this->priorityNumber = 0;

    }
    //constructor with arg
    customer(string name, int mileage, int years, int sequence) {
        this->customerName = name;
        this->totalMileage = mileage;
        this->flierYears = years;
        this->sequenceNumber = sequence;
        priorityNumber = (totalMileage/1000 + flierYears - sequenceNumber);
    }
};

//class for comparison of priority number
class comparison{
    public:
    //overloading operator for less than
       bool operator()(customer& c1, customer& c2){
           if(c1.priorityNumber < c2.priorityNumber){
               return true;
           }
           return false;
      }
};

int main(void) {
    //customers vector
    vector<customer> customers;

    //priority queue for customers
    priority_queue<customer, vector<customer>, comparison> customerQueue;

    //use ifstream to take the customers file from my PC, store each line in a string
    ifstream infile("C:/Users/lpdtd/Downloads/customers.txt");
    string line;

    //skip first line 
    getline(infile, line);

    while(getline(infile,line)) {
    
        //initialization of token strings
        string nameToken;
        string mileageToken;
        string yearsToken;
        string sequenceNumberToken;

        //use istringstream to parse the data into tokens, then update customer object accordingly
        istringstream parsed_data(line);
        getline(parsed_data, nameToken, '\t');
        getline(parsed_data, mileageToken, '\t');
        getline(parsed_data, yearsToken, '\t');
        getline(parsed_data, sequenceNumberToken, '\t');

        //create customer object with tokens
        customer c = customer(nameToken, stoi(mileageToken), stoi(yearsToken), stoi(sequenceNumberToken));

        //add customer object to customer vector
        customers.push_back(c);

        //print tokenized data to check if the line is correctly broken
        //cout << "CustomerName: " << c.customerName << " CustomerMileage: " << c.totalMileage << " CustomerFrequentFlierYears: " << c.flierYears << " CustomerSequenceNumber: " << c.sequenceNumber << endl;
        //cout << "CustomerPriorty: " << c.priorityNumber << endl << endl;
        //}

        //from customers vector, insert all objects into priority queue
        for(customer c : customers) {
        customerQueue.push(c);
        }
    
    //while loop to display customers w/ highest priority service
    //check if empty for loop condition
    while(!customerQueue.empty()) {
        //make customer object according to the current top of the queue
        customer customerTop = customerQueue.top();
        //print according to current object
        cout << "Name: " << customerTop.customerName << " -> Priority: " << customerTop.priorityNumber << endl;
        //pop current object
        customerQueue.pop();
    }

    return 0;
}