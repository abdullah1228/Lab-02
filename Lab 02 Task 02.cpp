#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    virtual double calculateSalary() const = 0;
    virtual ~Employee() {}
    virtual void displayDetails() const {
        cout << "Employee" << endl;
    }
};

class FullTimeEmployee : public Employee {
private:
    string name;
    int employeeId;
    double fixedSalary;

public:
    FullTimeEmployee(int id, const string& empName, double salary)
        : employeeId(id), name(empName), fixedSalary(salary) {}

    double calculateSalary() const override {
        return fixedSalary;
    }

    void displayDetails() const override {
        cout << "Full-Time Employee" << endl;
        cout << "ID: " << employeeId << endl;
        cout << "Name: " << name << endl;
    }

    int getEmployeeId() const { return employeeId; }
    string getName() const { return name; }
    double getFixedSalary() const { return fixedSalary; }

    void setFixedSalary(double salary) { fixedSalary = salary; }
    void setName(const string& empName) { name = empName; }
};

class PartTimeEmployee : public Employee {
private:
    string name;
    int employeeId;
    double hourlyRate;
    double hoursWorked;

public:
    PartTimeEmployee(int id, const string& empName, double rate, double hours)
        : employeeId(id), name(empName), hourlyRate(rate), hoursWorked(hours) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayDetails() const override {
        cout << "Part-Time Employee" << endl;
        cout << "ID: " << employeeId << endl;
        cout << "Name: " << name << endl;
    }

    int getEmployeeId() const { return employeeId; }
    string getName() const { return name; }
    double getHourlyRate() const { return hourlyRate; }
    double getHoursWorked() const { return hoursWorked; }

    void setHourlyRate(double rate) { hourlyRate = rate; }
    void setHoursWorked(double hours) { hoursWorked = hours; }
    void setName(const string& empName) { name = empName; }
};

int main() {
    FullTimeEmployee fullTimeEmp(101, "Alice Smith", 60000.0);

    cout << "--- Full-Time Employee ---" << endl;
    fullTimeEmp.displayDetails();
    cout << "Salary: $" << fullTimeEmp.calculateSalary() << endl;

    cout << endl;

    PartTimeEmployee partTimeEmp(202, "Bob Johnson", 25.0, 30.5);

    cout << "--- Part-Time Employee ---" << endl;
    partTimeEmp.displayDetails();
    cout << "Salary: $" << partTimeEmp.calculateSalary() << endl;

    return 0;
}