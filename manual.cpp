#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// ========================== ЗАДАЧА 1.3 ==========================
class Name {
private:
    std::string lastName;
    std::string firstName;
    std::string middleName;

public:
    Name() {}
    Name(const std::string& fn) : firstName(fn) {}
    Name(const std::string& fn, const std::string& ln) : firstName(fn), lastName(ln) {}
    Name(const std::string& fn, const std::string& ln, const std::string& mn) : firstName(fn), lastName(ln), middleName(mn) {}

    std::string toString() const {
        std::string result;
        if (!lastName.empty()) result += lastName;
        if (!firstName.empty()) {
            if (!result.empty()) result += " ";
            result += firstName;
        }
        if (!middleName.empty()) {
            if (!result.empty()) result += " ";
            result += middleName;
        }
        return result;
    }

    void print() const { std::cout << toString() << "\n"; }
};

// ========================== ЗАДАЧА 1.2 ==========================
class Human {
private:
    std::string name;
    int height;

public:
    Human(const std::string& n, int h) : name(n), height(h) {}

    std::string toString() const { return name + ", рост: " + std::to_string(height); }
    void print() const { std::cout << toString() << "\n"; }
};

// ========================== ЗАДАЧА 2.4 ==========================
class Employee;
class Department {
private:
    std::string name;
    Employee* head;

public:
    Department(const std::string& n) : name(n), head(nullptr) {}
    void setHead(Employee* emp);
    std::string getName() const { return name; }
    Employee* getHead() const { return head; }
};

class Employee {
private:
    std::string name;
    Department* department;

public:
    Employee(const std::string& n) : name(n), department(nullptr) {}
    void setDepartment(Department* dep) { department = dep; }
    std::string toString() const {
        if (!department) return name + " не работает ни в каком отделе";
        Employee* head = department->getHead();
        if (head == this) return name + " начальник отдела " + department->getName();
        else if (head) return name + " работает в отделе " + department->getName() + ", начальник которого " + head->getName();
        else return name + " работает в отделе " + department->getName();
    }
    std::string getName() const { return name; }
    void print() const { std::cout << toString() << "\n"; }
};

void Department::setHead(Employee* emp) {
    head = emp;
    if (emp) emp->setDepartment(this);
}

// ========================== ЗАДАЧА 3.4 ==========================
class Department2;
class Employee2 {
private:
    std::string name;
    Department2* department;

public:
    Employee2(const std::string& n) : name(n), department(nullptr) {}
    void setDepartment(Department2* dep);
    std::string getName() const { return name; }
    void print() const;
};

class Department2 {
private:
    std::string name;
    Employee2* head;
    std::vector<Employee2*> employees;

public:
    Department2(const std::string& n) : name(n), head(nullptr) {}
    void addEmployee(Employee2* emp) {
        employees.push_back(emp);
        if (emp) emp->setDepartment(this);
    }
    void setHead(Employee2* emp) {
        head = emp;
        if (emp) {
            emp->setDepartment(this);
            if (std::find(employees.begin(), employees.end(), emp) == employees.end())
                employees.push_back(emp);
        }
    }
    std::string getName() const { return name; }
    Employee2* getHead() const { return head; }
    const std::vector<Employee2*>& getEmployees() const { return employees; }
};

void Employee2::setDepartment(Department2* dep) { department = dep; }
void Employee2::print() const {
    if (!department) {
        std::cout << name << " не работает ни в каком отделе\n";
        return;
    }
    Employee2* head = department->getHead();
    if (head == this) {
        std::cout << name << " начальник отдела " << department->getName() << "\n";
        std::cout << "  Сотрудники отдела:\n";
        for (auto emp : department->getEmployees())
            if (emp != this) std::cout << "    " << emp->getName() << "\n";
    }
    else if (head) {
        std::cout << name << " работает в отделе " << department->getName() << ", начальник которого " << head->getName() << "\n";
    }
    else {
        std::cout << name << " работает в отделе " << department->getName() << "\n";
    }
}

// ========================== ЗАДАЧА 4.5 ==========================
class Name2 {
private:
    std::string firstName;
    std::string lastName;
    std::string middleName;

public:
    Name2() {}
    explicit Name2(const std::string& fn) : firstName(fn) {}
    Name2(const std::string& fn, const std::string& ln) : firstName(fn), lastName(ln) {}
    Name2(const std::string& fn, const std::string& mn, const std::string& ln) : firstName(fn), middleName(mn), lastName(ln) {}

