    #include <iostream>
    #include <vector>
    #include <time.h>
    #include <iomanip>


    using namespace std;

    double toNumGrade(string s) {
        if (s == "A+") {
            return 4.0;
        }
        else if (s == "A") {
            return 3.75;
        }
        else if (s == "B+")	{
            return 3.5;
        }
        else if (s == "B") {
            return 3.0;
        }
        else if (s == "C+")	{
            return 2.5;
        }
        else if (s == "C") {
            return 2.0;
        }
        else if (s == "D+")	{
            return 1.5;
        }
        else if (s == "D") {
            return 1.0;
        }
        else {
            return 0.0;
        }

    }

    bool comp(pair<string*, double> a, pair<string*, double> b) {
        if (a.second == b.second) {
            if (a.first[0] == b.first[0]) {
                return a.first[1] < b.first[1];
            } else {
                return a.first[0] < b.first[0];
            }
        } else {
            return a.second < b.second;
        }
    }

    int partition(pair<string*, double>* arr, int l, int r) {    
        srand(time(NULL));

        int pivot = l + rand() % (r - l);
        swap(arr[pivot], arr[r]);

        int i = l - 1;
        for (int j = l; j < r; j++) {
            if (comp(arr[j], arr[r])) {
                i++;
                swap(arr[j], arr[i]);
            }
        }

        swap(arr[i + 1], arr[r]);

        return i + 1;

    }

    void quickSort(pair<string*, double>* arr, int l, int r) {
        if (l < r) {
            int p = partition(arr, l, r);
            quickSort(arr, l, p - 1);
            quickSort(arr, p + 1, r);
        }
    }



    int main() {
        int n; cin >> n;
        string f_name, l_name;

        pair<string*, double> arr[n];

        for (int i = 0; i < n; i++) {
            cin >> l_name >> f_name;

            int num_of_sub; cin >> num_of_sub;

            pair<string*, double> s;
            s.first = new string[2];
            s.first[0] = l_name;
            s.first[1] = f_name;


            string letter_grade;
            int credit;

            double credit_sum = 0;
            double grade_by_credit = 0;

            for (int i = 0; i < num_of_sub; i++) {
                cin >> letter_grade >> credit;
                credit_sum += credit;
                grade_by_credit += (toNumGrade(letter_grade) * credit);
            };

            s.second = (grade_by_credit / credit_sum);

            arr[i] = s;

        }

        quickSort(arr, 0, n - 1);

        for (int i = 0; i < n; i++) {
            cout << arr[i].first[0] << " " << arr[i].first[1] << " " 
            << fixed << setprecision(3) << arr[i].second << endl;

            delete[] arr[i].first;
        }
    }