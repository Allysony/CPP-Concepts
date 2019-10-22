#include <iostream>

struct Node
{
Node(int v, Node * n) : value(v), next(n) {}
int value;
Node * next;
};

bool subsetSum(Node * front, int target)
{
  if (target == 0){ // If the target is zero, then the empty set is trivially what we want. Return true
    return true;
  }
  if (front == nullptr){ // If the target is NOT zero, but the front pointer is nullptr, there is no subset of the empty set that
                          //adds to anything other than zero. Return false.
    return false;
  }
  else if (front -> value == target){
    return true;
  }

  // Otherwise, either the front is included in a subset or it isn’t.
  // In other words, we should return true if at least one of the following is true:
  else{
    return (subsetSum(front -> next, target) || subsetSum(front -> next, target - front -> value));
  }
}

int main() {
  Node *x = new Node(3, nullptr);
  x->next = new Node(4, nullptr);
  x->next = new Node(5, nullptr);
  

 
  if( subsetSum(x, 4 )){
    return 0;
  }


}
