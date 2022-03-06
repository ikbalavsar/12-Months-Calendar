
#include <iostream>
#include <iomanip>

using namespace std;

int day_numbers(int day, int month, int year);
string MonthName(int monthNumber);
int DaysOfMonths(int month, int year);
void calendar(int year);

int main() {
    int year; // we will get the year from user.

    cout<<"Enter year that want to display: ";
    cin>>year; // reading year
    calendar(year); // displaying 12 months calendar

    return (0);
}

int day_numbers(int day, int month, int year){
    static int t[] = {0,3,2,5,0,3,5,1,4,6,2,4};
    year -= month < 3 ;
    return ( year + year/4 - year/100 + year/400 + t[month -1]) % 7;
}

// To return the month name, we need this function. We get the month number as
// parameter, and using the array of months we can return the expected month form this array.
string MonthName(int monthNumber){
    string month;
    string allMonths[] = {"January", "February", "March","April",
                       "May","June","July","August","September","October"
                       ,"November","December"};
    month = allMonths[monthNumber];
    return (month);
}

// We need to find that whether a month is 30 days or 31 days.
// Besides, we should check it is a leap year or not because of February.
// That's why we get the year as an input with month number.
int DaysOfMonths(int month,int year){
    if(month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11){
        return (31);
    }else if(month == 1){ // When we display February, we should check whether year is a leap year or not.
        if(year % 4 == 0){
            if(year % 100 == 0){
                if(year % 400 == 0){
                    return(29);
                }else{
                    return(28);
                }
            }else{
                return(29);
            }
        }else{
            return(28);
        }
    }else{
        return(30);
    }
}

// Finally, to display the all months and days of this year, we construct a function
// named calendar. It will take the year as input from user.
// Then, using the day_numbers, DaysOfMonths and MonthName that we created above,
// calendar function will print all months with its dates.
void calendar(int year){
    cout << "---- Calendar of "<< year <<" ----"<< endl;
    int dayValue; // to keep the day number of a month.
    int current = day_numbers(1,1,year) + 1;

    for(int i = 0; i <= 11; i++){   // This for loop provide us to determine the month and display the days of it
        dayValue = DaysOfMonths(i,year);
        cout << endl <<"           "<< MonthName(i)<<" "<<endl;
        cout <<" Sun  Mon  Tue  Wed  Thu  Fri  Sat"<< endl;
        cout<<" ------------------------------------"<< endl;

        int k=0;
        while(k< current){ // This while loop for arranging the indentation of calendar
            cout <<"     "; // For example, if a month is beginning in Wednesday, days before
            k++;            // Wednesday should be empty.
        }

        for(int j = 1; j <= dayValue; j++)
        { // With this for loop, we can display the days of current month.
            cout << setw(5) << j; // setw function is used for setting the field width. With this code line, we can display
            int a = ++k;            // the days and days number one under the other properly.
            if(a >6)
            { //To pass the new line in a month.
                k = 0;
                cout << endl;
            }
        }
        if(k)
        {
            cout << endl;
        }
        current = k;
    }
}

