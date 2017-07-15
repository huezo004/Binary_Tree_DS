#include <stack>
#include <iostream> 
#include <sstream>
#include <string>
using namespace std; 
class BET{
 public:
   BET();
   BET(string);
   BET(const BET& tree); 
   size_t size(); 
   size_t leaf_nodes();
   bool empty(); 
   ~BET();
   const BET& operator=(const BET & n); 
   bool buildFromPostfix(const string postfix);
   void printPostfixExpression();   
   void printInfixExpression();
 private:   
 struct Node{
    string data; 
    Node *Right; 
    Node *Left;
 Node(string d, Node *r=NULL, Node *l=NULL):data(d), Right(r), Left(l){}
  };

  Node* Root; 
  size_t size(Node *n);
  size_t leaf_nodes(Node *n); 
  void makeEmpty(Node *&n); 
  Node* clone(Node *t)const;
  void printInfixExpression(Node *T);
  void printPostfixExpression(Node *T);   
};



