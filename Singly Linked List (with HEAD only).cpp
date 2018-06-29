#include <iostream>
using namespace std;


/*-------------------------List Item-------------------------*/
template <class T>
struct ListItem
{
    T value;                //Data Item
    ListItem<T> * next;     //Pointer to the next item of the List

    T getValue()
    {   
        return value;
    }
};




/*-------------------------Singly Linked List-------------------------*/
template <class T>
class List
{

private:
    ListItem<T> * head;

public:

    // Default Constructor
    List()
    {
        head = NULL;
    }



    // Copy Constructor
    List(const List<T>& otherList)
    {
        //If the other list is empty then make the current list empty too.
        if(otherList.head == NULL)
        {
            head = NULL;
        }

        //If the other List isn't empty:
        else
        {
            ListItem<T> * current1 = otherList.head;  //current1 points to the other list.

            head = new ListItem<T>;
            head -> value = current1 -> value;

            current1 = current1 -> next;

            if( current1 == NULL )
                head -> next  = NULL;

            else
            {
                ListItem<T> * current2 = head;    //current2 keeps track of the list being created.

                while(current1 != NULL)
                {
                    current2 -> next = new ListItem<T>;
                    current2 = current2 -> next;

                    current2 -> value = current1 -> value;
                    current1 = current1 -> next;
                }

                current2 -> next = NULL;
            }
        }

    }



    //Overloaded Assignment Operator
    List<T> operator = (const List<T>& otherList)
    {
        if( &otherList != this)
        {
            if (head != NULL)                   //If list isn't empty then delete the whole list.
            {
                ListItem<T> * current = head;

                while(current != NULL)
                {
                    ListItem<T> * temp = current;
                    current = current -> next;
                    delete temp;
                }

                head = NULL;
            }

            //If the other list is empty then make the current list empty too.
            if(otherList.head == NULL)
            {
                head = NULL;
            }

            //If the other List isn't empty:
            else
            {
                ListItem<T> * current1 = otherList.head;  //current1 points to the other list.

                head = new ListItem<T>;
                head -> value = current1 -> value;

                current1 = current1 -> next;

                if( current1 == NULL )
                    head -> next  = NULL;

                else
                {
                    ListItem<T> * current2 = head;    //current2 keeps track of the list being created.

                    while(current1 != NULL)
                    {
                        current2 -> next = new ListItem<T>;
                        current2 = current2 -> next;

                        current2 -> value = current1 -> value;
                        current1 = current1 -> next;
                    }

                    current2 -> next = NULL;
                }
            }

        }

        return *this;
    }



    // Destructor
    ~List()
    {
        if (head != NULL)                   //If list is empty then do nothing.
        {
            ListItem<T> * current = head;

            while(current != NULL)
            {
                ListItem<T> * temp = current;
                current = current -> next;
                delete temp;
            }
        }
    }



    /*------------------- Insertion Functions -------------------*/
    void insertAtHead(T item)
    {
        ListItem<T> * temp = new ListItem<T>;
        temp -> value = item;

        temp -> next = head;
        head = temp;
    }



    void insertAtTail(T item)
    {
        ListItem<T> * temp = new ListItem<T>;
        temp -> value = item;


        ListItem<T> * current = head;

        if(current == NULL)  //If the list is empty.
        {
            head = temp;
        }

        else
        {
            while (current -> next != NULL)  //Reach the end of the list.
            {
                current = current -> next;
            }

            current -> next = temp;
        }

        temp -> next = NULL;   //The end item of the list always points to null.
    }



    void insertSorted(T item)
    {
        ListItem<T> * temp = new ListItem<T>;
        temp -> value = item;

        ListItem<T> * current = head;
        ListItem<T> * previous = NULL;

        while(current != NULL && current -> value > item)
        {
            previous = current;
            current = current -> next;
        }

        temp -> next = current;

        if(current == head)
        {
            head = temp;
        }
        else
            previous -> next = temp;
    }



    /*------------------- Lookup Functions -------------------*/
    ListItem<T> *getHead()
    {
        return head;
    }



    ListItem<T> *getTail()
    {
        if( head == NULL)
        {
            return NULL;
        }

        else
        {
            ListItem<T> * current = head;

            while (current -> next != NULL)  //Traverses the whole list till the end is reached.
            {
                current = current -> next;
            }

            return current;
        }
    }



    ListItem<T> *searchFor(T item)
    {
        if(head == NULL)
        {
            return NULL;
        }

        else
        {
            ListItem<T> * current = head;

            while (current != NULL && current -> value >= item)
            {
                if(current -> value == item)
                {
                    return current;
                }

                current = current -> next;
            }

            return NULL;
        }
    }



    /*------------------- Deletion Functions -------------------*/

    void deleteElement(T item)
    {
        if(head != NULL) //If the list isn't empty.
        {
            ListItem<T> * current = head;
            ListItem<T> * previous = head;

            while( current -> next != NULL && current -> value > item)
            {
                previous = current;
                current = current -> next;
            }


            //If the element is found.
            if(current -> value == item)
            {
                if (current == head)
                {
                    head = head -> next;
                }

                else
                {
                    previous -> next = current -> next;
                }

                delete current;
            }
        }
    }



