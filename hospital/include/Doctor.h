#ifndef DOCTOR_H
#define DOCTOR_H
#include "Staff.h"
#include <iostream>
using namespace std;


class Doctor : public Staff
{
    public:

        Doctor(int Size){
            this->index = 0 ;
            this->arr_size = Size ;  //size of array
            this->ptr = new Doctor*[arr_size] ;  //memory allocate for array
        }


        Doctor(int Id , string Name , int Age , string specialty):Staff(Id , Name , Age , "Doctor") {

        }

        ~Doctor(){
            delete []ptr ; // free memory allocated for the array
        }


        int updateId(){
            int id ;
            cout << "Enter The Id of Doctor : " ;
            cin >> id ;
            return id ;
        }


        string updateName(){
            string name ;
            cout << "Enter The Name of Doctor : " ;
            cin >> name ;
            return name ;
        }


        int updateAge(){
            int age ;
            cout << "Enter The Age of Doctor : " ;
            cin >> age ;
            return age ;
        }


        void Register(Doctor* D) {
        if (index < arr_size) {
            this->ptr[index] = D ; //set the new doctor in the array
            index++;
        } else {
            cout << "Array is full, cannot add more doctors." << endl;
        }
    }


        void Update(){
            int i = LinearSearch() ;
            if(i != -1){
                cout << "Enter 0 to update the id or 1 to update the name 2 to update the age : " ;
                int x ;
                cin >> x ;
                if(x == 0){
                    ptr[i]->Id = updateId();
                }
                else if(x == 1){
                    ptr[i]->Name = updateName();
                }
                else if(x == 2){
                    ptr[i]->Age = updateAge();
                }
                else{
                    cout << "You entered not valid value" ;
                }
            }
            else{
                cout << "Invalid Id" ;
            }
        }


        void Delete(){
            int i = LinearSearch() ;
            if(i != -1){
                delete ptr[i] ;
                for(int j = i ; j < index-1 ; j++){
                    ptr[j] = ptr[j+1] ;
                }
                index-- ;
            }
            else{
                cout << "Invalid Id" ;
            }
        }

        void DisplayByID(){
            int i = LinearSearch();
            if(i != -1){
            cout << "Doctor Details : " << endl << "Id : " << ptr[i]->Id << "    " << "Name : " << ptr[i]->Name << "    " << "Age : " << ptr[i]->Age << endl ;

            }
            else{
                cout << "Invalid Id" ;
            }
        }


        void DisplayAllDoctors(){
            for(int i = 0 ; i < index ; i++){
            cout << "Doctor Details : " << endl << "Id : " << ptr[i]->Id << "    " << "Name : " << ptr[i]->Name << "    " << "Age : " << ptr[i]->Age << endl ;
            }
        }

        friend ostream& operator << (ostream& out , Doctor &D) ;
        friend istream& operator >> (istream& in , Doctor &D) ;

    protected:

    private:

        Doctor** ptr ;
        int arr_size ;
        int index ;
        int LinearSearch(){
            int id ;
            cout << "Enter The Id of Doctor : " ;
            cin >> id ;
            for(int i = 0 ; i < index ; i++){
                if(ptr[i]->Id == id){
                    return i ;
                }
            }
            return -1 ;
        }


};










ostream& operator << (ostream& out , Doctor &D){
    out << "Doctor Details" << endl << "Id : " << D.Id << "    " << "Name : " << D.Name << "    " << "Age : " << D.Age ;
    return out ;
}


istream& operator >> (istream& in , Doctor &D){
    cout << "Enter The Id of Doctor : " ;
    in >> D.Id ;
    cout << "Enter The Name of Doctor : " ;
    in >> D.Name ;
    cout << "Enter The Age of Doctor : " ;
    in >> D.Age ;

    return in ;
}

#endif // DOCTOR_H