    std::string toString() const {
        std::string result;
        if (!firstName.empty()) result += firstName;
        if (!middleName.empty()) {
            if (!result.empty()) result += " ";
            result += middleName;
        }
        if (!lastName.empty()) {
            if (!result.empty()) result += " ";
            result += lastName;
        }
        return result;
    }

    void print() const { std::cout << toString() << "\n"; }
};

// ========================== ЗАДАЧА 5.1 ==========================
class Gun {
private:
    int bullets;

public:
    Gun() : bullets(5) {}
    Gun(int b) : bullets(b) {}
    void shoot() {
        if (bullets > 0) {
            std::cout << "Бах!\n";
            bullets--;
        }
        else {
            std::cout << "Клац!\n";
        }
    }
    int getBullets() const { return bullets; }
    void reload(int b) {
        if (b >= 0) bullets = b;
        else std::cout << "Неверное количество патронов\n";
    }
    void print() const { std::cout << "Патронов: " << bullets << "\n"; }
};

// ==================== ИНТЕРАКТИВНЫЕ ФУНКЦИИ ====================

void task13Interactive() {
    std::cout << "\nЗадача 1.3. Имена. Создайте сущность Имя, которая описывается тремя параметрами:\n"
        "Фамилия, Личное имя, Отчество.Имя может быть приведено к строковому виду,\n"
        "включающему традиционное представление всех трех параметров : Фамилия Имя\n"
        "Отчество(например “Иванов Иван Иванович”).Необходимо предусмотреть\n"
        "возможность того, что какой - либо из параметров может быть не задан, и в этом\n"
        "случае он не учитывается при приведении к текстовому виду.\n"
        "Необходимо создать следующие имена : \n"
        " Клеопатра\n"
        " Пушкин Александр Сергеевич\n"
        " Маяковский Владимир\n"
        "Обратите внимание, что при выводе на экран, не заданные параметры никак не\n"
        "участвуют в образовании строки.\n\n";

    std::vector<Name> names;
    int choice;
    do {
        std::cout << "\n--- Меню ---\n";
        std::cout << "1. Добавить имя\n";
        std::cout << "2. Вывести все имена\n";
        std::cout << "3. Очистить\n";
        std::cout << "0. Назад\n";
        std::cout << "Выберите: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Выберите тип:\n1. Только имя\n2. Имя + фамилия\n3. Имя + фамилия + отчество\n";
            int t; std::cin >> t;
            std::string fn, ln, mn;
            if (t == 1) {
                std::cout << "Введите имя: "; std::cin >> fn;
                names.push_back(Name(fn));
            }
            else if (t == 2) {
                std::cout << "Введите имя: "; std::cin >> fn;
                std::cout << "Введите фамилию: "; std::cin >> ln;
                names.push_back(Name(fn, ln));
            }
            else if (t == 3) {
                std::cout << "Введите имя: "; std::cin >> fn;
                std::cout << "Введите фамилию: "; std::cin >> ln;
                std::cout << "Введите отчество: "; std::cin >> mn;
                names.push_back(Name(fn, ln, mn));
            }
            else std::cout << "Неверно\n";
        }
        else if (choice == 2) {
            if (names.empty()) std::cout << "Нет имён\n";
            else for (size_t i = 0; i < names.size(); ++i) {
                std::cout << i + 1 << ": "; names[i].print();
            }
        }
        else if (choice == 3) {
            names.clear();
            std::cout << "Очищено\n";
        }
    } while (choice != 0);
}

void task12Interactive() {
    std::cout << "\nЗадача 1.2. Человек. Создайте сущность Человек, которая описывается:\n"
        " Имя : строка\n"
        " Рост : целое число\n"
        "Может возвращать текстовое представление вида “Name, рост : height”, где Name и\n"
        "height это переменная с именем и ростом.\n"
        "Необходимо создать и вывести на экран следующих людей :\n"
        " Человек с именем “Клеопатра” и ростом 152\n"
        " Человек с именем “Пушкин ” и ростом 167\n"
        " Человек с именем “Владимир ” и ростом 189\n\n";

    std::vector<Human> humans;
    int choice;
    do {
        std::cout << "\n--- Меню ---\n";
        std::cout << "1. Добавить человека\n";
        std::cout << "2. Вывести всех\n";
        std::cout << "3. Очистить\n";
        std::cout << "0. Назад\n";
        std::cout << "Выберите: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string name; int h;
            std::cout << "Введите имя: "; std::cin >> name;
            std::cout << "Введите рост: "; std::cin >> h;
            if (h > 0) humans.push_back(Human(name, h));
            else std::cout << "Рост должен быть >0\n";
        }
        else if (choice == 2) {
            if (humans.empty()) std::cout << "Нет людей\n";
            else for (size_t i = 0; i < humans.size(); ++i) {
                std::cout << i + 1 << ": "; humans[i].print();
            }
        }
        else if (choice == 3) {
            humans.clear();
            std::cout << "Очищено\n";
        }
    } while (choice != 0);
}

