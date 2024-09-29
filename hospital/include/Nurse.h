#ifndef NURSE_H
#define NURSE_H
#include"Staff.h"

//child class
class Nurse:public Staff
{
    public:
        Nurse(int Size){
            this->index = 0 ; //set the index = 0
            this->arr_size = Size ;  //size of array
            this->ptr = new Nurse*[arr_size] ;  //memory allocate for array
        }


        Nurse(int Id , string Name , int Age , string specialty):Staff(Id , Name , Age , "Nurse") {

        }

        ~Nurse(){
            delete []ptr ; // free memory allocated for the array
        }


        int updateId(){
            int id ;
            cout << "Enter The Id of Nurse : " ;
            cin >> id ;
            return id ;
        }


        string updateName(){
            string name ;
            cout << "Enter The Name of Nurse : " ;
            cin >> name ;
            return name ;
        }


        int updateAge(){
            int age ;
            cout << "Enter The Age of Nurse : " ;
            cin >> age ;
            return age ;
        }


        void Register(Nurse* D)
        {
        if (index < arr_size) {
            this->ptr[index] = D ; //set the new doctor in the array
            index++;
        } else {
            cout << "Array is full, cannot add more Nurses." << endl;
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
            cout << "Nurse Details : " << endl << "Id : " << ptr[i]->Id << "    " << "Name : " << ptr[i]->Name << "    " << "Age : " << ptr[i]->Age << endl ;

            }
            else{
                cout << "Invalid Id" ;
            }
        }


        void DisplayAllNurse(){
            for(int i = 0 ; i < index ; i++){
            cout << "Nurse Details : " << endl << "Id : " << ptr[i]->Id << "    " << "Name : " << ptr[i]->Name << "    " << "Age : " << ptr[i]->Age << endl ;

            }
        }

        friend ostream& operator << (ostream& out , Nurse &D) ;
        friend istream& operator >> (istream& in , Nurse &D) ;


    private:

        Nurse** ptr ;
        int arr_size ;
        int index ;
        int LinearSearch(){
            int id ;
            cout << "Enter The Id of Nurse : " ;
            cin >> id ;
            for(int i = 0 ; i < index ; i++){
                if(ptr[i]->Id == id){
                    return i ;
                }
            }
            return -1 ;
        }
};

#endif // NURSE_H
