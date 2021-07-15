#include<iostream>
#include<fstream>
#include<cstring>
#include <iomanip>
using namespace std;


void check_correct_input_i(float &int_check);
void check_correct_input_f(float &x);



ifstream fin;
int NoOfStud = 0;
int numsubjects = 4;
float int_check;
bool flag = 1;


class student{
private:
public:
	int   rollNo;
	char  name[30], department[30];
	struct address{
		char city[30], residentialarea[30];
		char zipcode[30];
	}a1;
	float   mark[5];
	char grade;
	float score;
	float average;

	void read(){
		fin >> rollNo; if (rollNo == 0)return;
		fin.ignore();
		fin.getline(name, 30, ',');
		fin.getline(department, 30, ',');
		fin.getline(a1.city, 30, ',');
		fin.getline(a1.residentialarea, 30, ',');
		fin.getline(a1.zipcode, 30, ',');
		for (int j = 0; j<numsubjects; j++) { fin >> mark[j]; };
		NoOfStud++;
	}

	void display_data(){
		cout << left << setw(20) << setfill(' ') << " roll Number:";
		cout << left << setw(6) << setfill(' ') << rollNo << '\n';
		cout << left << setw(20) << setfill(' ') << " name:";
		cout << left << setw(30) << setfill(' ') << name << '\n';
		cout << left << setw(20) << setfill(' ') << " department:";
		cout << left << setw(30) << setfill(' ') << department << '\n';
		cout << left << setw(20) << setfill(' ') << " city:";
		cout << left << setw(30) << setfill(' ') << a1.city << '\n';
		cout << left << setw(20) << setfill(' ') << " residential Area:";
		cout << left << setw(30) << setfill(' ') << a1.residentialarea << '\n';
		cout << left << setw(20) << setfill(' ') << " zip code:";
		cout << left << setw(30) << setfill(' ') << a1.zipcode << '\n';
		for (int i = 0; i<numsubjects; i++){
			cout << left << setw(17) << setfill(' ') << " mark in subject";
			cout << i + 1 << ": ";
			cout << mark[i] << "/100\n";
		}
		cout << left << setw(20) << setfill(' ') << " score:";
		cout << score << "/500" << '\n';
		cout << left << setw(20) << setfill(' ') << " grade:";
		cout << left << setw(30) << setfill(' ') << grade << '\n';
	}



	void display_marks(){


		cout << left << setw(10) << setfill(' ') << rollNo;
		cout << left << setw(30) << setfill(' ') << name;
		for (int i = 0; i<numsubjects; i++)
			cout << left << setw(12) << setfill(' ') << mark[i];
		cout << left << setw(12) << setfill(' ') << score;
		cout << left << setw(10) << setfill(' ') << grade;
		cout << average << "%\n";
	}

	void CalcGrade(){
		score = 0;
		for (int j = 0; j<numsubjects; j++) { score += mark[j]; }
		average = score / numsubjects;
		if (average >= 85)grade = 'A';
		else if (average >= 75 && average<85)grade = 'B';
		else if (average >= 65 && average<75)grade = 'C';
		else if (average >= 50 && average<65)grade = 'D'; else grade = 'F';
	}


	void  insertstudent(){
		fstream fst("Students.txt", ios::app);
		cout << " \n roll number : "; cin >> int_check; check_correct_input_i(int_check); rollNo = int(int_check);
		cin.ignore();
		cout << " \n name : "; cin.getline(name, 30);
		cout << " \n department : "; cin.getline(department, 30);
		cout << " \n city : "; cin.getline(a1.city, 30);
		cout << " \n residential area : "; cin.getline(a1.residentialarea, 30);
		cout << " \n zip code : "; cin.getline(a1.zipcode, 30);
		for (int i = 0; i<numsubjects; i++) {
			cout << " \n mark in subject" << i + 1 << ": "; cin >> mark[i]; check_correct_input_f(mark[i]);
			while (mark[i]>100 || mark[i]<0){
				cout << "error. enter a number between 0 and 100 : " << " \n the new mark in subject" << i + 1 << ": ";
				cin >> mark[i]; check_correct_input_f(mark[i]);
			}
		}
		fst << rollNo << ' ' << name << ',' << department << ',' << a1.city << ',' << a1.residentialarea << ',' << a1.zipcode << ',' << numsubjects << ' ';
		for (int i = 0; i<numsubjects; i++) fst << mark[i] << ' ';
		fst << endl;
		cout << "done !\n";
	}

