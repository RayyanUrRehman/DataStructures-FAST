#include <algorithm>
#include<cctype>
#include <iostream>
#include <ctime>
#include <string>
#include<fstream>
#include<sstream>
#include "config.h"

using namespace std;

class tickets {
public:
    int ticketId;
    string customerName;
    int priority;
    string request;
    time_t creationTime;  
    string creationTimestr; 
    bool status;
    string closeTime;
    tickets* next;

    tickets() {}

    tickets(int id, string n, int p, string des, bool s)
        : ticketId(id), customerName(n), priority(p), request(des), status(s), next(nullptr) {
        time(&creationTime);  
        creationTimestr = ctime(&creationTime);
        closeTime = ""; 
    }
};

class LLtickets {
public:
    tickets* head;

    LLtickets() {
        head = nullptr;
    }
    bool ticketExists(int id) {
        tickets* temp = head;
        while (temp != nullptr) {
            if (temp->ticketId == id) return true;
            temp = temp->next;
        }
        return false;
    }
    void addTicket(int id, string n, int p, string req, bool status) {
        tickets* newticket = new tickets(id, n, p, req, status);
        if (head == nullptr) {
            head = newticket;
        } else {
            tickets* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newticket;
        }
        cout << "Ticket added with ID: " << newticket->ticketId << endl;
    }

