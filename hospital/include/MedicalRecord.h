#ifndef MEDICALRECORD_H
#define MEDICALRECORD_H
#include <cstring>
#include "patient.h"
#include <string>
#include"NodeMedical.h"
using namespace std;


class MedicalRecord
{
    public:
     //  NodeMedical* TOP=nullptr;
       MedicalRecord()
       {
           TOP=NULL;
       }
///////////////////////////
       void create(int Id)
       {

           string patientDiagnosis;
           cout << "Enter patient diagnosis: ";
           cin>>patientDiagnosis;
           NodeMedical* newNode= new NodeMedical(Id ,patientDiagnosis);
          // cout<<"26"<<endl;
          if(TOP == NULL)//first item
           {
              TOP = newNode;
           }
           else
           {
              newNode->next=TOP;
              TOP=newNode;

           }
       }
///////////////////////////
        void view()
        {
            NodeMedical* current = TOP;
            while(current != NULL)
            {
             //   cout<< "THE Id : "<<current->id << "\n";
                cout<< "THE patient Diagnosis : "<<current->patientDiagnosis << "\n";
                current = current->next;
            }
        }
///////////////////////////
        void update(int Id,string _patientDiagnosis)
        {
            NodeMedical* Pupdate= binarySearch(Id);
            if(Pupdate != NULL)
            {
                Pupdate->patientDiagnosis=_patientDiagnosis;
            }
        }
///////////////////////////
        void Delete()
        {
            if(TOP != NULL)
            {
                NodeMedical* temp=TOP;
                TOP=TOP->next;
                delete TOP;

            }
            else
            {
                cout<<"not found";
            }
        }

    private:
       NodeMedical* TOP;

NodeMedical* binarySearch(int id)
{
    NodeMedical* start = TOP;
    NodeMedical* endd = NULL;

    while (start >= endd)
    {
        NodeMedical* mid = start;
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
};

#endif // MEDICALRECORD_H
