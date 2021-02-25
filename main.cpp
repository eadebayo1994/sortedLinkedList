#include <iostream>
#include <string>
/* Emmanuel Adebayo
 * 11/2/2021
 * main.cpp
 *
 *a class Customer that requires a name, customer ID, address and phone number.
Using linked lists, create a list of customers in order by customer id. Create a menu-driven program to provide the following options:
Add  a new entry to the customer list.
Delete an entry from the customer list
Display the list
 * */
using namespace std;

//linked list node
class Customer {
public:
    string name;
    int customer_id;
    string address;
    long phone_number;

    Customer *next; //iterator

    //constructor
    Customer(string name, string address, int customer_id, long phone_number){
        this->name = name;
        this->address = address;
        this->customer_id = customer_id;
        this->phone_number = phone_number;
    }
};

Customer *head = NULL;
Customer *tail = NULL;
Customer *current = head;
//insert function
void insert(Customer* & head, string n_name, string n_address, int n_customer_id, long n_phone_numbe){
    if (head == NULL || n_customer_id < head->customer_id){
        cout<<"adding "<<n_name<<" to an empty list"<<endl;
        Customer *temp = new Customer(n_name,n_address,n_customer_id,n_phone_numbe);
        temp->next = head;
        head = temp;
    } else {
        Customer* current = head;
        Customer *temp = new Customer(n_name,n_address,n_customer_id,n_phone_numbe);

        //iterate until we reach end of loop

        while (current->next != NULL){
            if (n_customer_id < current->next->customer_id){
                temp->next = current->next;
                current->next = temp;
                break;
            }
            current = current->next;
        }

        //if we reached end of the list we add at the end;
        if (current->next == NULL){
            cout<<"adding "<<n_name<<" to end of the list"<<endl;
            current->next = temp;
        }
    }

    //end of insert
}
//free memory
void purgeList(Customer* & head){
    Customer* current = head;
    Customer* temp;

    //iterate until we reach end of list
    while (current != NULL){
        temp = current;
        current = current->next;

        cout<<"deleting "<<temp->customer_id <<endl;
        delete temp;
    }
}

//printing link list
void printList(Customer* &head){
    Customer* current = head;

    //iterate until we reach end of list

    while (current != NULL){
        cout<<"name "<<current->name<<endl;
        cout<<"customer id "<<current->customer_id<<endl;
        cout<<"adress "<<current->address<<endl;
        cout<<"phone number "<<current->phone_number<<endl;
        current = current->next;
    }
}

void deleteItem(Customer* &head, int id){
    if (head == NULL) {
        cout << "Empty list - nothing to delete here"<<endl;
        return;
    }
    if (head->customer_id == id) {
        cout <<"deleting " <<id <<" from head" <<endl;
        Customer *temp = head;
        head = head->next;
        delete temp;
    } else {
        Customer* current = head;
    }
}

int main() {
    //std::cout << "Hello, World!" << std::endl;

    Customer *head = NULL;
    string name, address, yesNo;
    int cust_id;
    long phone_num;

    do {
        cout<<"enter name"<<endl;
        cin.ignore();
        getline(cin,name);

        cout<<"enter address"<<endl;
        cin.ignore();
        getline(cin,address);

        cout<<"enter customer id"<<endl;
        cin>>cust_id;

        cout<<"enter phone number"<<endl;
        cin>>phone_num;

        insert(head, name, address, cust_id, phone_num);

        cout<<"would you like to add another value"<<endl;
        cin>>yesNo;
    } while (yesNo == "Y" || yesNo == "y");

    printList(head);
    cout<<"purging the list"<<endl;
    purgeList(head);

    return 0;
}
