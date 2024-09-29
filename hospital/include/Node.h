#ifndef NODE_H
#define NODE_H
using namespace std;

class Node
{
    public:
        int id ;
        string name;
        int age;
        Node* next;

        Node(int _id , string _name, int _age)
        {
            id=_id;
            name=_name;
            age=_age;
            next = NULL;
        }


    private:
};

#endif // NODE_H
