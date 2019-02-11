/*
 * GradingStudents.cpp
 *
 *  Created on: 18-Jun-2018
 *      Author: dubeyalo
 */




#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the gradingStudents function below.
 */
vector<int> gradingStudents(vector<int> grades) {

    for(int i =0;i< grades.size(); i++){
    	if(grades[i]<38)
    		continue;
    	else {
			int a = grades[i]%5;
			a = grades[i] + (5 - a);
			if ((a - grades[i]) < 3)
				grades[i] = a;
		}
	}
    return grades;
}

int GradingStudents()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> grades(n);

    for (int grades_itr = 0; grades_itr < n; grades_itr++) {
        int grades_item;
        cin >> grades_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        grades[grades_itr] = grades_item;
    }

    vector<int> result = gradingStudents(grades);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        cout << result[result_itr];

        if (result_itr != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}
