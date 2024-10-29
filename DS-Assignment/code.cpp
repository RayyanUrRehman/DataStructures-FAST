#include <algorithm>
#include<cctype>
#include <iostream>
#include <ctime>
#include <string>
#include<fstream>
#include<sstream>
#include "config.h"

using namespace std;

class Tickets {
public:
    int ticket_id;
    string cust_name;
    int priority;
    string request_des;
    time_t creation_time;  
    string creation_time_str; 
    bool status;
    string close_time;
    Tickets* next;

    Tickets() {}

    Tickets(int id, string n, int p, string des, bool s)
        : ticket_id(id), cust_name(n), priority(p), request_des(des), status(s), next(nullptr) {
        time(&creation_time);  
        creation_time_str = ctime(&creation_time);
        close_time = ""; 
    }
};

class Linked_list_Tickets {
public:
    Tickets* head;

    Linked_list_Tickets() {
        head = nullptr;
    }
    bool ticket_exists(int id) {
        Tickets* temp = head;
        while (temp != nullptr) {
            if (temp->ticket_id == id) return true;
            temp = temp->next;
        }
        return false;
    }
    void add_ticket(int id, string n, int p, string req, bool status) {
        Tickets* newticket = new Tickets(id, n, p, req, status);
        if (head == nullptr) {
            head = newticket;
        } else {
            Tickets* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newticket;
        }
        cout << "Ticket added with ID: " << newticket->ticket_id << endl;
    }

