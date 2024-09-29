#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <conio.h>
#include "Appointment.h"
#include "patient.h"
#include "Doctor.h"
#include"Nurse.h"
#include "Staff.h"
#include"Online.h"
#include"In_Person.h"
#include"Appointment.h"
using namespace std;

///////////////////////////////////////////////

void gotoxy(int x,int y)
{
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}
Appointment* app;
Online online ;
In_Person person;

void manageDoctors()
{
    int quit_flage = 0 ;
    string Menu[5] = {"Register" , "Update" ,"DisplayAllDoctors" , "Delete" , "Exit"} ;
    int current_item = 0 ;
    char c ;
    Doctor doc(100);


    do{
            textattr(15) ;
            system("cls") ;
            ////////////
            for(int i = 0 ; i < 5 ; i++)
            {
                if(current_item == i){
                    textattr(117) ;
                }
                else{
                   textattr(15) ;
                }


                gotoxy(0 , i) ;
                cout<< Menu[i] ;
            }

            ////////
            c = getch() ;
            switch(c){
                case -32 :{
                    c = getch() ;
                      switch(c)
                      {
                       case 72 :
                       {
                            if(current_item == 0)
                            {
                                    current_item = 4 ;
                            }
                            else
                            {
                                current_item-- ;
                            }
                            break ;
                        }
                       case 80 :
                       {
                            if(current_item == 4)
                            {
                                    current_item = 0 ;
                            }
                            else
                            {
                                current_item++ ;
                            }
                            break ;
                        }
                       case 73 :
                       {
                            current_item = 0 ;
                            break ;
                        }
                       case 81 :
                       {
                            current_item = 4 ;
                            break ;
                        }

                      }
                   break;
                   }


                case 13 : {

                    system("cls") ;

                    switch(current_item)
                    {
                        case 0 :
                        {
                            int id , x ;
                            string name ;
                            printf("Register \n") ;
                            cout<<"Enter ID :";
                            cin>>id;
                            cout<<"Enter Age :";
                            cin>>x;
                            cout<<"Enter Name :";
                            cin>>name;

                            Doctor* ptr=new Doctor(id,name,x,"DOC");
                            doc.Register(ptr);
                            break ;
                        }

                        case 1 :
                        {
                            printf("Update \n") ;
                            doc.Update();
                            break ;
                        }

                        case 2 :
                        {
                            printf("DisplayAllDoctors \n") ;
                            doc.DisplayAllDoctors();

                            break ;
                        }

                        case 3 :
                        {
                            printf("Delete\n") ;
                            doc.Delete();
                            break ;
                        }

                        case 4 :
                        {
                            quit_flage = 1 ;
                            break ;
                        }

                    }

                    getch() ;
                    break;
                }


                case 27 : {
                    quit_flage = 1 ;
                    break;
                }
            }

      }while(quit_flage == 0) ;
}
void manageNurse()
{
    int quit_flage = 0 ;
    string Menu[5] = {"Register" , "Update" ,"DisplayAllNurses" , "Delete" , "Exit"} ;
    int current_item = 0 ;
    char c ;
    Nurse Nur(200);


    do{
            textattr(15) ;
            system("cls") ;
            ////////////
            for(int i = 0 ; i < 5 ; i++)
            {
                if(current_item == i){
                    textattr(117) ;
                }
                else{
                   textattr(15) ;
                }


                gotoxy(0 , i) ;
                cout<< Menu[i] ;
            }

            ////////
            c = getch() ;
            switch(c){
                case -32 :{
                    c = getch() ;
                      switch(c)
                      {
                       case 72 :
                       {
                            if(current_item == 0)
                            {
                                    current_item = 4 ;
                            }
                            else
                            {
                                current_item-- ;
                            }
                            break ;
                        }
                       case 80 :
                       {
                            if(current_item == 4)
                            {
                                    current_item = 0 ;
                            }
                            else
                            {
                                current_item++ ;
                            }
                            break ;
                        }
                       case 73 :
                       {
                            current_item = 0 ;
                            break ;
                        }
                       case 81 :
                       {
                            current_item = 4 ;
                            break ;
                        }

                      }
                   break;
                   }


                case 13 : {//ENTER KEY

                    system("cls") ;

                    switch(current_item)
                    {
                        case 0 :
                        {
                            int id , x ;
                            string name ;
                            printf("Register \n") ;
                            cout<<"Enter ID :";
                            cin>>id;
                            cout<<"Enter Age :";
                            cin>>x;
                            cout<<"Enter Name :";
                            cin>>name;

                            Nurse* ptr=new Nurse(id,name,x,"NUR");
                            Nur.Register(ptr);
                            break ;
                        }

                        case 1 :
                        {
                            printf("Update \n") ;
                            Nur.Update();
                            break ;
                        }

                        case 2 :
                        {
                            printf("DisplayAllDoctors \n") ;
                            Nur.DisplayAllNurse();

                            break ;
                        }

                        case 3 :
                        {
                            printf("Delete\n") ;
                            Nur.Delete();
                            break ;
                        }

                        case 4 :
                        {
                            quit_flage = 1 ;
                            break ;
                        }

                    }

                    getch() ;
                    break;
                }


                case 27 : {
                    quit_flage = 1 ;
                    break;
                }
            }

      }while(quit_flage == 0) ;
}
void ManagePatients()
{
    int quit_flage = 0 ;
    string Menu[6] = {"Register" ,"update", "view" , "Find Patient by ID" ,"Delete" , "Exit"} ;
    int current_item = 0 ;
    char c ;
    patient patient1;


    do{
            textattr(15) ;
            system("cls") ;
            ////////////
            for(int i = 0 ; i < 6 ; i++)
            {
                if(current_item == i){
                    textattr(117) ;
                }
                else{
                   textattr(15) ;
                }


                gotoxy(0 , i) ;
                cout<< Menu[i] ;
            }

            ////////
            c = getch() ;
            switch(c){
                case -32 :{
                    c = getch() ;
                      switch(c)
                      {
                       case 72 :
                       {
                            if(current_item == 0)
                            {
                                    current_item = 4 ;
                            }
                            else
                            {
                                current_item-- ;
                            }
                            break ;
                        }
                       case 80 :
                       {
                            if(current_item == 4)
                            {
                                    current_item = 0 ;
                            }
                            else
                            {
                                current_item++ ;
                            }
                            break ;
                        }
                       case 73 :
                       {
                            current_item = 0 ;
                            break ;
                        }
                       case 81 :
                       {
                            current_item = 4 ;
                            break ;
                        }

                      }
                   break;
                   }


                case 13 : {

                    system("cls") ;

                    switch(current_item)
                    {
                        case 0 :
                        {
                            int id , x ;
                            string name ;
                            printf("Register \n") ;
                            cout<<"Enter ID :";
                            cin>>id;
                            cout<<"Enter Age :";
                            cin>>x;
                            cout<<"Enter Name :";
                            cin>>name;
                            patient1.Register(id,name,x);

                            break ;
                        }

                        case 1 :
                        {
                            int id , x ;
                            cout<<"Enter ID :";
                            cin>>id;
                            cout<<"Enter New Age :";
                            cin>>x;
                            printf("update \n") ;
                            patient1.update(id,x);
                            break ;
                        }

                        case 2 :
                        {
                            printf("View \n") ;
                            patient1.view();
                            patient1.displayMedical();
                            break ;
                        }

                        case 3 :
                        {
                            int id;
                            cout<<"Enter ID :";
                            cin>>id;
                            printf("Find Patient by ID \n") ;
                            patient1.FindPatient(id);
                            break ;
                        }
                        case 4 :
                        {
                            printf("Delete\n") ;
                            patient1.Delete();
                            break ;
                        }
                        case 5 :
                        {
                            quit_flage = 1 ;
                            break ;
                        }

                    }

                    getch() ;
                    break;
                }


                case 27 : {
                    quit_flage = 1 ;
                    break;
                }
            }

      }while(quit_flage == 0) ;
}
void Online()
{

    app=&online;
    int quit_flage = 0 ;
    string Menu[5] = {"Create" , "View" ,"Update" , "Cancel" , "Exit"} ;
    int current_item = 0 ;
    char c ;




    do{
            textattr(15) ;
            system("cls") ;
            ////////////
            for(int i = 0 ; i < 5 ; i++)
            {
                if(current_item == i){
                    textattr(117) ;
                }
                else{
                   textattr(15) ;
                }


                gotoxy(0 , i) ;
                cout<< Menu[i] ;
            }

            ////////
            c = getch() ;
            switch(c){
                case -32 :{
                    c = getch() ;
                      switch(c)
                      {
                       case 72 :
                       {
                            if(current_item == 0)
                            {
                                    current_item = 4 ;
                            }
                            else
                            {
                                current_item-- ;
                            }
                            break ;
                        }
                       case 80 :
                       {
                            if(current_item == 4)
                            {
                                    current_item = 0 ;
                            }
                            else
                            {
                                current_item++ ;
                            }
                            break ;
                        }
                       case 73 :
                       {
                            current_item = 0 ;
                            break ;
                        }
                       case 81 :
                       {
                            current_item = 4 ;
                            break ;
                        }

                      }
                   break;
                   }


                case 13 : {

                    system("cls") ;

                    switch(current_item)
                    {
                        case 0 :
                        {
                            int id , x ;
                            string Date ;

                            printf("Create \n") ;
                            cout<<"Enter your ID :";
                            cin>>id;
                            cout<<"Enter Doctor ID :";
                            cin>>x;
                            cout<<"Enter Appointment Date :";
                            cin>>Date;
                            app->Create(id,x,Date);

                            break ;
                        }

                        case 1 :
                        {
                            printf("View\n") ;
                            app->View();
                            break ;
                        }

                        case 2 :
                        {
                            int id;
                            string newDate;
                            printf("Update \n") ;
                            cout<<"Enter your ID :";
                            cin>>id;
                            cout<<"Enter Appointment Date :";
                            cin>>newDate;
                            app->Update(id ,newDate);
                            break ;
                        }

                        case 3 :
                        {
                            printf("Cancel\n") ;
                            app->Cancel();
                            break ;
                        }

                        case 4 :
                        {
                            quit_flage = 1 ;
                            break ;
                        }

                    }

                    getch() ;
                    break;
                }


                case 27 : {
                    quit_flage = 1 ;
                    break;
                }
            }

      }while(quit_flage == 0) ;
}
void In_Person()
{
    app=&person;
    int quit_flage = 0 ;
    string Menu[5] = {"Create" , "View" ,"Update" , "Cancel" , "Exit"} ;
    int current_item = 0 ;
    char c ;




    do{
            textattr(15) ;
            system("cls") ;
            ////////////
            for(int i = 0 ; i < 5 ; i++)
            {
                if(current_item == i){
                    textattr(117) ;
                }
                else{
                   textattr(15) ;
                }


                gotoxy(0 , i) ;
                cout<< Menu[i] ;
            }

            ////////
            c = getch() ;
            switch(c){
                case -32 :{
                    c = getch() ;
                      switch(c)
                      {
                       case 72 :
                       {
                            if(current_item == 0)
                            {
                                    current_item = 4 ;
                            }
                            else
                            {
                                current_item-- ;
                            }
                            break ;
                        }
                       case 80 :
                       {
                            if(current_item == 4)
                            {
                                    current_item = 0 ;
                            }
                            else
                            {
                                current_item++ ;
                            }
                            break ;
                        }
                       case 73 :
                       {
                            current_item = 0 ;
                            break ;
                        }
                       case 81 :
                       {
                            current_item = 4 ;
                            break ;
                        }

                      }
                   break;
                   }


                case 13 : {

                    system("cls") ;

                    switch(current_item)
                    {
                        case 0 :
                        {
                            int id , x ;
                            string Date ;

                            printf("Create \n") ;
                            cout<<"Enter your ID :";
                            cin>>id;
                            cout<<"Enter Doctor ID :";
                            cin>>x;
                            cout<<"Enter Appointment Date :";
                            cin>>Date;
                            app->Create(id,x,Date);

                            break ;
                        }

                        case 1 :
                        {
                            printf("View\n") ;
                            app->View();
                            break ;
                        }

                        case 2 :
                        {
                            int id;
                            string newDate;
                            printf("Update \n") ;
                            cout<<"Enter your ID :";
                            cin>>id;
                            cout<<"Enter Appointment Date :";
                            cin>>newDate;
                            app->Update(id ,newDate);
                            break ;
                        }

                        case 3 :
                        {
                            printf("Cancel\n") ;
                            app->Cancel();
                            break ;
                        }

                        case 4 :
                        {
                            quit_flage = 1 ;
                            break ;
                        }

                    }

                    getch() ;
                    break;
                }


                case 27 : {
                    quit_flage = 1 ;
                    break;
                }
            }

      }while(quit_flage == 0) ;
}
void ManageAppointments()
{
    int quit_flage = 0 ;
    string Menu[2] = {"Online" , "In_Person" } ;
    int current_item = 0 ;
    char c ;



    do{
            textattr(15) ;
            system("cls") ;
            ////////////
            for(int i = 0 ; i < 2 ; i++)
            {
                if(current_item == i){
                    textattr(117) ;
                }
                else{
                   textattr(15) ;
                }


                gotoxy(0 , i) ;
                cout<< Menu[i] ;
            }

            ////////
            c = getch() ;
            switch(c){
                case -32 :{
                    c = getch() ;
                      switch(c)
                      {
                       case 72 :
                       {
                            if(current_item == 0)
                            {
                                    current_item = 2 ;
                            }
                            else
                            {
                                current_item-- ;
                            }
                            break ;
                        }
                       case 80 :
                       {
                            if(current_item == 2)
                            {
                                    current_item = 0 ;
                            }
                            else
                            {
                                current_item++ ;
                            }
                            break ;
                        }
                       case 73 :
                       {
                            current_item = 0 ;
                            break ;
                        }
                       case 81 :
                       {
                            current_item = 2 ;
                            break ;
                        }

                      }
                   break;
                   }


                case 13 : {

                    system("cls") ;

                    switch(current_item)
                    {
                        case 0 :
                        {
                            printf("Online \n") ;
                            Online();

                            break ;
                        }

                        case 1 :
                        {
                            printf("In_Person \n") ;
                            In_Person();
                            break ;
                        }

                        case 2 :
                        {
                            quit_flage = 1 ;
                            break ;
                        }

                    }

                    getch() ;
                    break;
                }


                case 27 : {
                    quit_flage = 1 ;
                    break;
                }
            }

      }while(quit_flage == 0) ;
}

