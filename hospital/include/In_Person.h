#ifndef IN_PERSON_H
#define IN_PERSON_H
#include"Appointment.h"

class In_Person: public Appointment
{
    public:
        In_Person()
        {
            Front = Rear = NULL;
        }

    void Create(int patient_id, int doctor_id , string date )
    {
            Node_2* newNode = new Node_2(patient_id, doctor_id , date );
            cout<<"In person appointment";
            //queue is empty
            if(Front == NULL)
            {
                Front = Rear = newNode;
            }else{
                Rear->next = newNode;
                Rear = newNode;
            }
    }

    void View()
    {
            Node_2* current = Front;
            cout<<"In person appointment";
            while(current !=NULL)
            {
                cout<< current->Patient_id<<"\t";
                cout<< current->Doctor_id<<"\t";
                cout<< current->Date<<"\t";
                current = current->next;
            }
        }

    Node_2* GetFront()
    {
        if(Front !=NULL)
        return Front;
    }

    void Update(int Patient_id,string newdate)
    {
        cout<<"In person appointment";
        Node_2* current = binarySearch(Patient_id);
            if(current != NULL)
            {
                current->Date=newdate;
            }
    }

    void Cancel()
            {
                Node_2* temp = Front;
                cout<<"In person appointment";
                cout<<"in person";
                if(Front == Rear) // single Node
                {

                    Front = Rear =NULL; //queue is empty


                }else{

                    Front = Front->next;

                }

                delete temp;

            }




    private:

        Node_2* binarySearch(int id)
        {
             Node_2* start = Front;
             Node_2* endd = NULL;
              while (start >= endd)
              {
                  Node_2* mid = start;
                  for (int i = 0; i < (endd - start) / 2; ++i)
                  {
                     mid = mid->next;
                  }
                  if (mid->Patient_id == id) {return mid;}
                  else if (mid->Patient_id < id) {start = mid->next;}
                  else {endd = mid;}
              }
                return nullptr; // ID not found
             }
};

#endif // IN_PERSON_H
