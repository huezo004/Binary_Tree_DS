
#include "bet.h"
BET::BET(){
  Root = NULL;
}

BET::BET(string expression){
  Root=NULL;
  buildFromPostfix(expression); 
}
void BET::printPostfixExpression(Node* Root){  
  if(Root== NULL) return;
   printPostfixExpression(Root->Left);    
   printPostfixExpression(Root->Right); 
   cout<<Root->data; 
}
void BET::printPostfixExpression(){
 printPostfixExpression(Root); 
}

size_t BET::size(Node* Root){
  int counter=0; 
  if(Root != NULL)
  counter= 1 + size(Root->Left)+ size(Root->Right);  
  return counter;  
}
size_t BET::size(){
  size(Root);
}
size_t BET::leaf_nodes(Node *Root){
  if(Root ==NULL)return 0;
  if(Root->Right==NULL && Root->Left== NULL)
    return 1;
    return leaf_nodes(Root->Right)+ leaf_nodes(Root->Left); 
}
size_t BET::leaf_nodes(){
  leaf_nodes(Root);   
}
bool BET::empty(){
  if(Root==NULL)
    return true;
    return false;
}
void BET:: makeEmpty(Node*& Root){
  if(Root!=NULL){
    makeEmpty(Root->Left);
    makeEmpty(Root->Right);
    delete Root; 
  }
  Root = NULL; 
}

BET::~BET(){
makeEmpty(Root); 
}

BET::Node* BET::clone(Node* t)const{
  if(t==NULL)
    return NULL;
  else
   return new Node(t->data, clone(t->Right),clone(t->Left));		  
}

const BET& BET:: operator=(const BET &tree){
    makeEmpty(Root);
    Root =  clone(tree.Root);
}

BET::BET(const BET& tree){
  Root= clone(tree.Root); 
}


bool BET:: buildFromPostfix(const string expression){  
  //remove is not empty!
    if(Root!= NULL)
      makeEmpty(Root);   
   
  stack<Node*>Stc;
  string token;
  istringstream o(expression);
  while(o >> token){
  if (!(token == "+"|| token == "-"||token =="*"||token == "/")){ // manipulation of operands          
      Node *Onew = new Node(token);
      Stc.push(Onew);
  }//end if(!o)                                                                                        
  if(token == "+"|| token == "-"||token =="*"||token == "/"){ // manipulation of operators              
    //Cheking for errors
    // operator does not have operands: 
    // check is stack has at least 2 elements(shouldnt create operator if stack
    // has less than 2     
    if(Stc.size()< 2){ 
      cout<< " wrong infix expression"; 
      return false;
     
    }
   //if no error in operator 
    Node *op = new Node(token);
    Node *Ri =Stc.top();
    Stc.pop();
    Node *Le =Stc.top();
    Stc.pop();
    op->Right=Ri;
    op->Left=Le;
    Stc.push(op);
  }// end if(o)
  }//end of while                                                                                          
//operand error check:
// at the end if stack is not empty and size > 1    
  if(Stc.size() > 1){
    cout<<"wrong infix expression"; 
  return false;

  }
  else {
 Root=Stc.top();
 Stc.pop();
 Stc.push(Root);
  return true;
  }//end else 
} //end function                   

void BET::printInfixExpression(Node* T){

  if(T->Left != NULL)
    {
      printInfixExpression(T->Left);
    }
  cout << T->data; 

  if(T->Right != NULL)
    {
      printInfixExpression(T->Right);
    }
}

void BET::printInfixExpression(){
  printInfixExpression(Root); 
} 