void task24Interactive() {
    std::cout << "\nЗадача 2.4. Сотрудники и отделы. Создайте сущность Сотрудник, которая описывается\n"
        "именем(в строковой форме) и отделом, в котором сотрудник работает, причем у\n"
        "каждого отдела есть название и начальник, который также является\n"
        "Сотрудником.Сотрудник может быть приведен к текстовой форме вида : “Имя\n"
        "работает в отделе Название, начальник которого Имя”.В случае если сотрудник\n"
        "является руководителем отдела, то текстовая форма должна быть “Имя\n"
        "начальник отдела Название”.\n"
        "Необходимо выполнить следующие задачи : \n"
        "1. Создать Сотрудников Петрова, Козлова, Сидорова работающих в отделе IT.\n"
        "2. Сделать Козлова начальником IT отдела.\n"
        "3. Вывести на экран текстовое представление всех трех Сотрудников(у всех\n"
        "    троих должен оказаться один и тот же отдел и начальник).\n\n";

    std::vector<Employee*> employees;
    std::string deptName;
    std::cout << "Введите название отдела: ";
    std::cin >> deptName;
    Department dept(deptName);

    int n;
    std::cout << "Сколько сотрудников создать? ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string name;
        std::cout << "Имя сотрудника " << i + 1 << ": ";
        std::cin >> name;
        Employee* emp = new Employee(name);
        emp->setDepartment(&dept);
        employees.push_back(emp);
    }

    std::cout << "\nВыберите начальника (номер):\n";
    for (size_t i = 0; i < employees.size(); ++i)
        std::cout << i + 1 << ". " << employees[i]->getName() << "\n";
    int idx; std::cin >> idx;
    if (idx >= 1 && idx <= (int)employees.size())
        dept.setHead(employees[idx - 1]);
    else std::cout << "Неверный номер\n";

    std::cout << "\nСотрудники:\n";
    for (auto e : employees) e->print();
    for (auto e : employees) delete e;
}

void task34Interactive() {
    std::cout << "\nЗадача 3.4. Сотрудники и отделы. Измените решение, полученное в задаче 2.4 таким\n"
        "образом, чтобы имея ссылку на сотрудника, можно было бы узнать список всех\n"
        "сотрудников этого отдела.\n\n";

    std::vector<Employee2*> employees;
    std::string deptName;
    std::cout << "Введите название отдела: ";
    std::cin >> deptName;
    Department2 dept(deptName);

    int n;
    std::cout << "Сколько сотрудников создать? ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string name;
        std::cout << "Имя сотрудника " << i + 1 << ": ";
        std::cin >> name;
        Employee2* emp = new Employee2(name);
        dept.addEmployee(emp);
        employees.push_back(emp);
    }

    std::cout << "\nВыберите начальника (номер):\n";
    for (size_t i = 0; i < employees.size(); ++i)
        std::cout << i + 1 << ". " << employees[i]->getName() << "\n";
    int idx; std::cin >> idx;
    if (idx >= 1 && idx <= (int)employees.size())
        dept.setHead(employees[idx - 1]);
    else std::cout << "Неверный номер\n";

    std::cout << "\nСотрудники:\n";
    for (auto e : employees) e->print();

    std::cout << "\nВведите имя сотрудника для просмотра отдела (или 0): ";
    std::string s; std::cin >> s;
    if (s != "0") {
        bool found = false;
        for (auto e : employees) {
            if (e->getName() == s) { e->print(); found = true; break; }
        }
        if (!found) std::cout << "Не найден\n";
    }
    for (auto e : employees) delete e;
}