    void deleteHead()
    {
        if(head != NULL)
        {
            ListItem<T> * temp = head -> next;
            delete head;
            head = temp;
        }
    }



    void deleteTail()
    {
        if(head != NULL)
        {
            ListItem<T> * current  = head;
            ListItem<T> * previous = NULL;

            while (current -> next != NULL)
            {
                previous = current;
                current  = current -> next;
            }

            if(current == head)
            {
                head = NULL;
            }

            else
            {
                previous -> next = NULL;
            }

            delete current;
        }
    }



    /*------------------- Utility Functions -------------------*/
    int length()
    {
        int length = 0;
        ListItem<T> * current = head;

        while( current != NULL)
        {
            length++;
            current = current -> next;
        }

        return length;
    }



    void Print()
    {
        if(head != NULL)
        {
            ListItem<T> * current = head;

            cout << endl << "The list contains: " << endl;

            while ( current != NULL)
            {
                cout << current -> value << endl;
                current = current -> next;
            }
        }

        else
            cout << "\nList is empty.";
    }



    void displayFunctions()
    {
        cout << "\n\n\nThis class List has the following functionality : ";
        cout << "\n1)insertAtHead \n2)insertAtTail \n3)insertSorted \n4)getHead \n5)getTail"
             << "\n6)searchFor \n7)deleteElement \n8)deleteHead \n9)deleteTail \n10)Print List \n11)Length of List";
        cout << "\nEnter the option number. To exit, enter -1.\nOption Number : ";
    }



    //Overloaded + operator
    List operator + (List<T> & rhs)
    {
        ListItem<T> * current1;
        List tempList;
        //Chooses that list which is larger than the other one
        if ( length() >= rhs.length() )
        {
            tempList = *this;

            current1 = rhs.head;
        }

        else
        {
            tempList = rhs;

            current1 = head;
        }

        ListItem<T> * tempPtr = NULL;

        while(current1 != NULL)  //Current1 will always keep track of the shorter list
        {
           tempPtr = tempList.searchFor(current1 -> value);

           if (tempPtr != NULL)
           {
                tempPtr -> value = (tempPtr -> value) + (current1 -> value);
           }

           else
                tempList.insertSorted(current1 -> value);

           current1 = current1 -> next;
        }

        return tempList;
    }



    //Adds the duplicate values in a list and de-allocates the space consumed by the duplicate
    void addDuplicates()
    {
        ListItem<T>* current  = head;
        ListItem<T>* previous = NULL;

        if (current != NULL && current -> next != NULL)
        {
            while (current -> next != NULL)
            {
                previous = current;
                current  = current -> next;

                if (previous -> value == current -> value)
                {   
                    current -> value = current -> value + previous -> value;

                    deleteElement(previous -> value);
                }
            }    
        }
    }



    //Get element at the desired position, eg 3rd element of list etc
    ListItem<T>* getDesiredElement(int n)
    {
        ListItem<T>* current = head;

        if (n <= length())
        {   
            while (n != 1)
            {
                current = current -> next;
                n--;
            }
        }

        return current;
    }
};


//--------------Ended List Class---------------------










void driver()
{
    List<int> list1;

    int userInput = 0;
    int data;

    while (userInput != -1)
    {
        list1.displayFunctions();
        cin >> userInput;

        if (userInput == 1)
        {
            cout << "\nEnter the data to be inserted into the List : ";
            cin  >> data;

            list1.insertAtHead(data);
        }

        else if (userInput == 2)
        {
            cout << "\nEnter the data to be inserted into the List : ";
            cin  >> data;

            list1.insertAtTail(data);
        }

        else if (userInput == 3)
        {
            cout << "\nEnter the data to be inserted into the List : ";
            cin  >> data;

            list1.insertSorted(data);
        }

        else if (userInput == 4)
        {
            if(list1.getHead() != NULL)
                cout << "\nThe value at the head of the list is " << list1.getHead()->value;
            else
                cout << "\nThe list is empty.";
        }

        else if (userInput == 5)
        {
            if(list1.getTail() != NULL)
                cout << "\nThe value at the tail of the list is " << list1.getTail()->value;
            else
                cout << "\nThe list is empty.";
        }

        else if (userInput == 6)
        {
            cout << "\nEnter the data element which is to be searched : ";
            cin  >> data;

            if(list1.searchFor(data) != NULL)
                cout << "\nThe element is found. ";
            else
                cout << "\nThe element is not found. ";
        }

        else if (userInput == 7)
        {
            cout << "\nEnter the data to be deleted from the List : ";
            cin  >> data;

            list1.deleteElement(data);
        }

        else if (userInput == 8)
        {
            list1.deleteHead();
        }

        else if (userInput == 9)
        {
            list1.deleteTail();
        }

        else if (userInput == 10)
        {
            list1.Print();
        }

        else if (userInput == 11)
        {
            cout << "\n\nThe length of the list is : " << list1.length();
        }
    }



    cout << "\nTesting the copy constructor :";
    List<int> list2 = list1;

    cout << "\nList 2 is a copy of List 1 constructed through Copy Constructor.";
    
    cout << "\nList 1 : ";
    list1.Print();

    cout << "\nList 2 : ";
    list2.Print();
}



int main()
{
    driver();
    system ("PAUSE");
    return 0;
}