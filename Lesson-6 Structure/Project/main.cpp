#include <iostream>
#include <limits>
#include <string>

struct Employee
{
    int id{};
    std::string name;
    float salary{};
    std::string department;

    Employee() = default;
    Employee(int id, const std::string &name, float salary, const std::string &department)
        : id(id), name(name), salary(salary), department(department)
    {
    }
};

struct EmployeeDirectory
{
    Employee dir[10];
    int employee_count = 0;

    void addEmployee()
    {
        if (employee_count >= 10)
        {
            std::cout << "Directory is full. Cannot add more employees." << std::endl;
            return;
        }

        Employee e;
        std::cout << "Enter id of employee: ";
        std::cin >> e.id;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter name of employee: ";
        std::getline(std::cin, e.name);

        std::cout << "Enter salary of employee: ";
        std::cin >> e.salary;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter department of employee: ";
        std::getline(std::cin, e.department);

        dir[employee_count++] = e;
        std::cout << "Employee added successfully." << std::endl;
    }

    void displayEmployee() const
    {
        if (employee_count == 0)
        {
            std::cout << "No employees in the directory." << std::endl;
            return;
        }

        for (int i = 0; i < employee_count; i++)
        {
            std::cout << "--------------------------------------------------------------------------------------" << std::endl;
            std::cout << "------------------------------ Employee-" << i + 1 << " Details ------------------------------" << std::endl;
            std::cout << "Employee ID: " << dir[i].id << std::endl;
            std::cout << "Employee Name: " << dir[i].name << std::endl;
            std::cout << "Employee Salary: " << dir[i].salary << std::endl;
            std::cout << "Employee Department: " << dir[i].department << std::endl;
        }
    }
};

int main()
{
    EmployeeDirectory d1;

    while (true)
    {
        int option;
        std::cout << "------------------------------- Welcome to Employee Directory --------------------------" << std::endl;
        std::cout << "Press 1 to add an employee to the directory" << std::endl;
        std::cout << "Press 2 to display employees from the directory" << std::endl;
        std::cout << "Press 3 to exit" << std::endl;
        std::cout << "Choose an option: ";

        if (!(std::cin >> option))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (option)
        {
        case 1:
            d1.addEmployee();
            break;
        case 2:
            d1.displayEmployee();
            break;
        case 3:
            std::cout << "Goodbye!" << std::endl;
            return 0;
        default:
            std::cout << "Invalid option. Please choose 1, 2, or 3." << std::endl;
            break;
        }
    }
}
