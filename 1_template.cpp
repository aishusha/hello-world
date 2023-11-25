#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
// You can add more libraries here (if needed)
using namespace std;
// Define the classes and member functions here

struct Student {
	int id;
	string name;
	Student() {
		id = 0;
		name = "invalid";
	};
	Student(int inputid, string inputname) {
		id = inputid;
		name = inputname;
	};
};

class Table {
public:
	void InsertStudent(Student x, int y);
	void SearchbyID(int x);
	void SearchbyGrade(int y);
	void Statistics();
	void PrintAll();
	// You can add more member functions to help your implementation.
private:
	map<int, Student> names_records;
	map<int, int> grades_records;
	/* The data type is decided by you records; */ 
};

bool operator<(const Student&a, const Student&b) {
	return false;
	// This function may be useful for your implementation.
}

//insert one record in to the map
void Table::InsertStudent(Student x, int y) {
	map<int, Student>::iterator it_st;
        for(it_st=names_records.begin();it_st!=names_records.end();it_st++){
                if(x.id==(*it_st).first){
                        cout<<"Student exists."<<endl;
                        return;
                }
        }
	names_records[x.id]=x;
	grades_records[x.id]=y;
}

//return the name and grade of the student with id x
void Table::SearchbyID(int x) {
	int attempts=0;
	map<int, Student>::iterator it_st;
	map<int, int>::iterator it_gr;
	for(it_st=names_records.begin();it_st!=names_records.end();it_st++){
		if(x==(*it_st).first){
			attempts++;
			cout<<(*it_st).second.name<<endl;
			break;
		}
	}
	for(it_gr=grades_records.begin();it_gr!=grades_records.end();it_gr++){
		if(x==(*it_gr).first){
			cout<<(*it_gr).second<<endl;
			break;
		}
	}
	if(attempts==0){
		cout<<"No such student."<<endl;
	}
}

//return the id and name of the student with grade y
void Table::SearchbyGrade(int y) {
	vector<int> ids;
	map<int, int>::iterator it_gr;
	for(it_gr=grades_records.begin();it_gr!=grades_records.end();it_gr++){
                if(y==(*it_gr).second){
                        ids.push_back((*it_gr).first);
                }
        }
	if(ids.size()==0){
		cout<<"No such record."<<endl;
	}
	else{
		for(int i=0;i<ids.size();i++){
			cout<<ids[i]<<" "<<names_records[ids[i]].name<<endl;
		}
	}
}

void Table::Statistics() {
// Print the maximum, minimum and median of grades
	map<int, int>::iterator it_gr;
	auto it = grades_records.begin();
	int max = (*it).second;
	int min = (*it).second;
	double median=0;
	vector<int> grades;
	for(it_gr=grades_records.begin();it_gr!=grades_records.end();it_gr++){
		if((*it_gr).second>max){
			max=(*it_gr).second;
		}
		if((*it_gr).second<min){
                        min=(*it_gr).second;
                }
		grades.push_back((*it_gr).second);
	}
	sort(grades.begin(), grades.end());
	cout<<"Maximum "<<max<<endl;
	if((grades.size()%2)==0){
		median=(static_cast<double>(grades[grades.size()/2-1])+static_cast<double>(grades[grades.size()/2]))/2;
	}
	else{
		median=grades[grades.size()/2-1];
	}
	cout<<"Median "<<median<<endl;
	cout<<"Minimum "<<min<<endl;
}

//Print all records in the accending order of id
void Table::PrintAll() {
	// To be implemented
	map<int, Student>::iterator it_st;
        map<int, int>::iterator it_gr;
        for(it_st=names_records.begin();it_st!=names_records.end();it_st++){
		cout<<(*it_st).first<<" "<<(*it_st).second.name<<" "<<grades_records[(*it_st).first]<<endl;
	}
}


int main() {
	Table t;
	string command;
	int id;
	string name;
	int grade;

	while (cin >> command) {
		if (command == "InsertStudent") {
			cin >> id >> name >> grade;
			Student s = {id, name};
			t.InsertStudent(s, grade);
		}
		else if (command == "SearchbyID") {
			cin >> id;
			t.SearchbyID(id);
		}
		else if (command == "SearchbyGrade") {
			cin >> grade;
			t.SearchbyGrade(grade);
		}
		else if (command == "PrintAll") {
			t.PrintAll();
		}
		else if (command == "Statistics") {
			t.Statistics();
		}
		else if (command == "exit") {
			break;
		}
	}

	return 0;
}