void task45Interactive() {
    std::cout << "\nЗадача 4.5. Создаем Имена. Измените сущность Имя из задачи 1.3. Новые требования\n"
        "включают:\n"
        " Имя можно создать указав только Личное имя\n"
        " Имя можно создать указав Личное имя и Фамилию.\n"
        " Имя можно создать указав все три параметра : Личное имя, Фамилию,\n"
        "Отчество.\n"
        "Необходимо создать следующие имена :\n"
        "1. Клеопатра\n"
        "2. Александр Сергеевич Пушкин\n"
        "3. Владимир Маяковский\n"
        "4. Христофор Бонифатьевич(здесь Христофор это имя, а Бонифатьевич -\n"
        "    фамилия) \n\n";

    std::vector<Name2> names;
    int choice;
    do {
        std::cout << "\n--- Меню ---\n";
        std::cout << "1. Добавить имя\n";
        std::cout << "2. Вывести все имена\n";
        std::cout << "3. Очистить\n";
        std::cout << "0. Назад\n";
        std::cout << "Выберите: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Тип:\n1. Только имя\n2. Имя + фамилия\n3. Имя + отчество + фамилия\n";
            int t; std::cin >> t;
            std::string fn, ln, mn;
            if (t == 1) {
                std::cout << "Имя: "; std::cin >> fn;
                names.push_back(Name2(fn));
            }
            else if (t == 2) {
                std::cout << "Имя: "; std::cin >> fn;
                std::cout << "Фамилия: "; std::cin >> ln;
                names.push_back(Name2(fn, ln));
            }
            else if (t == 3) {
                std::cout << "Имя: "; std::cin >> fn;
                std::cout << "Отчество: "; std::cin >> mn;
                std::cout << "Фамилия: "; std::cin >> ln;
                names.push_back(Name2(fn, mn, ln));
            }
            else std::cout << "Неверно\n";
        }
        else if (choice == 2) {
            if (names.empty()) std::cout << "Нет имён\n";
            else for (size_t i = 0; i < names.size(); ++i) {
                std::cout << i + 1 << ": "; names[i].print();
            }
        }
        else if (choice == 3) {
            names.clear();
            std::cout << "Очищено\n";
        }
    } while (choice != 0);
}

void task51Menu() {
    std::cout << "\nЗадача 5.1. Пистолет стреляет. Создайте сущность Пистолет, которая описывается\n"
        "следующим образом : \n"
        " Имеет Количество патронов(целое число)\n"
        " Может быть создан с указанием начального количества патронов\n"
        " Может быть создан без указания начального количества патронов, в этом\n"
        "случае он изначально заряжен пятью патронами.\n"
        " Может Стрелять, что приводит к выводу на экран текста “Бах!” в том\n"
        "случае, если количество патронов больше нуля, иначе делает “Клац!”.\n"
        "После каждого выстрела(когда вывелся “Бах!”) количество патронов\n"
        "уменьшается на один.\n"
        "Создайте пистолет с тремя патронами и выстрелите из него пять раз. \n\n";

    int init;
    std::cout << "Введите начальное количество патронов (по умолчанию 5): ";
    std::cin >> init;
    if (init < 0) init = 0;
    Gun gun(init);
    int choice;
    do {
        std::cout << "Текущее состояние: ";
        gun.print();
        std::cout << "1. Выстрелить\n";
        std::cout << "2. Перезарядить (5 патронов)\n";
        std::cout << "3. Перезарядить (указать количество)\n";
        std::cout << "4. Выстрелить 5 раз подряд\n";
        std::cout << "0. Назад\n";
        std::cout << "Выберите: ";
        std::cin >> choice;
        switch (choice) {
        case 1: gun.shoot(); break;
        case 2: gun.reload(5); std::cout << "Перезаряжено (5 патронов)\n"; break;
        case 3: { int b; std::cout << "Сколько патронов: "; std::cin >> b; gun.reload(b); break; }
        case 4:
            std::cout << "1: "; gun.shoot();
            std::cout << "2: "; gun.shoot();
            std::cout << "3: "; gun.shoot();
            std::cout << "4: "; gun.shoot();
            std::cout << "5: "; gun.shoot();
            break;
        case 0: break;
        default: std::cout << "Неверный выбор\n";
        }
    } while (choice != 0);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    do {
        std::cout << "\n========== ЛАБОРАТОРНАЯ РАБОТА №15 ==========\n";
        std::cout << "1. Имена (Клеопатра, Пушкин Александр Сергеевич, Маяковский Владимир)\n";
        std::cout << "2. Люди (Клеопатра 152, Пушкин 167, Владимир 189)\n";
        std::cout << "3. Сотрудники и отделы (Петров, Козлов, Сидоров в IT, Козлов начальник)\n";
        std::cout << "4. Сотрудники и отделы с просмотром списка\n";
        std::cout << "5. Создание имён (разными конструкторами)\n";
        std::cout << "6. Пистолет с 3 патронами\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите: ";
        std::cin >> choice;
        switch (choice) {
        case 1: task13Interactive(); break;
        case 2: task12Interactive(); break;
        case 3: task24Interactive(); break;
        case 4: task34Interactive(); break;
        case 5: task45Interactive(); break;
        case 6: task51Menu(); break;
        case 0: std::cout << "Выход\n"; break;
        default: std::cout << "Неверный выбор\n";
        }
    } while (choice != 0);
}