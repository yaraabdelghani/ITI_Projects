#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include"patient.h"
#include"Doctor.h"
#include "Node_2.h"
using namespace std;

class Appointment
{
    private:
    public:
        Node_2* Front;
        Node_2* Rear;
    Appointment(){}

   virtual void Create(int patient_id, int doctor_id , string date){cout<<"app";}
   virtual void Update(int Patient_id,string newdate){cout<<"app";}
   virtual void View(){cout<<"app";}
   virtual void Cancel(){cout<<"app";}


};
#endif // APPOINTMENT_H

