#include <iostream>
#include <cstring>

using namespace std;


class Member
{
public:
    string ID;
    string name;
    string surname;
    string department;
    string email;

public:
    //get and set functions for ID, Name, Surname, Department, Email properties
    string getID()
    {
        return this->ID;
    };
    void setID(string _ID)
    {
        this->ID = _ID;
    };
    string getName()
    {
        return this->name;
    };
    void setName(string _name)
    {
        this->name = _name;
    };
    string getSurname()
    {
        return this->surname;
    };
    void setSurname(string _surname)
    {
        this->surname = _surname;
    };
    string getDepartment()
    {
        return this->department;
    };
    void setDepartment(string _department)
    {
        this->department = _department;
    };
    string getEmail()
    {
        return this->email;
    };
    void setEmail(string _email)
    {
        this->email = _email;
    };
};

//inherit Student class from Member class
class Student :public Member
{
private:
    static int student_counter;
    static Student _S[100];
public:
    //constructor
    Student()
    {
    };

    Student(string id, string Name, string Surname, string Department, string Email)
    {
        setID(id);
        setName(Name);
        setSurname(Surname);
        setDepartment(Department);
        setEmail(Email);
    }

    //student add 
    static void addStudent(string id, string Name, string Surname, string Department, string Email)
    {
        if (student_counter >= 100)
        {
            cout << "cant add more students";
        }
        else
        {
            Student newS;
            newS.setID(id);
            newS.setName(Name);
            newS.setSurname(Surname);
            newS.setDepartment(Department);
            newS.setEmail(Email);
            _S[student_counter] = newS;
            student_counter++;
        }
    }

    //display students
    static void display()
    {
        for (int i = 0; i < student_counter; i++)
        {
            cout << _S[i].getID() << " - ";
            cout << _S[i].getName() << " - ";
            cout << _S[i].getSurname() << " - ";
            cout << _S[i].getDepartment() << " - ";
            cout << _S[i].getEmail() << "\n";
        }
    }

    static void removeData(string id)
    {
        int deleted;
        int i = 0;
        while (i <= student_counter)
        {
            if (_S[i].getID() == id)
            {
                deleted = i;
                student_counter = student_counter - 1;
            }
            i++;
        }
        for (i = deleted; i <= student_counter; i++)
        {
            _S[i] = _S[i + 1];
        }
    }
};

int Student::student_counter = 0;
Student Student::_S[100];


//inherit Teacher class from Member class
class Teacher :public Member
{
private:
    static int teacher_counter;
    static Teacher _T[100];
public:
    //constructor
    Teacher()
    {
    };
    Teacher(string id, string Name, string Surname, string Department,
        string Email)
    {
        setID(id);
        setName(Name);
        setSurname(Surname);
        setDepartment(Department);
        setEmail(Email);
    }
    //teacher add
    void addTeacher(string id, string Name, string Surname, string Department, string Email)
    {
        if (teacher_counter >= 100)
        {
            cout << "can not add anymore teachers." << endl;
        }
        else
        {
            Teacher newT;
            newT.setID(id);
            newT.setName(Name);
            newT.setSurname(Surname);
            newT.setDepartment(Department);
            newT.setEmail(Email);
            _T[teacher_counter] = newT;
            teacher_counter++;
        }
    }

    //display Teacher
    static void display()
    {
        for (int i = 0; i < teacher_counter; i++)
        {
            cout << _T[i].getID() << " - ";
            cout << _T[i].getName() << " - ";
            cout << _T[i].getSurname() << " - ";
            cout << _T[i].getDepartment() << " - ";
            cout << _T[i].getEmail() << "\n";
        }
    }

    static void removeData(string id)
    {
        int deleted;
        int i = 0;
        while (i <= teacher_counter)
        {
            if (_T[i].getID() == id)
            {
                deleted = i;
                teacher_counter = teacher_counter - 1;
            }
            i++;
        }
        for (i = deleted; i <= teacher_counter; i++)
        {
            _T[i] = _T[i + 1];
        }
    }
};
int Teacher::teacher_counter = 0;
Teacher Teacher::_T[100];

//composite Appointment class from Student and Teacher classes
class Appointment
{
private:
    //appointment properties
    static int appointment_counter;
    static Appointment _A[100];
    string startingTime;
    int date;
    int month;
public:
    //composition
    Teacher T;
    Student S;
    //constructor
    Appointment()
    {
    };
    Appointment(string studentID, string teacherID, string startingTime_, int date_, int month_)
    {
        S.setID(studentID);
        T.setID(teacherID);
        setStartingTime(startingTime_);
        setDate(date_);
        setMonth(month_);
    }
    //get and set functions for Date, Start and End 
    string getStartingTime()
    {
        return this->startingTime;
    };
    void setStartingTime(string _startingTime)
    {
        this->startingTime = _startingTime;
    };
    int getDate()
    {
        return this->date;
    }
    void setDate(int _date)
    {
        this->date = _date;
    }
    int getMonth()
    {
        return this->month;
    }
    void setMonth(int _month)
    {
        this->month = _month;
    };

    //appointment add
    void addAppointment(string studentID, string teacherID, string startingTime_, int date_, int month_)
    {
        if (appointment_counter >= 100)
        {
            cout << "can not add anymore appointment." << endl;
        }
        else
        {
            Appointment newA;
            newA.appointment_counter;
            newA.S.setID(studentID);
            newA.T.setID(teacherID);
            newA.setStartingTime(startingTime_);
            newA.setDate(date_);
            newA.setMonth(month_);
            _A[appointment_counter] = newA;
            appointment_counter++;
        }
    }
    //display appointments
    static void display()
    {
        for (int i = 0; i < appointment_counter; i++)
        {
            cout << _A[i].appointment_counter << " - ";
            cout << _A[i].S.getID() << " - ";
            cout << _A[i].T.getID() << " - ";
            cout << _A[i].getStartingTime() << " - ";
            cout << _A[i].getDate() << " - ";
            cout << _A[i].getMonth() << "\n";
        }
    }

    static void removeData(int appointmentNumber)
    {
        int deleted;
        int i = 0;
        while (i <= appointment_counter)
        {
            if (_A[i].appointment_counter == appointmentNumber)
            {
                deleted = i;
                appointment_counter = appointment_counter - 1;
            }
            i++;
        }
        for (i = deleted; i <= appointment_counter; i++)
        {
            _A[i] = _A[i + 1];
        }
    }

};
int Appointment::appointment_counter = 0;
Appointment Appointment::_A[100];




int main()
{

    Student stu;
    stu.addStudent("ST123456", "Egemen", "Inanc", "CS", "egemen161143542@hotmail.com");
    stu.addStudent("ST234567", "Bhavya", "Kajani", "CS", "bk2141@gmail.com");
    stu.addStudent("ST234568", "Efe", "Turksen", "CS", "ET@gmail.com");
    stu.removeData("ST123456");
    stu.display();

    Teacher teach;
    teach.addTeacher("TC123456", "R", "P", "CS", "RP@pw.edu.pl");
    teach.display();

    Appointment app;
    app.addAppointment("ST234567", "TC123456", "08.30", 23, 7);
    app.display();

}