	void modify(){
		cout << "enter the new data of the student";
		cout << " \n the old roll number is : " << rollNo << " \n the new roll number is : ";
		cin >> int_check; check_correct_input_i(int_check); rollNo = int(int_check);
		cin.ignore();
		cout << " \n the old name is : " << name << " \n the new name is : ";
		cin.getline(name, 30);
		cout << " \n the old department is : " << department << " \n the new department is : ";
		cin.getline(department, 30);
		cout << " \n the old city is : " << a1.city << " \n the new city is : ";
		cin.getline(a1.city, 30);
		cout << " \n the old residential area is : " << a1.residentialarea << " \n the new residential area is : ";
		cin.getline(a1.residentialarea, 30);
		cout << " \n the old zip code is : " << a1.zipcode << " \n the new zip code is : ";
		cin.getline(a1.zipcode, 30);
		for (int i = 0; i<numsubjects; i++) {
			cout << " \n mark in subject" << i + 1 << ": ";
			cout << " \n the old mark in subject" << i + 1 << ": " << mark[i];
			cout << " \n the new mark in subject" << i + 1 << ": ";
			cin >> mark[i]; check_correct_input_f(mark[i]);
			while (mark[i]>100 || mark[i]<0){
				cout << "error. enter a number between 0 and 100  " << " \n the new mark in subject" << i + 1 << ": ";
				cin >> mark[i]; check_correct_input_f(mark[i]);
			}
		}
		CalcGrade();
		cout << " \n Record Updated !! \n\n";
	}

};



//void readStudents(student st[]);
void CalcGrades(student st[], int NoOfStud);
//void displayReport(student st[], int NoOfStud);
//void searchstudent(student st[], int NoOfStud);
//void insert_student(student st[], int &NoOfStud);
//void modify(student st[], int NoOfStud);
void check_correct_input_i(float &int_check){
	check_correct_input_f(int_check);
	while (1){
		if (int_check == (int)int_check&&!cin.fail())break;
		else{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "\n Error.this input has to be integer." << endl;
			cout << "the right input is:";
			cin >> int_check;
		}

	}
}

void check_correct_input_f(float &x){
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "\n Error.this input has to be a number" << endl;
			cout << "the right input is:";
			cin >> x;
		}
		if (!cin.fail())
			break;
	}
}

void readStudents(student st[]){
	fin.open("students.txt"); int i = 0;
	for (int i = 0; !fin.eof(); i++)
	{
		st[i].read();
	}
	CalcGrades(st, NoOfStud);
}

void CalcGrades(student st[], int NoOfStud){
	for (int i = 0; i<NoOfStud; i++)
		st[i].CalcGrade();
}

void displayReport(student st[], int NoOfStud){
	cout << left << setw(10) << setfill(' ') << "roll #";
	cout << left << setw(30) << setfill(' ') << "name";
	for (int i = 0; i<numsubjects; i++)
		cout << left << setw(4) << setfill(' ') << "subj" << left << setw(2) << setfill(' ') << i + 1 << left << setw(6) << setfill(' ') << "100";
	cout << left << setw(5) << setfill(' ') << "score ";
	cout << left << setw(6) << setfill(' ') << numsubjects * 100;
	cout << left << setw(10) << setfill(' ') << "grade";
	cout << left << setw(10) << setfill(' ') << "percentage" << "\n";
	for (int j = 0; j<NoOfStud; j++) st[j].display_marks();
}

bool found = 1; int location;

