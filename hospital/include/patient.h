#ifndef PATIENT_H
#define PATIENT_H
#include"MedicalRecord.h"
#include"Node.h"
using namespace std;

class patient
{
    private:
    Node* TOP;

Node* binarySearch(int id)
{
    Node* start = TOP;
    Node* endd = NULL;

    while (start >= endd)
    {
        Node* mid = start;
        for (int i = 0; i < (endd - start) / 2; ++i)
        {
            mid = mid->next;
        }
        if (mid->id == id) {
            return mid;
        } else if (mid->id < id) {
            start = mid->next;
        } else {
            endd = mid;
        }
    }
    return nullptr; // ID not found
}

    protected:
    MedicalRecord* med ;

    public:

        patient()
        {
             TOP=NULL;
              med = new MedicalRecord();
        }



//////////////////////////
        void Register(int id ,string name,int age)
        {
           Node* newNode = new Node(id,name,age);

           if(TOP == NULL)//first item
           {
              TOP = newNode;
           }
           else
           {
              newNode->next=TOP;
              TOP=newNode;
           }
           cout<<" If you want to make a medical record, enter 'yes':  ";
           string x;
           cin>>x;
           if(x=="yes")
           {
               med->create(id);
           }
           else
           {
               cout<<"thak you :)";
           }

        }
///////////////////////////

void displayMedical()
{
    med->view();
}
///////////////////////////
        void view()
        {
            Node* current = TOP;
            while(current != NULL)
            {
                cout<< "THE Id : "<<current->id << "\n";
                cout<< "THE Name : "<<current->name << "\n";
                cout<< "THE Age : "<<current->age << "\n";
                current = current->next;
            }
        }
///////////////////////////
        void update(int Id,int _age)
        {
            Node* Pupdate= binarySearch(Id);
            if(Pupdate != NULL)
            {
                Pupdate->age=_age;
            }
        }

///////////////////////////
        void Delete()
        {
            if(TOP != NULL)
            {
                Node* temp=TOP;
                TOP=TOP->next;
                delete TOP;

            }
            else
            {
                cout<<"not found";
            }
        }

        void FindPatient(int Id)
        {
          Node* Find = binarySearch(Id);
          cout<<"THE Name : "<<Find->name<< "\n";
          cout<<"THE Age : "<<Find->age<< "\n";
          cout<<"THE Id : "<<Find->id<< "\n";
        }


};

#endif // PATIENT_H