    void delete_ticket(int id) {
        if (head == nullptr) {
            cout << "No tickets to delete.\n";
            return;
        }

        if (head->ticket_id == id) {
            Tickets* del = head;
            head = head->next;
            delete del;
            cout << "Ticket with ID " << id << " deleted.\n";
            return;
        }

        Tickets* temp = head;
        while (temp->next != nullptr && temp->next->ticket_id != id) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Ticket with ID " << id << " not found.\n";
        } else {
            Tickets* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            cout << "Ticket with ID " << id << " deleted.\n";
        }
    }

    void search_ticket(int id) {
        Tickets* temp = head;
        while (temp != nullptr) {
            if (temp->ticket_id == id) {
                cout << "Ticket ID: " << temp->ticket_id << endl;
                cout << "Customer Name: " << temp->cust_name << endl;
                cout << "Priority: " << temp->priority << endl;
                cout << "Request Description: " << temp->request_des << endl;
                cout << "Creation Time: " << temp->creation_time_str;
                cout << "Status: " << (temp->status ? "Open" : "Closed") << endl;
                if (!temp->status) {
                    cout << "Close Time: " << temp->close_time;
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Ticket with ID " << id << " not found.\n";
    }

    void display() {
        Tickets* temp = head;
        if (temp == nullptr) {
            cout << "No tickets available.\n";
            return;
        }
        cout << "Displaying tickets details:\n";
        while (temp != nullptr) {
            cout << "Ticket ID: " << temp->ticket_id << endl;
            cout << "Customer Name: " << temp->cust_name << endl;
            cout << "Priority: " << temp->priority << endl;
            cout << "Request Description: " << temp->request_des << endl;
            cout << "Creation Time: " << temp->creation_time_str; 
            cout << "Status: " << (temp->status ? "Open" : "Closed") << endl;
            if (!temp->status) {
                cout << "Close Time: " << temp->close_time;
            }
            cout << "-------------------------------------\n";
            temp = temp->next;
        }
    }
    //merge Sort
Tickets* sortedMerge(Tickets* a, Tickets* b) {
    if (!a) return b;
    if (!b) return a;

    Tickets* result;
    if (a->ticket_id <= b->ticket_id) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void frontBackSplit(Tickets* source, Tickets** frontRef, Tickets** backRef) {
    Tickets* fast = source->next;
    Tickets* slow = source;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}

void mergeSort(Tickets** headRef) {
    if (!*headRef || !(*headRef)->next) return;

    Tickets* a;
    Tickets* b;
    frontBackSplit(*headRef, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortedMerge(a, b);
}
//quick sort
Tickets* getTail(Tickets* node) {
    while (node != nullptr && node->next != nullptr) {
        node = node->next;
    }
    return node;
}
Tickets* partition(Tickets* head, Tickets* end, Tickets** newHead, Tickets** newEnd) {
    Tickets* pivot = end;
    Tickets *prev = nullptr, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->ticket_id < pivot->ticket_id) {
            if (!*newHead) *newHead = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            Tickets* temp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }
    if (!*newHead) *newHead = pivot;
    *newEnd = tail;
    return pivot;
}

Tickets* quickSortRecur(Tickets* head, Tickets* end) {
    if (!head || head == end) return head;

    Tickets *newHead = nullptr, *newEnd = nullptr;
    Tickets* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Tickets* temp = newHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = nullptr;

        newHead = quickSortRecur(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

void quickSort(Tickets** headRef) {
    *headRef = quickSortRecur(*headRef, getTail(*headRef));
}

//selection sort
void selectionSort(Tickets** headRef) {
    Tickets* temp = *headRef;

    while (temp) {
        Tickets* min = temp;
        Tickets* r = temp->next;

        while (r) {
            if (r->ticket_id < min->ticket_id) min = r;
            r = r->next;
        }
        swapNodes(temp, min);
        temp = temp->next;
    }
}

void swapNodes(Tickets* a, Tickets* b) {
    if (a != b) {
        swap(a->ticket_id, b->ticket_id);
        swap(a->cust_name, b->cust_name);
        swap(a->priority, b->priority);
        swap(a->request_des, b->request_des);
        swap(a->creation_time, b->creation_time);
        swap(a->creation_time_str, b->creation_time_str);
        swap(a->status, b->status);
        swap(a->close_time, b->close_time);
    }
}
//insertion sort
void insertionSort(Tickets** headRef) {
    Tickets* sorted = nullptr;
    Tickets* current = *headRef;

    while (current) {
        Tickets* next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    *headRef = sorted;
}

void sortedInsert(Tickets** headRef, Tickets* newNode) {
    if (!*headRef || (*headRef)->ticket_id >= newNode->ticket_id) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        Tickets* current = *headRef;
        while (current->next && current->next->ticket_id < newNode->ticket_id) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

    void timesort() {
        if (head == nullptr) return; 

        for (Tickets* temp1 = head; temp1 != nullptr; temp1 = temp1->next) {
            for (Tickets* temp2 = temp1->next; temp2 != nullptr; temp2 = temp2->next) {
                if (temp1->creation_time > temp2->creation_time) {
                    tswap(temp1, temp2);
                }
            }
        }
    }

    void namesort() {
        if (head == nullptr) return;

        for (Tickets* temp1 = head; temp1 != nullptr; temp1 = temp1->next) {
            for (Tickets* temp2 = temp1->next; temp2 != nullptr; temp2 = temp2->next) {
                if (temp1->cust_name > temp2->cust_name) {
                    tswap(temp1, temp2);
                }
            }
        }
    }

    void idsort() {
        if (head == nullptr) return;

        for (Tickets* temp1 = head; temp1 != nullptr; temp1 = temp1->next) {
            for (Tickets* temp2 = temp1->next; temp2 != nullptr; temp2 = temp2->next) {

                if (temp1->ticket_id > temp2->ticket_id) {
                    tswap(temp1, temp2);
                }
            }
        }
    }

    void tswap(Tickets* a, Tickets* b) {
        swap(a->ticket_id, b->ticket_id);
        swap(a->cust_name, b->cust_name);
        swap(a->priority, b->priority);
        swap(a->request_des, b->request_des);
        swap(a->creation_time, b->creation_time);
        swap(a->creation_time_str, b->creation_time_str);
        swap(a->status, b->status);
        swap(a->close_time, b->close_time);
    }

    void sort(int p) {
        if (p == 1) {
            timesort();
        } else if (p == 2) {
            namesort();
        } else if (p == 3) {
            idsort();
        }
    }
};

class Agent {
public:
    int agent_id;
    string name;
    int* assigned_tickets; 
    bool availability; 
    int num;              

    Agent() {}

    Agent(int id, string n) : agent_id(id), name(n), availability(true), num(0) {
        assigned_tickets = nullptr; 
    }

    ~Agent() {
        delete[] assigned_tickets;
    }

    void assign_ticket(int t_ID) {
        if (num >= 5) {
            availability = false;
            cout << "Agent " << name << " is at full capacity." << endl;
            return;
        }

        int* temp = new int[num + 1];
        for (int i = 0; i < num; i++) {
            temp[i] = assigned_tickets[i];
        }

        temp[num] = t_ID;

        delete[] assigned_tickets;
        assigned_tickets = temp;
        num++;

        if (num >= 5) {
            availability = false;
        }

        cout << "Assigned ticket " << t_ID << " to agent " << name << endl;
    }

    int get_priority_number() const {
        return num;
    }
        void display() const {
        cout << "Agent ID: " << agent_id << ", Name: " << name << ", Availability: " 
             << (availability ? "Available" : "Unavailable") << ", Tickets Assigned: ";
        
        if (num == 0) {
            cout << "None";
        } else {
            for (int i = 0; i < num; i++) {
                cout << assigned_tickets[i] << (i < num - 1 ? ", " : "");
            }
        }
        cout << endl;
    }

};

class Agent_management {
public:
    Agent* agents;  
    int agent_count; 

    Agent_management() : agent_count(0), agents(nullptr) {}

    ~Agent_management() {
        delete[] agents;
    }

    void add_agent(Agent new_agent) {
        Agent* temp = new Agent[agent_count + 1];
        for (int i = 0; i < agent_count; i++) {
            temp[i] = agents[i];
        }

        temp[agent_count] = new_agent;

        delete[] agents;
        agents = temp;
        agent_count++;

        cout << "Added agent " << new_agent.name << " (ID: " << new_agent.agent_id << ")" << endl;
    }

    void assign_ticket_to_agent(int ticket_id) {
        if (agent_count == 0) {
            cout << "No agents available to assign tickets." << endl;
            return;
        }

        int min_tickets = 6; 
        int chosen_agent_index = -1;

        for (int i = 0; i < agent_count; i++) {
            if (agents[i].availability && agents[i].get_priority_number() < min_tickets) {
                min_tickets = agents[i].get_priority_number();
                chosen_agent_index = i;
            }
        }

        if (chosen_agent_index != -1) {
            agents[chosen_agent_index].assign_ticket(ticket_id);
        } else {
            cout << "No available agents to assign ticket " << ticket_id << endl;
        }
    }
    void display_all_agents() const {
        cout << "Agent Details:" << endl;
        for (int i = 0; i < agent_count; i++) {
            agents[i].display();
        }
    }
        void sort_agents_by_ticket_count() {
        for (int i = 0; i < agent_count - 1; i++) {
            for (int j = 0; j < agent_count - i - 1; j++) {
                if (agents[j].get_priority_number() > agents[j + 1].get_priority_number()) {
                    // Swap agents
                    Agent temp = agents[j];
                    agents[j] = agents[j + 1];
                    agents[j + 1] = temp;
                }
            }
        }
        cout << "Agents sorted by the number of assigned tickets." << endl;
    }

    void sort_agents_by_id() {
        for (int i = 0; i < agent_count - 1; i++) {
            for (int j = 0; j < agent_count - i - 1; j++) {
                if (agents[j].agent_id > agents[j + 1].agent_id) {

                    Agent temp = agents[j];
                    agents[j] = agents[j + 1];
                    agents[j + 1] = temp;
                }
            }
        }
        cout << "Agents sorted by Agent ID." << endl;
    }
        static int binary_search(Agent* agents, int count, int agent_id) {
        int left = 0;
        int right = count - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (agents[mid].agent_id == agent_id) {
                return mid; 
            }
            if (agents[mid].agent_id < agent_id) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; 
    }


    static int interpolation_search(Agent* agents, int count, int agent_id) {
        int low = 0, high = count - 1;

        while (low <= high && agent_id >= agents[low].agent_id && agent_id <= agents[high].agent_id) {
            if (low == high) {
                if (agents[low].agent_id == agent_id) {
                    return low; 
                }
                return -1; 
            }

            int pos = low + ((high - low) / (agents[high].agent_id - agents[low].agent_id) * (agent_id - agents[low].agent_id));

            if (agents[pos].agent_id == agent_id) {
                return pos;
            }

            if (agents[pos].agent_id < agent_id) {
                low = pos + 1; 
            } else {
                high = pos - 1; 
            }
        }
        return -1; 
    }
};

class Stack {
private:
    struct Node {
        int ticket_id;
        string resolution_detail;
        Node* next;
    };

    Node* top;  

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int id, string detail) {
        Node* new_node = new Node{id, detail, top};
        top = new_node;
    }

    void pop() {
        if (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        } else {
            cout << "No resolutions to pop." << endl;
        }
    }

    void display() {
        Node* temp = top;
        while (temp) {
            cout << "Ticket ID: " << temp->ticket_id << ", Resolution: " << temp->resolution_detail << endl;
            temp = temp->next;
        }
    }
};

class Queue {
private:
    struct Node {
        int ticket_id;
        string customer_name;
        int priority; 
        Node* next;
    };

    Node* front; 
    Node* rear;   

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
    string returnticketname(int id){
      Node* temp = front;
        while (temp != nullptr) {
            if (temp->ticket_id == id) return temp->customer_name;
            temp = temp->next;
        }
        
        return "Does not exists" ;
    }
        int returnticketpriority(int id){
      Node* temp = front;
        while (temp != nullptr) {
            if (temp->ticket_id == id) return temp->priority;
            temp = temp->next;
        }
        
        return -1;
    }
    bool ticket_exists(int id) {
        Node* temp = front;
        while (temp != nullptr) {
            if (temp->ticket_id == id) return true;
            temp = temp->next;
        }
        return false;
    }
    void enqueue(int id) {
        Node* new_node = new Node{id};
        if (rear) {
            rear->next = new_node;
        } else {
            front = new_node; 
        }
        rear = new_node;
        cout << "Ticket " << id << " added to the queue." << endl;
    }

    void dequeue() {
        if (front) {
            Node* temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete temp;
            cout << "Ticket dequeued." << endl;
        } else {
            cout << "Queue is empty." << endl;
        }
    }

    void display() {
        Node* temp = front;
        if (!temp) {
            cout << "No pending tickets." << endl;
            return;
        }
        cout << "Pending tickets in the queue:" << endl;
        while (temp) {
            cout << "Ticket ID: " << temp->ticket_id << ", Customer: " << temp->customer_name
                 << ", Priority: " << temp->priority << endl;
            temp = temp->next;
        }
    }
};

class TicketResolutionLogs {
private:

    struct StackNode {
        int ticket_id;
        string resolution_detail;
        StackNode* next;
    };

    struct QueueNode {
        int ticket_id;
        string customer_name;
        int priority;
        QueueNode* next;
    };

    StackNode* stackTop;     
    QueueNode* queueFront;    
    QueueNode* queueRear;  

public:
    TicketResolutionLogs() : stackTop(nullptr), queueFront(nullptr), queueRear(nullptr) {}

    ~TicketResolutionLogs() {

        while (stackTop) {
            StackNode* temp = stackTop;
            stackTop = stackTop->next;
            delete temp;
        }

        while (queueFront) {
            QueueNode* temp = queueFront;
            queueFront = queueFront->next;
            delete temp;
        }
    }

    void logClosedTicket(int ticket_id, const string& resolution_detail) {
        StackNode* newNode = new StackNode{ticket_id, resolution_detail, stackTop};
        stackTop = newNode;
        cout << "Ticket " << ticket_id << " resolved and added to resolution log.\n";
    }

    void addTicketToPendingQueue(int ticket_id, const string& customer_name, int priority) {
        QueueNode* newNode = new QueueNode{ticket_id, customer_name, priority, nullptr};

        if (!queueFront) { 
            queueFront = queueRear = newNode;
        } else {

            if (queueFront->priority < priority) { 
                newNode->next = queueFront;
                queueFront = newNode;
            } else {
                QueueNode* temp = queueFront;
                while (temp->next && temp->next->priority >= priority) {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
                if (newNode->next == nullptr) { 
                    queueRear = newNode;
                }
            }
        }
        cout << "Ticket " << ticket_id << " added to pending queue with priority " << priority << ".\n";
    }

    void viewResolutionLogs() const {
        if (!stackTop) {
            cout << "No resolved tickets to display.\n";
            return;
        }

        cout << "Recent Ticket Resolutions:\n";
        StackNode* temp = stackTop;
        while (temp) {
            cout << "Ticket ID: " << temp->ticket_id << ", Resolution: " << temp->resolution_detail << endl;
            temp = temp->next;
        }
    }

    void viewPendingTickets() const {
        if (!queueFront) {
            cout << "No pending tickets.\n";
            return;
        }

        cout << "Pending Tickets:\n";
        QueueNode* temp = queueFront;
        while (temp) {
            cout << "Ticket ID: " << temp->ticket_id << ", Customer: " << temp->customer_name
                 << ", Priority: " << temp->priority << endl;
            temp = temp->next;
        }
    }
       void removeTicketFromPendingQueue() {
        if (!queueFront) {
            cout << "No tickets to dequeue.\n";
            return;
        }

        QueueNode* temp = queueFront;
        queueFront = queueFront->next;
        if (!queueFront) {  
            queueRear = nullptr;
        }
        cout << "Ticket " << temp->ticket_id << " dequeued from pending queue.\n";
        delete temp; 
    } 
};

void management_function(Linked_list_Tickets &ticket_list, Agent_management &agent_management, Stack &resolution_stack, Queue &pending_tickets, TicketResolutionLogs &ticketresolutionlog) {
    cout << "SYED MUHIB ALI ZAIDI (23K-2030)\n";
    cout << "************************************************************************************************\n";
    cout << "________________________________________________________________________________________________\n\n";
    cout << "---------------------------------WELCOME TO ONE-STOP OF FAST NU---------------------------------\n";
    cout << "________________________________________________________________________________________________\n";
    int choice;
    while (true) {
        cout << "________________________________________________________________________________________________\n";
        cout << "(1). Add Ticket" << endl;
        cout << "(2). Display Tickets" << endl;
        cout << "(3). Add Agent" << endl;
        cout << "(4). Assign Ticket to Agent" << endl;
        cout << "(5). Enqueue Pending Ticket" << endl;
        cout << "(6). Dequeue Pending Ticket" << endl;
        cout << "(7). Log Resolution" << endl;
        cout << "(8). Display Resolution Logs" << endl;
        cout << "(9). Display Pending Tickets" << endl;
        cout << "(10). Remove Tickets" << endl;
        cout << "(11). Sort by Priority (1, 2, or 3)" << endl;
        cout<<"(12) Display Agent details \n";
        cout<<"(13) Sort agents\n";
        cout<<"(14) Search agents\n";
        cout << "(0). Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int ticket_id, priority;
                string customer_name, request_description;
                cout << "Enter Ticket ID: ";
                cin >> ticket_id;
                cout << "Enter Customer Name: ";
                cin >> customer_name;
                cout << "Enter Request Description: ";
                cin.ignore();
                getline(cin, request_description);
                ticket_list.add_ticket(ticket_id, customer_name, 0, request_description, 1);
                cout << "Ticket " << ticket_id << " added to the system.\n";
                break;
            }
            case 2:
                ticket_list.display();
                break;
            case 3: {
                int agent_id;
                string agent_name;
                cout << "Enter Agent ID: ";
                cin >> agent_id;
                cout << "Enter Agent Name: ";
                cin >> agent_name;
                agent_management.add_agent(Agent(agent_id, agent_name));
                break;
            }
            case 4: {
                int ticket_id;
                cout << "Enter Ticket ID to assign: ";
                cin >> ticket_id;
                if (ticket_list.ticket_exists(ticket_id)) {
                    agent_management.assign_ticket_to_agent(ticket_id);
                    cout << "Ticket " << ticket_id << " assigned to an agent.\n";
                } else {
                    cout << "No ticket with ID " << ticket_id << " exists.\n\n";
                }
                break;
            }
            case 5: {

                int ticket_id;
                cout << "Enter Ticket ID to enqueue: ";
                cin >> ticket_id;
                if(ticket_list.ticket_exists(ticket_id)){
                pending_tickets.enqueue(ticket_id);
                string name=pending_tickets.returnticketname(ticket_id);
                int p=pending_tickets.returnticketpriority(ticket_id);
                ticketresolutionlog.addTicketToPendingQueue(ticket_id,name,p);
                cout << "Ticket " << ticket_id << " added to pending queue.\n";
                }

                break;
            }
            case 6:
            ticketresolutionlog.removeTicketFromPendingQueue();
                pending_tickets.dequeue();
                break;
            case 7: {
                int ticket_id;
                string resolution_detail;
                cout << "Enter Ticket ID for resolution: ";
                cin >> ticket_id;
                cout << "Enter Resolution Detail: ";
                cin.ignore();
                getline(cin, resolution_detail);
                if (ticket_list.ticket_exists(ticket_id)) {
                    resolution_stack.push(ticket_id, resolution_detail);
                    ticket_list.delete_ticket(ticket_id);
                    cout << "Ticket " << ticket_id << " resolved and logged in resolution stack.\n";
                } else {
                    cout << "Ticket with ID " << ticket_id << " does not exist.\n";
                }
                break;
            }
            case 8:
                resolution_stack.display();
                break;
            case 9:
                pending_tickets.display();
                break;
            case 10: {
                int ticket_id;
                cout << "Enter Ticket ID to remove: ";
                cin >> ticket_id;
                if (ticket_list.ticket_exists(ticket_id)) {
                    ticket_list.delete_ticket(ticket_id);
                    cout << "Ticket with ID " << ticket_id << " has been removed.\n";
                } else {
                    cout << "Ticket with ID " << ticket_id << " does not exist.\n";
                }
                break;
            }
            case 11: {
                int priority;
                cout << "Enter the priority level (1-3): ";
                cin >> priority;
                if (priority >= 1 && priority <= 3) {
                    ticket_list.sort(priority);
                    cout << "Tickets sorted by priority level " << priority << ".\n";
                } else {
                    cout << "Invalid priority number. Please enter 1, 2, or 3.\n";
                }
                break;
            }
            case 12:
        agent_management.display_all_agents();
            break;
            case 13:
            if(agent_management.agent_count==0){
                cout<<"No available agents\n";
                return;
            }
            cout<<"Sort by id press (1) --Sort by ticket count press (2)\n";
            int x;
            cin>>x;
            if(x==1){
        agent_management.sort_agents_by_id();
            }else{

        agent_management.sort_agents_by_ticket_count();
            }

            break;
            case 14:
                cout << "Enter ID of the agent: ";
                int agent_id;
                cin >> agent_id;

                cout << "Decide which searching algorithm you want to choose:" << endl;
                cout << "1. Interpolation Search" << endl;
                cout << "2. Binary Search" << endl;

                int search_choice;
                cin >> search_choice;
                int found;

                if (search_choice == 1) {
                    found = agent_management.interpolation_search(agent_management.agents, agent_management.agent_count, agent_id);
                } else if (search_choice == 2) {
                    found = agent_management.binary_search(agent_management.agents, agent_management.agent_count, agent_id);
                } else {
                    cout << "Invalid search choice." << endl;
                    break;
                }

                if (found != -1) {
                    cout << "Agent found: ";
                    agent_management.agents[found].display(); // Display the found agent's details
                } else {
                    cout << "Agent with ID " << agent_id << " not found." << endl;
                }

                break;
            case 0:
                cout << "Exiting the management system...\n";
       
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

void readConfig(const string& filename, string& sorting_algorithm, string& searching_algorithm, int& threshold) {
    ifstream configFile(filename);
    if (!configFile) {
        cerr << "Could not open the config file: " << filename << endl;
        return;
    }

    string line;
    while (getline(configFile, line)) {
        istringstream iss(line);
        string key, value;

        if (getline(iss, key, '=') && getline(iss, value)) {
 
            value.erase(remove_if(value.begin(), value.end(), ::isspace), value.end());
            if (value.back() == ';') {
                value.pop_back();
            }

            if (key == "sorting_algorithm") {
                sorting_algorithm = value;
            } else if (key == "searching_algorithm") {
                searching_algorithm = value;
            } else if (key == "threshold") {
                threshold = stoi(value);
            }
        }
    }
}


int main() {
            Config config = readConfig("config.txt");


    cout << "Sorting Algorithm: " << config.sorting_algorithm << endl;
    cout << "Searching Algorithm: " << config.searching_algorithm << endl;
    cout << "Threshold: " << config.threshold << endl;
    Linked_list_Tickets ticket_list;
    Agent_management agent_management; 
    Stack resolution_stack; 
    Queue pending_tickets; 
    TicketResolutionLogs ticketresolutionlog;
    management_function(ticket_list, agent_management, resolution_stack, pending_tickets,ticketresolutionlog);
}