void searchstudent(student st[], int NoOfStud){
	int i, x, rn; char n[30]; CalcGrades(st, NoOfStud);
	cout << "by roll number or by name ?" << "\n" << "by roll number enter 1" << "\n" << "by name enter 2" << "\n";
	while (true){
		cin >> int_check; check_correct_input_i(int_check); x = int(int_check);
		if (x == 1){
			cout << "enter student's roll number: "; cin >> int_check; check_correct_input_i(int_check); rn = int(int_check);
			for (i = 0; i<NoOfStud; i++)
			{
				if (st[i].rollNo == rn){ found = 1; location = i; break; }
			}
			if (i == NoOfStud){ cout << "student not found\n"; found = 0; }break;
		}
		if (x == 2){
			cout << "enter student's name: ";
			cin.ignore(); cin.getline(n, 30);
			for (i = 0; i<NoOfStud; i++)
			{
				if (!strcmp(n, st[i].name)){ found = 1; location = i; break; }
			}
			if (i == NoOfStud){ cout << "student not found\n"; found = 0; }  break;
		}
		if (x != 1 || x != 2) cout << "please enter 1 or 2 \n";
	}
}

void insert_student(student st[], int &NoOfStud){
	cout << "\n enter the new student data\n";
	st[NoOfStud].insertstudent();
	st[NoOfStud].CalcGrade();
	NoOfStud++;
}
void modify(student st[], int NoOfStud){
	int i, rn;
	while (true){
		cout << "enter student's roll number: "; cin >> int_check; check_correct_input_i(int_check); rn = int(int_check);
		for (i = 0; i<NoOfStud; i++)
		{
			if (st[i].rollNo == rn){ location = i; found = 1; break; }
		}
		if (i == NoOfStud){ cout << "student not found,try again \n"; found = 0; }
		if (found){
			st[location].modify();
			fstream fout("students.txt", ios::out);
			for (int i = 0; i<NoOfStud; i++){
				fout << st[i].rollNo << ' ' << st[i].name << ',' << st[i].department << ',' << st[i].a1.city << ',' << st[i].a1.residentialarea << ',' << st[i].a1.zipcode << ',';
				for (int j = 0; j<numsubjects; j++) fout << st[i].mark[j] << ' ';
				fout << endl;
			}
			break;
		}
	}
}


int main(){
	student st[100];
	readStudents(st);
	int x;
	cout << "welcome"<<endl;
	cout << "1.insert a student into the system"<<endl;
	cout << "2.search for a student"<<endl;
	cout << "3.edit student details"<<endl;
	cout << "4.calculate the total score and get grade of the student"<<endl;
	cout << "5.print student information"<<endl;
	cout << "6.Display all students' grade report"<<endl;
	cout << "7.exit"<<endl;
	while (true){
		cout << " enter the number of your option: ";
		cin >> int_check; 
		check_correct_input_i(int_check); 
		x = int(int_check);
		if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5 || x == 6 || x == 7){
			switch (x){
			case 1:
				insert_student(st, NoOfStud);
				break;
			case 2:
				cout << "search student ";
				searchstudent(st, NoOfStud);
				if (found)st[location].display_data();
				break;
			case 3:
				modify(st, NoOfStud);
				break;
			case 4:
				cout << "get student ";
				searchstudent(st, NoOfStud); 
				if (found){
					cout << left << setw(10) << setfill(' ') << "roll #";
					cout << left << setw(30) << setfill(' ') << "name";
					for (int i = 0; i<numsubjects; i++)
						cout << left << setw(4) << setfill(' ') << "subj" << left << setw(2) << setfill(' ') << i + 1 << left << setw(6) << setfill(' ') << "100";
					cout << left << setw(5) << setfill(' ') << "score ";
					cout << left << setw(6) << setfill(' ') << numsubjects * 100;
					cout << left << setw(10) << setfill(' ') << "grade";
					cout << left << setw(10) << setfill(' ') << "percentage" << "\n";
					st[location].display_marks();
				}
				break;
			case 5:
				cout << "get student ";
				searchstudent(st, NoOfStud); if (found)st[location].display_data();
				break;
			case 6:
				displayReport(st, NoOfStud);
				break;
			case 7:
				return 0;
			}
			cout << " to continue using the program enter 1 "<<endl;
			cout << " to exit enter 2  "<<endl;
			while (true)
			{
				cin >> int_check; check_correct_input_i(int_check); x = int(int_check);
				if (x != 1 && x != 2)cout << " please enter 1 or 2 :"<<endl; 
				else break;
			}
			if (x == 2)break;
		}

		else cout << " please enter an integer between 1 and 7 : "<<endl;
	}

	return 0;
}