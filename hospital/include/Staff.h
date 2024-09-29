#ifndef STAFF_H
#define STAFF_H
using namespace std;

//base class
class Staff
{
    private:

    protected:

    public:
        int Id;
        string Name;
        int Age;
        string Specialty;

        Staff() {}
        Staff(int id ,string name ,int  age ,string specialty)
        {
            Id=id;
            Name=name;
            Age=age;
            Specialty=specialty;
        }
};

#endif // STAFF_H