void medicalRecord()
{
    int quit_flage = 0 ;
    string Menu[5] = {"create" , "Update" ,"Display" , "Delete" , "Exit"} ;
    int current_item = 0 ;
    char c ;
    MedicalRecord medical;

    do{
            textattr(15) ;
            system("cls") ;
            ////////////
            for(int i = 0 ; i < 5 ; i++)
            {
                if(current_item == i){
                    textattr(117) ;
                }
                else{
                   textattr(15) ;
                }


                gotoxy(0 , i) ;
                cout<< Menu[i] ;
            }

            ////////
            c = getch() ;
            switch(c){
                case -32 :{
                    c = getch() ;
                      switch(c)
                      {
                       case 72 :
                       {
                            if(current_item == 0)
                            {
                                    current_item = 4 ;
                            }
                            else
                            {
                                current_item-- ;
                            }
                            break ;
                        }
                       case 80 :
                       {
                            if(current_item == 4)
                            {
                                    current_item = 0 ;
                            }
                            else
                            {
                                current_item++ ;
                            }
                            break ;
                        }
                       case 73 :
                       {
                            current_item = 0 ;
                            break ;
                        }
                       case 81 :
                       {
                            current_item = 4 ;
                            break ;
                        }

                      }
                   break;
                   }


                case 13 : {//ENTER KEY

                    system("cls") ;

                    switch(current_item)
                    {
                        case 0 :
                        {
                            int id ;
                            cout<<"Enter ID :";
                            cin>>id;
                            medical.create(id);
                            break ;
                        }

                        case 1 :
                        {
                            string patientDiagnosis;
                            int id;
                            printf("Update \n") ;
                            cout<<"Enter ID :";
                            cin>>id;
                            cout << "Enter patient diagnosis: ";
                            cin>>patientDiagnosis;
                            medical.update(id ,patientDiagnosis);
                            break ;
                        }

                        case 2 :
                        {
                            printf("Display \n") ;
                            medical.view();

                            break ;
                        }

                        case 3 :
                        {
                            printf("Delete\n") ;
                            medical.Delete();
                            break ;
                        }

                        case 4 :
                        {
                            quit_flage = 1 ;
                            break ;
                        }

                    }

                    getch() ;
                    break;
                }


                case 27 : {
                    quit_flage = 1 ;
                    break;
                }
            }

      }while(quit_flage == 0) ;
}

