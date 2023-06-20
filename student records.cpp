#include <iostream>
#include <string>

using namespace std;

class student {
public:
    student();
    student(string id, string name, int crds, double GPA);
    string getSname();
    void setSname(string name);
    void inputValuesforOneStuObj();
    void displayOneStuObj();
    bool compareNames(student s2);

private:
    string sid;
    string sname;
    int credits;
    double gpa;
};

student::student() {
    // default constructor
}

student::student(string id, string name, int crds, double GPA) {
    sid = id;
    sname = name;
    credits = crds;
    gpa = GPA;
}

string student::getSname() {
    return sname;
}

void student::setSname(string name) {
    sname = name;
}

void student::inputValuesforOneStuObj() {
    cout << "Enter sid, name, credits, and GPA: ";
    cin >> sid >> sname >> credits >> gpa;
}

void student::displayOneStuObj() {
    cout << sid << ", " << sname << ", " << credits << ", " << gpa << endl;
}

bool student::compareNames(student s2) {
    if (sname > s2.getSname()) {
        return true;
    }
    else {
        return false;
    }
}

int fillStuRecs(student s[], int capacity) {
    int n;
    cout << "You may enter up to " << capacity << " student records. Enter the number: ";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter sid, name, credits, and GPA for student #" << i + 1 << ": ";
        s[i].inputValuesforOneStuObj();
    }
    return n;
}

void displayStuRecs(student s[], int n) {
    cout << "sid, name, credits, gpa" << endl;
    for (int i = 0; i < n; i++)
    {
        s[i].displayOneStuObj();
    }
}

void sortStuRecsByName(student s[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].compareNames(s[j + 1]) == true)
            {
                student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
int linearSearchForName(student s[], int n, string key) {
    for (int i = 0; i < n; i++)
    {
        if (s[i].getSname() == key) {
            return i;
        }
    }
    return -1;
}

int binarySearchForName(student s[], int n, string key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (s[mid].getSname() == key) {
            return mid;
        } else if (s[mid].getSname() < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    const int CAPACITY = 100;
    student stuArr[CAPACITY];
    int numStudents = 0;

    // fill student array with input from user
    numStudents = fillStuRecs(stuArr, CAPACITY);

    // display all student records
    cout << "ALL STUDENT RECORDS:\n";
    displayStuRecs(stuArr, numStudents);

    // sort student records by name and display
    cout << "\nSTUDENT RECORDS SORTED BY NAME:\n";
    sortStuRecsByName(stuArr, numStudents);
    displayStuRecs(stuArr, numStudents);

    // prompt user to enter a name to search for and perform linear search
    string searchName;
    cout<<" \nLINEAR SEARCH "<<endl;
    cout << "\nEnter a name to search for: ";
    cin >> searchName;
    int linearSearchResult = linearSearchForName(stuArr, numStudents, searchName);
    if (linearSearchResult != -1)
    {
        cout << "Linear Search: Student record found at index " << linearSearchResult << endl;
        stuArr[linearSearchResult].displayOneStuObj();
    }
    else
    {
        cout << "Linear Search: Student record not found\n";
    }

    // prompt user to enter a name to search for and perform binary search
    cout<<" \nBINARY SEARCH "<<endl;
    cout << "\nEnter a name to search for: ";
    cin >> searchName;
    int binarySearchResult = binarySearchForName(stuArr, numStudents, searchName);
    if (binarySearchResult != -1)
    {
        cout << "Binary Search: Student record found at index " << binarySearchResult << endl;
        stuArr[binarySearchResult].displayOneStuObj();
    }
    else
    {
        cout << "Binary Search: Student record not found\n";
    }

    return 0;
}
