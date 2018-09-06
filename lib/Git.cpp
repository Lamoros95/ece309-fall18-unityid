#include <stdio.h>



//Holds the value of the Item or string
class Item{
    public:

        const char * str;
        Item(const char *as = ""){

            str = as;

        }
};



struct List{

private:

        //I need a Node where HEAD and TAIL are at
        class ListNode{

            private:

                Item item; //calling the first class where item is at
                ListNode *next; // Calling this class *Next

            public:

                ListNode(Item a){ // i used it to call my items

                    item = a;
                    next =NULL; //This is the TAIL!!!!
                }

                ListNode* getNext(){

                    return next;//Tail goes to the next value

                }

                void setNext(ListNode *n){ //I am getting the next value

                    next = n;

                }

                Item getItem(){

                    return item;

                }
};


    ListNode *head;//First item
    ListNode *tail;//Last Item

public:

    List();//My constructor by Default
    void push_back(Item a);
    bool remove_front(Item &a);
    bool empty();
    bool get(Item &a);
    int length(Item &a);
    ~List(){printf("List Destroyed");}
};
  List::List()
  {

  head=NULL;
  tail=NULL;


  }

        void List::push_back(Item a){

        ListNode *node = new ListNode(a);//allocates a into the object using new

        if(head==NULL){
            //This is because the list is empty
            //your head and tail are at the beggining
            head = node;
            tail = node;
        }
        else{

            tail->setNext(node);
            tail=node;

        }
        }

        bool List::remove_front(Item &copy){

            if(!empty())// if list is not empty
            {
                copy = head->getItem(); // return copy
                ListNode *tmp = head->getNext();
                delete head;            // delete the node
                head = tmp;             // update the head
                if (tmp==NULL)          // removed last element
                tail = NULL;
                printf("This is the tail item removed: %s\n",copy.str);
                return true;

            }
        return false;


        }


        bool List::empty(){

        return head==NULL;

        }

        bool List::get(Item &copy){

        copy=tail->getItem();
        printf("This is the tail item removed: %s\n",copy.str);
// or Return i; i wasnt sure if you wanted to print the number of items

        }

        int List::length(Item &copy){
        int i=0;
        while(!empty()){
            i++;
            copy = head->getItem(); // return copy
            ListNode *tmp = head->getNext();
            head = tmp;             // update the head
            if (tmp==NULL)          // removed last element
            i++;
            tail = NULL;
                   }
                   printf("there are %d items\n",i);
        }










int main()
{
  List l;

  l.push_back(Item("milk"));
  l.push_back(Item("eggs"));
  l.push_back(Item("bread"));


  //while(!l.empty())
   // {
    Item copy; //copy of the objects used to take objects out
    l.get(copy);
    l.remove_front(copy);
    l.get(copy);
    l.length(copy);
   // }

  return 0;
}
