
#include <iostream>
#include <vector>
using namespace std;

class subject
{
public:
    string subjectname;
    int credit;
    float gradepoint;

    subject(string name, int cr, float gp)
    {
        subjectname = name;
        credit = cr;
        gradepoint = gp;
    }
};

class student
{
public:
    string name;
    vector<subject> subjects;

    student(string studentname)
    {
        name = studentname;
    }

    void addSubject(subject sub)
    {
        subjects.push_back(sub);
    }

    float calculateCGPA()
    {
        float totalcredits = 0;
        float weightedSum = 0;
        for (int i = 0; i < subjects.size(); i++)
        {
            weightedSum += subjects[i].credit * subjects[i].gradepoint;
            totalcredits += subjects[i].credit;
        }

        if (totalcredits == 0)
            return 0;

        return weightedSum / totalcredits;
    }

    void displayCGPA()
    {
        cout << "Student Name: " << name << endl;
        cout << "CGPA: " << calculateCGPA() << endl;
    }
};

int main()
{
    student s1("John Doe");

    int n;
    cout << "Enter number of subjects: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string subname;
        int credit;
        float gradepoint;

        cout << "Enter subject name: ";
        cin >> subname;

        cout << "Enter credit for " << subname << ": ";
        cin >> credit;

        cout << "Enter grade point for " << subname << ": ";
        cin >> gradepoint;

        subject sub(subname, credit, gradepoint);
        s1.addSubject(sub);
    }

    s1.displayCGPA();

    return 0;
}
