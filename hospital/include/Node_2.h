#ifndef NODE_2_H
#define NODE_2_H


class Node_2
{
    public:
       int Patient_id;
       int Doctor_id;
       string Date;
       Node_2* next;

        Node_2(int patient_id, int doctor_id , string date)
        {
            Patient_id = patient_id;
            Doctor_id = doctor_id;
            Date =date;
            next = NULL;
        }

    protected:

    private:
};

#endif // NODE_2_H
