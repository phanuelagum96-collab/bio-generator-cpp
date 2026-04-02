#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;

struct Person {
    string name;
    int age;
    string course;
};

// 🔹 Utility
bool isOnlySpaces(const string& str) {
    for (char c : str) {
        if (c != ' ') return false;
    }
    return true;
}

// 🔹 Input functions
string getValidName() {
    string name;
    while (true) {
        cout << "Enter your name:\n";
        getline(cin, name);

        if (name.empty() || isOnlySpaces(name)) {
            cout << "Invalid name.\n";
            continue;
        }

        bool valid = true;
        for (char c : name) {
            if (!isalpha(c) && c != ' ') {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout << "Only letters and spaces allowed.\n";
            continue;
        }

        return name;
    }
}

int getValidAge() {
    int age;
    while (true) {
        cout << "Enter age:\n";
        cin >> age;

        if (cin.fail()) {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (age < 0 || age > 120) {
            cout << "Invalid age.\n";
            continue;
        }

        cin.ignore();
        return age;
    }
}

string getValidCourse() {
    string course;
    while (true) {
        cout << "Enter course:\n";
        getline(cin, course);

        if (course.empty() || isOnlySpaces(course)) {
            cout << "Invalid course.\n";
            continue;
        }

        return course;
    }
}

// 🔹 Core features
void addPerson(vector<Person>& people) {
    Person p;
    p.name = getValidName();
    p.age = getValidAge();
    p.course = getValidCourse();
    people.push_back(p);
    cout << "Person added successfully.\n";
}

void viewBios(const vector<Person>& people) {
    if (people.empty()) {
        cout << "No data available.\n";
        return;
    }

    cout << "\n--- ALL BIOS ---\n";
    for (int i = 0; i < people.size(); i++) {
        cout << i + 1 << "." << endl;
        cout << "   Name: " << people[i].name << endl;
        cout << "   Age: " << people[i].age << endl;
        cout << "   Course: " << people[i].course << endl;
        cout << endl;
    }
}

void viewAdults(const vector<Person>& people) {
    bool found = false;
    cout << "\n--- PEOPLE ABOVE 18 ---\n";

    for (int i = 0; i < people.size(); i++) {
        if (people[i].age > 18) {
            cout << "Name: " << people[i].name << endl;
            cout << "Age: " << people[i].age << endl;
            cout << "Course: " << people[i].course << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found) cout << "No adults found.\n";
}

void deletePerson(vector<Person>& people) {
    if (people.empty()) {
        cout << "No data to delete.\n";
        return;
    }

    viewBios(people);

    int index;
    cout << "Enter number to delete: ";
    cin >> index;

    if (cin.fail()) {
        cout << "Invalid input.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    cin.ignore();

    if (index < 1 || index > people.size()) {
        cout << "Invalid number.\n";
        return;
    }

    people.erase(people.begin() + (index - 1));
    cout << "Deleted successfully.\n";
}

// 🔥 EDIT FEATURE
void editPerson(vector<Person>& people) {
    if (people.empty()) {
        cout << "No data to edit.\n";
        return;
    }

    viewBios(people);

    int index;
    cout << "Enter number to edit: ";
    cin >> index;

    if (cin.fail()) {
        cout << "Invalid input.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    cin.ignore();

    if (index < 1 || index > people.size()) {
        cout << "Invalid number.\n";
        return;
    }

    Person& p = people[index - 1];

    int choice;
    cout << "\nEdit Menu:\n";
    cout << "1. Name\n2. Age\n3. Course\nChoose field: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        p.name = getValidName();
    }
    else if (choice == 2) {
        p.age = getValidAge();
    }
    else if (choice == 3) {
        p.course = getValidCourse();
    }
    else {
        cout << "Invalid option.\n";
        return;
    }

    cout << "Updated successfully.\n";
}

// 🔹 MAIN
int main() {
    vector<Person> people;
    int choice;

    while (true) {
        cout << "\n=== MENU ===\n";
        cout << "1. Add Person\n";
        cout << "2. View All Bios\n";
        cout << "3. View Adults (18+)\n";
        cout << "4. Delete Person\n";
        cout << "5. Exit\n";
        cout << "6. Edit Person\n";
        cout << "Choose an option: ";

        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        cin.ignore();

        if (choice == 1) addPerson(people);
        else if (choice == 2) viewBios(people);
        else if (choice == 3) viewAdults(people);
        else if (choice == 4) deletePerson(people);
        else if (choice == 6) editPerson(people);
        else if (choice == 5) break;
        else cout << "Invalid choice.\n";
    }

    return 0;
}
