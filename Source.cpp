#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Name {//1.3
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

class Human {//1.2
private:
    std::string name;
    int height;

public:
    Human(const std::string& n, int h) : name(n), height(h) {}

    std::string toString() const { return name + ", рост: " + std::to_string(height); }
    void print() const { std::cout << toString() << "\n"; }
};

class Employee;//2.4
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

class Department2;//3.4
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

class Name2 {//4.5
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

class Gun { //5.1
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

void task13Demo() {
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
    Name n1("Клеопатра");
    Name n2("Александр", "Пушкин", "Сергеевич");
    Name n3("Владимир", "Маяковский");
    std::cout << "Имя 1: "; n1.print();
    std::cout << "Имя 2: "; n2.print();
    std::cout << "Имя 3: "; n3.print();
}

void task12Demo() {
    std::cout << "\nЗадача 1.2. Человек. Создайте сущность Человек, которая описывается:\n"
        " Имя : строка\n"
        " Рост : целое число\n"
        "Может возвращать текстовое представление вида “Name, рост : height”, где Name и\n"
        "height это переменная с именем и ростом.\n"
        "Необходимо создать и вывести на экран следующих людей :\n"
        " Человек с именем “Клеопатра” и ростом 152\n"
        " Человек с именем “Пушкин ” и ростом 167\n"
        " Человек с именем “Владимир ” и ростом 189\n\n";
    Human h1("Клеопатра", 152);
    Human h2("Пушкин", 167);
    Human h3("Владимир", 189);
    std::cout << "Человек 1: "; h1.print();
    std::cout << "Человек 2: "; h2.print();
    std::cout << "Человек 3: "; h3.print();
}

void task24Demo() {
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
    Employee petrov("Петров");
    Employee kozlov("Козлов");
    Employee sidorov("Сидоров");
    Department it("IT");
    kozlov.setDepartment(&it);
    petrov.setDepartment(&it);
    sidorov.setDepartment(&it);
    it.setHead(&kozlov);
    std::cout << "Петров: "; petrov.print();
    std::cout << "Козлов: "; kozlov.print();
    std::cout << "Сидоров: "; sidorov.print();
}

void task34Demo() {
    std::cout << "\nСотрудники и отделы. Измените решение, полученное в задаче 2.4 таким\n"
        "образом, чтобы имея ссылку на сотрудника, можно было бы узнать список всех\n"
        "сотрудников этого отдела.\n\n";
    Employee2 petrov("Петров");
    Employee2 kozlov("Козлов");
    Employee2 sidorov("Сидоров");
    Department2 it("IT");
    it.addEmployee(&petrov);
    it.addEmployee(&kozlov);
    it.addEmployee(&sidorov);
    it.setHead(&kozlov);
    std::cout << "Петров: "; petrov.print();
    std::cout << "Козлов: "; kozlov.print();
    std::cout << "Сидоров: "; sidorov.print();
}

void task45Demo() {
    std::cout << "\nСоздаем Имена. Измените сущность Имя из задачи 1.3. Новые требования\n"
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
    Name2 n1("Клеопатра");
    Name2 n2("Александр", "Сергеевич", "Пушкин");
    Name2 n3("Владимир", "Маяковский");
    Name2 n4("Христофор", "Бонифатьевич");
    std::cout << "Имя 1: "; n1.print();
    std::cout << "Имя 2: "; n2.print();
    std::cout << "Имя 3: "; n3.print();
    std::cout << "Имя 4: "; n4.print();
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
    Gun gun(3);
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
        std::cout << "\n";
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
        std::cout << "\n";
        switch (choice) {
        case 1: task13Demo(); break;
        case 2: task12Demo(); break;
        case 3: task24Demo(); break;
        case 4: task34Demo(); break;
        case 5: task45Demo(); break;
        case 6: task51Menu(); break;
        case 0: std::cout << "Выход\n"; break;
        default: std::cout << "Неверный выбор\n";
        }
    } while (choice != 0);

}