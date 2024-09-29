#ifndef NODEMEDICAL_H
#define NODEMEDICAL_H
using namespace std;

class NodeMedical
{
    public:
        int id;
        string patientDiagnosis;
        NodeMedical* next;
        NodeMedical(int Id ,string PatientDiagnosis)
        {
            id=Id;
            patientDiagnosis=PatientDiagnosis;
            next=NULL;
        }



    private:
};

#endif // NODEMEDICAL_H
