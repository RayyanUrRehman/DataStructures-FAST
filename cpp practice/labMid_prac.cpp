// q3
// #include <iostream>
// #include <cstring>
// using namespace std;

// const int ROWS = 5;
// const int COLS = 5;

// // Function to perform backtracking to search the word in the grid
// bool backtrack(char board[ROWS][COLS], string word, int row, int col, int index) {
//     // If all characters of the word have been matched
//     if (index == word.length()) {
//         return true;
//     }

//     // If out of bounds or the character doesn't match
//     if (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col] != word[index]) {
//         return false;
//     }

//     // Mark the current cell as visited by temporarily changing the character
//     char temp = board[row][col];
//     board[row][col] = '#'; // Use a special marker to denote the cell as visited

//     // Explore in all 8 possible directions
//     if (backtrack(board, word, row - 1, col, index + 1)) return true;  // Up
//     if (backtrack(board, word, row + 1, col, index + 1)) return true;  // Down
//     if (backtrack(board, word, row, col - 1, index + 1)) return true;  // Left
//     if (backtrack(board, word, row, col + 1, index + 1)) return true;  // Right
//     if (backtrack(board, word, row - 1, col - 1, index + 1)) return true;  // Up-Left Diagonal
//     if (backtrack(board, word, row - 1, col + 1, index + 1)) return true;  // Up-Right Diagonal
//     if (backtrack(board, word, row + 1, col - 1, index + 1)) return true;  // Down-Left Diagonal
//     if (backtrack(board, word, row + 1, col + 1, index + 1)) return true;  // Down-Right Diagonal

//     // Backtrack: undo the marking of the cell
//     board[row][col] = temp;
//     return false;
// }

// // Main function to search how many times the word appears in the board
// int exist(char board[ROWS][COLS], string word) {
//     int count = 0;
//     // Start searching from every cell in the grid
//     for (int i = 0; i < ROWS; i++) {
//         for (int j = 0; j < COLS; j++) {
//             // For each cell, if a valid match is found, increment the counter
//             if (backtrack(board, word, i, j, 0)) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// int main() {
//     // Example word search grid
//     char board[ROWS][COLS] = {
//         {'G', 'R', 'O', 'O', 'T'},
//         {'B', 'A', 'R', 'R', 'O'},
//         {'W', 'R', 'D', 'B', 'S'},
//         {'R', 'A', 'D', 'A', 'R'},
//         {'W', 'E', 'S', 'T', 'G'}
//     };

//     string word;
//     cout << "Enter the word to search: ";
//     cin >> word;

//     // Check how many times the word exists in the board
//     int occurrences = exist(board, word);
//     if (occurrences > 0) {
//         cout << "The word '" << word << "' was found " << occurrences << " times in the grid!" << endl;
//     } else {
//         cout << "The word '" << word << "' was not found in the grid." << endl;
//     }

//     return 0;
// }


// 


// q2
// #include <iostream>
// #include<string>
// using namespace std;
// template <typename T> struct Node {
//   T v;
//   Node *nxt;
//   Node *prv;
//   Node(T v) : v(v){};
// };

// template <typename T> class LL {

// public:
//   Node<T> *head;
//   Node<T> *tail;

//   LL() { head = tail = NULL; }
//   void insertTail(T v) {
//     Node<T> *nw = new Node<T>(v);
//     if (!head)
//       tail = head = nw;
//     else {
//       tail->nxt = nw;
//       nw->prv = tail;
//       tail = nw;
//     }
//   }

//   void insertHead(T v) {
//     if (!head) {
//       insertTail(v);
//       return;
//     }
//     Node<T> *nw = new Node<T>(v);
//     head->prv = nw;
//     nw->nxt = head;
//     head = nw;
//   }
//   void deleteHead() {
//     Node<T> *tmp = head;
//     head = head->nxt;
//     delete tmp;
//   }
//   T peekT() { return tail->v; }
//   T peekH() { return head->v; };
// };

// template <typename T> class Stack {
//   LL<T> s;

// public:
//   void push(T v) { s.insertHead(v); }
//   T pop() {
//     T v = s.peekH();
//     s.deleteHead();
//     return v;
//   }
//   T top() { return s.peekH(); }
//   bool isEmpty() { return s.head == NULL; }
// };

// bool isNum(string s) { return s[0] >= '0' && s[0] <= '9'; }

// bool isOp(string s) { return s == "+" || s == "-" || s == "*" || s == "/"; }

// int persidence(char op) {
//   // According to EDMAS
//   switch (op) {
//   case '/':
//     return 3;
//     break;
//   case '*':
//     return 2;
//   case '+':
//     return 1;
//   case '-':
//     return 0;
//   }

//   return 0;
// }

// int evalVals(string op, int v1, int v2) {
//   if (op[0] == '+')
//     return v1 + v2;
//   else if (op[0] == '-')
//     return v1 - v2;
//   else if (op[0] == '*')
//     return v1 * v2;
//   return v1 / v2;
// }

// int processExp(Node<string> *expH) {
//   Stack<string> vals;
//   Stack<string> ops;

//   Node<string> *cur = expH;


//   while (cur) {
//     string item = cur->v;
//     if (isNum(item)) {
//       vals.push(item);
//     } else if (isOp(item)) {
//       // Do Item evaluation
//       // cout << vals.top() << " ";
//       // cout << ops.top() << " ";
//       while (!ops.isEmpty() &&
//              persidence(item[0]) <= persidence(ops.top()[0])) {
//         // Process the things with in the stacks
//         string v2 = vals.pop();
//         string v1 = vals.pop();
//         string op = ops.pop();
//         string res = to_string(evalVals(op, stoi(v1), stoi(v2)));
//         vals.push(res);
//       }
//       ops.push(item);
//     } else if (item[0] == '(') {
//       vals.push(to_string(processExp(cur->nxt)));
//       while (cur->v[0] != ')')
//         cur = cur->nxt;
//     } else if (item[0] == ')') {
//       break;
//     }
//     // cout << item << " ";
//     cur = cur->nxt;
//   }


//   // return 0;

//   while (!ops.isEmpty()) {
//     string v2 = vals.pop();
//     string v1 = vals.pop();
//     string op = ops.pop();
//     string res = to_string(evalVals(op, stoi(v1), stoi(v2)));
//     vals.push(res);
//   }
//   if (vals.isEmpty())
//     throw "No Value";
//   return stoi(vals.pop());
// }

// int processLists(LL<string> *a, int n) {
//   int ans = 0;
//   for (int i = 0; i < n; i++) {
//     ans += processExp(a[i].head);
//   }

//   return ans;
// }

// int main(int argc, char *argv[]) {
//   // int test[] = {1, 2, 3, 4, 5, 6, 7};
//   // int n = sizeof(test) / sizeof(int);
//   // Stack<int> sTest;
//   // for (int i = 0; i < n; i++) {
//   //   sTest.push(test[i]);
//   // }
//   cout << "Enter za Nodes" << endl;
//   int n;
//   cin >> n;
//   LL<string> exp[2];
//   for (int i = 0; i < n; i++) {
//     int m;
//     cout << "Size of linked list " << i + 1 << endl;
//     cin >> m;
//     for (int j = 0; j < m; j++) {
//       string s;
//       cin >> s;
//       exp[i].insertTail(s);
//     }
//   }
//   cout << processLists(exp, n) << endl;
//   return 0;
// }
