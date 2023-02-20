#include <iostream>
#include <string>
#include <vector>
using namespace std;

void addStudent(vector<string>& name, vector<string>& course, vector<string>& section);
void deleteStudent(vector<string>& name, vector<string>& course, vector<string>& section);
void modifyStudent(vector<string>& name, vector<string>& course, vector<string>& section);
void listStudent(const vector<string>& name, const vector<string>& course, const vector<string>& section);
char getAction(const string& prompt);
bool login();

int main() {
	if (!login())
		return 1;

	vector<string> name;
	vector<string> course;
	vector<string> section;

	const char exitProgram{ '5' }; // 5 to exit program
	const string prompt{ "\n \t\t\t 1. Add Records"
		"\n \t\t\t 2. List Records"
		"\n \t\t\t 3. Modify Records"
		"\n \t\t\t 4. Delete Records"
		"\n \t\t\t 5. Exit Program"
		"\n\n"
		"\t\t\t Select Your Choice: " };

	cout << "\n\t STUDENT INFORMATION SYSTEM \n";

	// Loop until the user enters the exit code.
	for (char userAction; (userAction = getAction(prompt)) != exitProgram; ) {
		switch (userAction) {
		case '1':
			cout << "\nADD STUDENT:\n------------\n";
			addStudent(name, course, section);
			break;

		case '2':
			cout << "\nLIST ALL STUDENTS:\n------------------\n";
			listStudent(name, course, section);
			break;

		case '3': // come back to this
			cout << "\nMODIFY STUDENT:\n---------------\n";
			modifyStudent(name, course, section);
			break;

		case '4':
			cout << "\nDELETE STUDENT:\n---------------\n";
			deleteStudent(name, course, section);
			break;

		default:
			cout << "\nInvalid selection!\n";
			break;
		} // end switch
	} // end while
}

bool login()
{
	static const string accountName{ "MA" };
	static const string accountPass{ "sis123" };

	size_t loginAttempt{};

	for (string loginName, loginPassword; loginAttempt < 3; ++loginAttempt) {
		cout << "Enter login name: ";
		cin >> loginName;

		cout << "Enter password: ";
		cin >> loginPassword;

		if (loginName == accountName && loginPassword == accountPass) {
			cout << "Hello " << loginName << ", Welcome to the ... \n";
			return true;
		}

		cout << "Invalid login attempt. Please try again.\n";
	}

	cout << "Too many invalid login attempts! The program will now terminate.\n";
	return false;
}

// Adds  student
void addStudent(vector<string>& name, vector<string>& course, vector<string>& section) {
	string theName;
	string theCourse;
	string theSection;

	cout << "\nEnter the student name to add: ";
	getline(cin, theName);

	cout << "\nEnter " << theName << "'s course: ";
	getline(cin, theCourse);

	cout << "\nEnter " << theName << "'s section: ";
	getline(cin, theSection);

	name.push_back(theName);
	course.push_back(theCourse);
	section.push_back(theSection);

	cout << theName << "'s information has been added.\n";
}

void listStudent(const vector<string>& name, const vector<string>& course, const vector<string>& section) {
	const auto nElements{ name.size() };

	if (nElements > 0) {
		cout << '\n';

		for (size_t i = 0; i < nElements; ++i) {
			cout << i << ") Name: " << name.at(i)
				<< ",\tCourse: " << course.at(i)
				<< ",\tSection: " << section.at(i) << endl;
		}
	}
	else
		cout << endl << "there are no students to list." << endl;

} // end listStudents

// function modifies student record
void modifyStudent(vector<string>& name, vector<string>& course, vector<string>& section) {
	string theName;
	string theCourse;
	string theSection;

	cout << "\nEnter the student name to modify: ";
	getline(cin, theName);

	cout << "Enter " << theName << "'s course: ";
	getline(cin, theCourse);

	cout << "Enter " << theName << "'s section: ";
	getline(cin, theSection);

} // end modify student records

// function deletes student records
void deleteStudent(vector<string>& name, vector<string>& course, vector<string>& section) {
	string theName;
	string theCourse;
	string theSection;

	cout << endl << "\nEnter the student name to delete: ";
	getline(cin, theName);

	cout << "Enter " << theName << "'s course: ";
	getline(cin, theCourse);

	cout << "Enter " << theName << "'s section: ";
	getline(cin, theSection);

	auto i{ name.size() - 1 };
	size_t any{};

	for (; i > 0; --i)
		if (name[i] == theName && course[i] == theCourse && section[i] == theSection) {
			name.erase(name.begin() + i);
			course.erase(course.begin() + i);
			section.erase(section.begin() + i);
			++any;
		}

	if (any > 0)
		cout << theName << "'s information has been deleted.\n";
	else
		cout << theName << "'s info has not been found.\n";
}

// Get the action the user wants to perform
char getAction(const string& prompt) {
	string answer; 

	cout << '\n' << prompt << '\n';

	while (getline(cin, answer) && answer.empty());

	return static_cast<char>(toupper(static_cast<unsigned char>(answer[0]))); // change first char to uppercase
}