    void deleteTicket(int id) {
        if (head == nullptr) {
            cout << "No tickets to delete.\n";
            return;
        }

        if (head->ticketId == id) {
            tickets* del = head;
            head = head->next;
            delete del;
            cout << "Ticket with ID " << id << " deleted.\n";
            return;
        }

        tickets* temp = head;
        while (temp->next != nullptr && temp->next->ticketId != id) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Ticket with ID " << id << " not found.\n";
        } else {
            tickets* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            cout << "Ticket with ID " << id << " deleted.\n";
        }
    }

    void searchTicket(int id) {
        tickets* temp = head;
        while (temp != nullptr) {
            if (temp->ticketId == id) {
                cout << "Ticket ID: " << temp->ticketId << endl;
                cout << "Customer Name: " << temp->customerName << endl;
                cout << "Priority: " << temp->priority << endl;
                cout << "Request Description: " << temp->request << endl;
                cout << "Creation Time: " << temp->creationTimestr;
                cout << "Status: " << (temp->status ? "Open" : "Closed") << endl;
                if (!temp->status) {
                    cout << "Close Time: " << temp->closeTime;
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Ticket with ID " << id << " not found.\n";
    }

    void display() {
        tickets* temp = head;
        if (temp == nullptr) {
            cout << "No tickets available.\n";
            return;
        }
        cout << "Displaying tickets details:\n";
        while (temp != nullptr) {
            cout << "Ticket ID: " << temp->ticketId << endl;
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Priority: " << temp->priority << endl;
            cout << "Request Description: " << temp->request << endl;
            cout << "Creation Time: " << temp->creationTimestr; 
            cout << "Status: " << (temp->status ? "Open" : "Closed") << endl;
            if (!temp->status) {
                cout << "Close Time: " << temp->closeTime;
            }
            cout << "-----------------------------\n";
            temp = temp->next;
        }
    }

    //merge Sort
tickets* Merge(tickets* a, tickets* b) {
    if (!a) return b;
    if (!b) return a;

    tickets* result;
    if (a->ticketId <= b->ticketId) {
        result = a;
        result->next = Merge(a->next, b);
    } else {
        result = b;
        result->next = Merge(a, b->next);
    }
    return result;
}

void Split(tickets* source, tickets** frontRef, tickets** backRef) {
    tickets* fast = source->next;
    tickets* slow = source;

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

void mergeSort(tickets** headRef) {
    if (!*headRef || !(*headRef)->next) return;

    tickets* a;
    tickets* b;
    Split(*headRef, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = Merge(a, b);
}


//quick sort
tickets* getTail(tickets* node) {
    while (node != nullptr && node->next != nullptr) {
        node = node->next;
    }
    return node;
}
tickets* partition(tickets* head, tickets* end, tickets** newHead, tickets** newEnd) {
    tickets* pivot = end;
    tickets *prev = nullptr, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->ticketId < pivot->ticketId) {
            if (!*newHead) *newHead = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            tickets* temp = cur->next;
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

tickets* QSRecur(tickets* head, tickets* end) {
    if (!head || head == end) return head;

    tickets *newHead = nullptr, *newEnd = nullptr;
    tickets* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        tickets* temp = newHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = nullptr;

        newHead = QSRecur(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = QSRecur(pivot->next, newEnd);
    return newHead;
}

void quickSort(tickets** headRef) {
    *headRef = QSRecur(*headRef, getTail(*headRef));
}


//selection sort
void selectionSort(tickets** headRef) {
    tickets* temp = *headRef;

    while (temp) {
        tickets* min = temp;
        tickets* r = temp->next;

        while (r) {
            if (r->ticketId < min->ticketId) min = r;
            r = r->next;
        }
        swapNodes(temp, min);
        temp = temp->next;
    }
}

void swapNodes(tickets* a, tickets* b) {
    if (a != b) {
        swap(a->ticketId, b->ticketId);
        swap(a->customerName, b->customerName);
        swap(a->priority, b->priority);
        swap(a->request, b->request);
        swap(a->creationTime, b->creationTime);
        swap(a->creationTimestr, b->creationTimestr);
        swap(a->status, b->status);
        swap(a->closeTime, b->closeTime);
    }
}

//insertion sort
void insertionSort(tickets** headRef) {
    tickets* sorted = nullptr;
    tickets* current = *headRef;

    while (current) {
        tickets* next = current->next;
        insertSorted(&sorted, current);
        current = next;
    }
    *headRef = sorted;
}

void insertSorted(tickets** headRef, tickets* newNode) {
    if (!*headRef || (*headRef)->ticketId >= newNode->ticketId) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        tickets* current = *headRef;
        while (current->next && current->next->ticketId < newNode->ticketId) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

    void timeSort() {
        if (head == nullptr) return; 

        for (tickets* temp1 = head; temp1 != nullptr; temp1 = temp1->next) {
            for (tickets* temp2 = temp1->next; temp2 != nullptr; temp2 = temp2->next) {
                if (temp1->creationTime > temp2->creationTime) {
                    tswap(temp1, temp2);
                }
            }
        }
    }

    void nameSort() {
        if (head == nullptr) return;

        for (tickets* temp1 = head; temp1 != nullptr; temp1 = temp1->next) {
            for (tickets* temp2 = temp1->next; temp2 != nullptr; temp2 = temp2->next) {
                if (temp1->customerName > temp2->customerName) {
                    tswap(temp1, temp2);
                }
            }
        }
    }

    void idSort() {
        if (head == nullptr) return;

        for (tickets* temp1 = head; temp1 != nullptr; temp1 = temp1->next) {
            for (tickets* temp2 = temp1->next; temp2 != nullptr; temp2 = temp2->next) {

                if (temp1->ticketId > temp2->ticketId) {
                    tswap(temp1, temp2);
                }
            }
        }
    }

    void tswap(tickets* a, tickets* b) {
        swap(a->ticketId, b->ticketId);
        swap(a->customerName, b->customerName);
        swap(a->priority, b->priority);
        swap(a->request, b->request);
        swap(a->creationTime, b->creationTime);
        swap(a->creationTimestr, b->creationTimestr);
        swap(a->status, b->status);
        swap(a->closeTime, b->closeTime);
    }

    void sort(int p) {
        if (p == 1) {
            timeSort();
        } else if (p == 2) {
            nameSort();
        } else if (p == 3) {
            idSort();
        }
    }
};

class Agent {
public:
    int agentId;
    string name;
    int* assignedTickets; 
    bool availability; 
    int num;              

    Agent() {}

    Agent(int id, string n) : agentId(id), name(n), availability(true), num(0) {
        assignedTickets = nullptr; 
    }

    ~Agent() {
        delete[] assignedTickets;
    }

    void assignTicket(int t_ID) {
        if (num >= 5) {
            availability = false;
            cout << "Agent " << name << " is at full capacity." << endl;
            return;
        }

        int* temp = new int[num + 1];
        for (int i = 0; i < num; i++) {
            temp[i] = assignedTickets[i];
        }

        temp[num] = t_ID;

        delete[] assignedTickets;
        assignedTickets = temp;
        num++;

        if (num >= 5) {
            availability = false;
        }

        cout << "Assigned ticket " << t_ID << " to agent " << name << endl;
    }

    int getPriorityNumber() const {
        return num;
    }
        void display() const {
        cout << "Agent ID: " << agentId << ", Name: " << name << ", Availability: " 
             << (availability ? "Available" : "Unavailable") << ", tickets Assigned: ";
        
        if (num == 0) {
            cout << "None";
        } else {
            for (int i = 0; i < num; i++) {
                cout << assignedTickets[i] << (i < num - 1 ? ", " : "");
            }
        }
        cout << endl;
    }

};

class agentManagement {
public:
    Agent* agents;  
    int agentCount; 

    agentManagement() : agentCount(0), agents(nullptr) {}

    ~agentManagement() {
        delete[] agents;
    }

    void addAgent(Agent newAgent) {
        Agent* temp = new Agent[agentCount + 1];
        for (int i = 0; i < agentCount; i++) {
            temp[i] = agents[i];
        }

        temp[agentCount] = newAgent;

        delete[] agents;
        agents = temp;
        agentCount++;

        cout << "Added agent " << newAgent.name << " (ID: " << newAgent.agentId << ")" << endl;
    }

    void assignTicketToAgent(int ticketId) {
        if (agentCount == 0) {
            cout << "No agents available to assign tickets." << endl;
            return;
        }

        int minTickets = 6; 
        int chosenAgentIndex = -1;

        for (int i = 0; i < agentCount; i++) {
            if (agents[i].availability && agents[i].getPriorityNumber() < minTickets) {
                minTickets = agents[i].getPriorityNumber();
                chosenAgentIndex = i;
            }
        }

        if (chosenAgentIndex != -1) {
            agents[chosenAgentIndex].assignTicket(ticketId);
        } else {
            cout << "No available agents to assign ticket " << ticketId << endl;
        }
    }
    void displayAllAgents() const {
        cout << "Agent Details:" << endl;
        for (int i = 0; i < agentCount; i++) {
            agents[i].display();
        }
    }
        void sortAgentsByTicketCount() {
        for (int i = 0; i < agentCount - 1; i++) {
            for (int j = 0; j < agentCount - i - 1; j++) {
                if (agents[j].getPriorityNumber() > agents[j + 1].getPriorityNumber()) {
                    Agent temp = agents[j];
                    agents[j] = agents[j + 1];
                    agents[j + 1] = temp;
                }
            }
        }
        cout << "Agents sorted by the number of assigned tickets." << endl;
    }

    void sortAgentsById() {
        for (int i = 0; i < agentCount - 1; i++) {
            for (int j = 0; j < agentCount - i - 1; j++) {
                if (agents[j].agentId > agents[j + 1].agentId) {

                    Agent temp = agents[j];
                    agents[j] = agents[j + 1];
                    agents[j + 1] = temp;
                }
            }
        }
        cout << "Agents sorted by Agent ID." << endl;
    }
        static int binarySearch(Agent* agents, int count, int agentId) {
        int left = 0;
        int right = count - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (agents[mid].agentId == agentId) {
                return mid; 
            }
            if (agents[mid].agentId < agentId) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; 
    }


    static int interpolationSearch(Agent* agents, int count, int agentId) {
        int low = 0, high = count - 1;

        while (low <= high && agentId >= agents[low].agentId && agentId <= agents[high].agentId) {
            if (low == high) {
                if (agents[low].agentId == agentId) {
                    return low; 
                }
                return -1; 
            }

            int pos = low + ((high - low) / (agents[high].agentId - agents[low].agentId) * (agentId - agents[low].agentId));

            if (agents[pos].agentId == agentId) {
                return pos;
            }

            if (agents[pos].agentId < agentId) {
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
        int ticketId;
        string resolutionDetail;
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
        Node* newNode = new Node{id, detail, top};
        top = newNode;
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
            cout << "Ticket ID: " << temp->ticketId << ", Resolution: " << temp->resolutionDetail << endl;
            temp = temp->next;
        }
    }
};

class Queue {
private:
    struct Node {
        int ticketId;
        string customerName;
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
            if (temp->ticketId == id) return temp->customerName;
            temp = temp->next;
        }
        
        return "Does not exists" ;
    }
        int returnticketpriority(int id){
      Node* temp = front;
        while (temp != nullptr) {
            if (temp->ticketId == id) return temp->priority;
            temp = temp->next;
        }
        
        return -1;
    }
    bool ticketExists(int id) {
        Node* temp = front;
        while (temp != nullptr) {
            if (temp->ticketId == id) return true;
            temp = temp->next;
        }
        return false;
    }
    void enqueue(int id) {
        Node* newNode = new Node{id};
        if (rear) {
            rear->next = newNode;
        } else {
            front = newNode; 
        }
        rear = newNode;
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
            cout << "Ticket ID: " << temp->ticketId << ", Customer: " << temp->customerName
                 << ", Priority: " << temp->priority << endl;
            temp = temp->next;
        }
    }
};

class TicketResolutionLogs {
private:

    struct StackNode {
        int ticketId;
        string resolutionDetail;
        StackNode* next;
    };

    struct QueueNode {
        int ticketId;
        string customerName;
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

    void logClosedTicket(int ticketId, const string& resolutionDetail) {
        StackNode* newNode = new StackNode{ticketId, resolutionDetail, stackTop};
        stackTop = newNode;
        cout << "Ticket " << ticketId << " resolved and added to resolution log.\n";
    }

    void addTicketToPendingQueue(int ticketId, const string& customerName, int priority) {
        QueueNode* newNode = new QueueNode{ticketId, customerName, priority, nullptr};

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
        cout << "Ticket " << ticketId << " added to pending queue with priority " << priority << ".\n";
    }

    void viewResolutionLogs() const {
        if (!stackTop) {
            cout << "No resolved tickets to display.\n";
            return;
        }

        cout << "Recent Ticket Resolutions:\n";
        StackNode* temp = stackTop;
        while (temp) {
            cout << "Ticket ID: " << temp->ticketId << ", Resolution: " << temp->resolutionDetail << endl;
            temp = temp->next;
        }
    }

    void viewPendingTickets() const {
        if (!queueFront) {
            cout << "No pending tickets.\n";
            return;
        }

        cout << "Pending tickets:\n";
        QueueNode* temp = queueFront;
        while (temp) {
            cout << "Ticket ID: " << temp->ticketId << ", Customer: " << temp->customerName
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
        cout << "Ticket " << temp->ticketId << " dequeued from pending queue.\n";
        delete temp; 
    } 
};

void managementFunction(LLtickets &ticketList, agentManagement &agentManagement, Stack &resolutionStack, Queue &pendingTickets, TicketResolutionLogs &ticketresolutionlog) {
    cout << "RAYYAN UR REHMAN\n";
    cout << "23K-0634\n";
    cout << "************************************************************************************************\n";
    cout << "________________________________________________________________________________________________\n\n";
    cout << "---------------------------------WELCOME TO ONE-STOP FAST NU---------------------------------\n";
    cout << "________________________________________________________________________________________________\n";
    int choice;
    while (true) {
        cout << "________________________________________________________________________________________________\n";
        cout << "(1). Add Ticket" << endl;
        cout << "(2). Display tickets" << endl;
        cout << "(3). Add Agent" << endl;
        cout << "(4). Assign Ticket to Agent" << endl;
        cout << "(5). Enqueue Pending Ticket" << endl;
        cout << "(6). Dequeue Pending Ticket" << endl;
        cout << "(7). Log Resolution" << endl;
        cout << "(8). Display Resolution Logs" << endl;
        cout << "(9). Display Pending tickets" << endl;
        cout << "(10). Remove tickets" << endl;
        cout << "(11). Sort by Priority (1, 2, or 3)" << endl;
        cout<<"(12) Display Agent details \n";
        cout<<"(13) Sort agents\n";
        cout<<"(14) Search agents\n";
        cout << "(0). Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int ticketId, priority;
                string customerName, requestDescription;
                cout << "Enter Ticket ID: ";
                cin >> ticketId;
                cout << "Enter Customer Name: ";
                cin >> customerName;
                cout << "Enter Request Description: ";
                cin.ignore();
                getline(cin, requestDescription);
                ticketList.addTicket(ticketId, customerName, 0, requestDescription, 1);
                cout << "Ticket " << ticketId << " added to the system.\n";
                break;
            }
            case 2:
                ticketList.display();
                break;
            case 3: {
                int agentId;
                string agentName;
                cout << "Enter Agent ID: ";
                cin >> agentId;
                cout << "Enter Agent Name: ";
                cin >> agentName;
                agentManagement.addAgent(Agent(agentId, agentName));
                break;
            }
            case 4: {
                int ticketId;
                cout << "Enter Ticket ID to assign: ";
                cin >> ticketId;
                if (ticketList.ticketExists(ticketId)) {
                    agentManagement.assignTicketToAgent(ticketId);
                    cout << "Ticket " << ticketId << " assigned to an agent.\n";
                } else {
                    cout << "No ticket with ID " << ticketId << " exists.\n\n";
                }
                break;
            }
            case 5: {

                int ticketId;
                cout << "Enter Ticket ID to enqueue: ";
                cin >> ticketId;
                if(ticketList.ticketExists(ticketId)){
                pendingTickets.enqueue(ticketId);
                string name=pendingTickets.returnticketname(ticketId);
                int p=pendingTickets.returnticketpriority(ticketId);
                ticketresolutionlog.addTicketToPendingQueue(ticketId,name,p);
                cout << "Ticket " << ticketId << " added to pending queue.\n";
                }

                break;
            }
            case 6:
            ticketresolutionlog.removeTicketFromPendingQueue();
                pendingTickets.dequeue();
                break;
            case 7: {
                int ticketId;
                string resolutionDetail;
                cout << "Enter Ticket ID for resolution: ";
                cin >> ticketId;
                cout << "Enter Resolution Detail: ";
                cin.ignore();
                getline(cin, resolutionDetail);
                if (ticketList.ticketExists(ticketId)) {
                    resolutionStack.push(ticketId, resolutionDetail);
                    ticketList.deleteTicket(ticketId);
                    cout << "Ticket " << ticketId << " resolved and logged in resolution stack.\n";
                } else {
                    cout << "Ticket with ID " << ticketId << " does not exist.\n";
                }
                break;
            }
            case 8:
                resolutionStack.display();
                break;
            case 9:
                pendingTickets.display();
                break;
            case 10: {
                int ticketId;
                cout << "Enter Ticket ID to remove: ";
                cin >> ticketId;
                if (ticketList.ticketExists(ticketId)) {
                    ticketList.deleteTicket(ticketId);
                    cout << "Ticket with ID " << ticketId << " has been removed.\n";
                } else {
                    cout << "Ticket with ID " << ticketId << " does not exist.\n";
                }
                break;
            }
            case 11: {
                int priority;
                cout << "Enter the priority level (1-3): ";
                cin >> priority;
                if (priority >= 1 && priority <= 3) {
                    ticketList.sort(priority);
                    cout << "tickets sorted by priority level " << priority << ".\n";
                } else {
                    cout << "Invalid priority number. Please enter 1, 2, or 3.\n";
                }
                break;
            }
            case 12:
        agentManagement.displayAllAgents();
            break;
            case 13:
            if(agentManagement.agentCount==0){
                cout<<"No available agents\n";
                return;
            }
            cout<<"Sort by id press (1) --Sort by ticket count press (2)\n";
            int x;
            cin>>x;
            if(x==1){
        agentManagement.sortAgentsById();
            }else{

        agentManagement.sortAgentsByTicketCount();
            }

            break;
            case 14:
                cout << "Enter ID of the agent: ";
                int agentId;
                cin >> agentId;

                cout << "Decide which searching algorithm you want to choose:" << endl;
                cout << "1. Interpolation Search" << endl;
                cout << "2. Binary Search" << endl;

                int searchChoice;
                cin >> searchChoice;
                int found;

                if (searchChoice == 1) {
                    found = agentManagement.interpolationSearch(agentManagement.agents, agentManagement.agentCount, agentId);
                } else if (searchChoice == 2) {
                    found = agentManagement.binarySearch(agentManagement.agents, agentManagement.agentCount, agentId);
                } else {
                    cout << "Invalid search choice." << endl;
                    break;
                }

                if (found != -1) {
                    cout << "Agent found: ";
                    agentManagement.agents[found].display(); // Display the found agent's details
                } else {
                    cout << "Agent with ID " << agentId << " not found." << endl;
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

void readConfig(const string& filename, string& sortingAlgo, string& searchingAlgo, int& threshold) {
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

            if (key == "sortingAlgo") {
                sortingAlgo = value;
            } else if (key == "searchingAlgo") {
                searchingAlgo = value;
            } else if (key == "threshold") {
                threshold = stoi(value);
            }
        }
    }
}


int main() {
            Config config = readConfig("config.txt");


    cout << "Sorting Algorithm: " << config.sortingAlgo << endl;
    cout << "Searching Algorithm: " << config.searchingAlgo << endl;
    cout << "Threshold: " << config.threshold << endl;
    LLtickets ticketList;
    agentManagement agentManagement; 
    Stack resolutionStack; 
    Queue pendingTickets; 
    TicketResolutionLogs ticketresolutionlog;
    managementFunction(ticketList, agentManagement, resolutionStack, pendingTickets,ticketresolutionlog);
}