int main()
{
    int quit_flage = 0 ;
    string Menu[6] = {"Manage Doctors" ,"Manage Nurse", "Manage Patients" ,"Manage Appointments" , "Manage Medical Records" , "Exit"} ;
    int current_item = 0 ;
    char c ;



    do{
            textattr(15) ;
            system("cls") ;
            ////////////
            for(int i = 0 ; i < 6 ; i++)
            {
                if(current_item == i){
                    textattr(117) ;
                }
                else{
                   textattr(15) ;
                }


                gotoxy(0 , i) ;
                cout<< Menu[i] ;
            }

            ////////
            c = getch() ;
            switch(c){
                case -32 :{
                    c = getch() ;
                      switch(c)
                      {
                       case 72 :  // Arrow up
                       {
                            if(current_item == 0)
                            {
                                    current_item = 5 ;
                            }
                            else
                            {
                                current_item-- ;
                            }
                            break ;
                        }
                       case 80 : // Arrow down
                       {
                            if(current_item == 5)
                            {
                                    current_item = 0 ;
                            }
                            else
                            {
                                current_item++ ;
                            }
                            break ;
                        }
                       case 73 :// Page up
                       {
                            current_item = 0 ;
                            break ;
                        }
                       case 81 :// Page down
                       {
                            current_item = 5 ;
                            break ;
                        }

                      }
                   break;
                   }


                case 13 :// Enter key
                    {

                    system("cls") ;

                    switch(current_item)
                    {
                        case 0 :
                        {
                            printf("Manage Doctors \n") ;
                            manageDoctors();

                            break ;
                        }
                        case 1 :
                        {
                            printf("Manage Nurse \n") ;
                            manageNurse();
                            break ;
                        }

                        case 2 :
                        {
                            printf("Manage Patients \n") ;
                            ManagePatients();
                            break ;
                        }

                        case 3 :
                        {
                            printf("Manage Appointments \n") ;
                            ManageAppointments();
                            break ;
                        }

                        case 4 :
                        {
                            printf("Manage Medical Records\n") ;
                            medicalRecord();
                            break ;
                        }

                        case 5 :
                        {
                            quit_flage = 1 ;
                            break ;
                        }

                    }

                    getch() ;
                    break;
                }


                case 27 : {
                    quit_flage = 1 ;
                    break;
                }
            }

      }while(quit_flage == 0) ;

    return 0;
}



