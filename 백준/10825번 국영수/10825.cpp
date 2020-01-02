#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Student {
	string name;
	int korean;
	int english;
	int math;
};

bool cmp(Student a, Student b) {
	
	if (a.korean == b.korean && a.english == b.english && a.math == b.math)
		return a.name < b.name;
	else if (a.korean == b.korean && a.english == b.english)
		return a.math > b.math;
	else if (a.korean == b.korean)
		return a.english < b.english;
	else
		return a.korean > b.korean;
}

int n;
vector<Student> s;

int main(void) {

	string str;
	int k, e, m;
	Student temp;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str >> k >> e >> m;
		temp.name = str;
		temp.korean = k;
		temp.english = e;
		temp.math = m;
		s.push_back(temp);
	}

	sort(s.begin(), s.end(), cmp);

	for (int i = 0; i < s.size(); i++)
		cout << s[i].name << "\n";

	return 0;
} 
