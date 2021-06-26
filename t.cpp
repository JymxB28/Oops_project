#include <bits/stdc++.h>
#define N 1000
using namespace std;

/* ----------------------FOR LIBRARIAN-------------------------*/

class students
{
public:
    students *next;
    string student_name;
    string dob, date;
    string name_issued_book;
    int day_issued = 0, month_issued = 0, year_issued = 0;
    int day_returned = 0, month_returned = 0, year_returned = 0;
    int unique_id;
    int prime_id;
    int book_ID = 0;
    int fine_charged = 0;
    int months;
    int number_days = 0;
    int exceed_days;
    students()
    {
        next = NULL;
    }
};
void add_prime_member(students *&new_student)
{
    int choice;
    cout << "Select for how many months you want to be a prime member" << endl;
    cin >> new_student->months;
    cout << "Enter date of registration(DD/MM/YYYY): ";
    cin >> new_student->date;
    cout << "Amount you have to pay is " << new_student->months * 100 << endl;
    cout << "Your new ID is " << endl;
    new_student->prime_id = new_student->unique_id + 80;
    cout << "'" << new_student->prime_id << "'" << endl;
    cout << "Press '1' to continue" << endl;
    cin >> choice;
    if (choice == 1)
    {
        return;
    }
    else
    {
        cout << "INVALID INPUT";
        exit(0);
    }
}
void issue_book(students *&new_student, int choice)
{
    int choice1;
    switch (choice)
    {
    case 1:
        cout << "Enter the name of the book : ";
        cin >> new_student->name_issued_book;
        cout << "Enter the book ID : ";
        cin >> new_student->book_ID;
        {
            int date_check = 1;
            while (date_check)
            {
                cout << "Date of issuing book (format- DD MM YYYY)(WITH SPACES): ";
                cin >> new_student->day_issued >> new_student->month_issued >> new_student->year_issued;
                if (new_student->month_issued == 1 || new_student->month_issued == 3 || new_student->month_issued == 5 || new_student->month_issued == 7 || new_student->month_issued == 8 || new_student->month_issued == 10 || new_student->month_issued == 12)
                {
                    if (new_student->day_issued > 31)
                        cout << "Invalid Date" << endl;
                    else
                        date_check = 0;
                }
                else if (new_student->month_issued == 11 || new_student->month_issued == 6 || new_student->month_issued == 9 || new_student->month_issued == 11)
                {
                    if (new_student->day_issued > 30)
                        cout << "Invalid Data" << endl;
                    else
                        date_check = 0;
                }
                else if (new_student->month_issued == 2)
                {
                    if (((new_student->year_issued % 4 == 0) && (new_student->year_issued % 100 != 0)) || (new_student->year_issued % 400 == 0))
                        date_check = 0;
                    else
                        cout << "Invalid Date";
                }
            }
        }
        cout << "Number of days you want issue (not more than 10 days if you are not a prime member) : ";
        cin >> new_student->number_days;
        if (new_student->number_days <= 10 && new_student->number_days > 0)
        {
            cout << "Your book " << new_student->name_issued_book << "(ID = " << new_student->book_ID << ")"
                 << "has been issued" << endl;
        }
        else if (new_student->number_days > 10)
        {

            if (new_student->prime_id == new_student->unique_id + 80)
            {
                return;
            }
            else
            {

                cout << "You are not prime member of our library" << endl
                     << "If you want to be a part of our prime family press 1" << endl
                     << "1.Yes" << endl
                     << "2.No" << endl;
                cin >> choice1;
                if (choice1 == 1)
                {
                    add_prime_member(new_student);
                }
                else if (choice1 == 2)
                {
                    return;
                }
                else
                {
                    cout << "INVALID INPUT";
                    exit(0);
                }
            }
        }

        {
        }

        break;
    case 2:

        break;
    default:
        cout << "INVALID INPUT";
        exit(0);
        break;
    }
}

void issue_a_book_for_member(students *head)
{
    int unique_idno;
    cout << "	ENTER UNIQUE ID: ";
    cin >> unique_idno;
    students *temp = head;

    while (1)
    {
        if (temp->unique_id == unique_idno)
            break;
        else
            temp = temp->next;
    }

    issue_book(temp, 1);
}

void add_new_student(students *&head, int i)
{
    int choice;
    students *new_student = new students();
    cout << "ENTER"
         << " " << i << " STUDENT'S NAME: ";
    cin >> new_student->student_name;
    cout << "ENTER YOUR DOB (DD-MM-YYYY): ";
    cin >> new_student->dob;
    new_student->unique_id = new_student->student_name[0] + new_student->student_name[1] + new_student->student_name[2] + new_student->dob[0] + new_student->dob[1] + new_student->dob[3] + new_student->dob[4];
    cout << new_student->student_name << " your unique ID is "
         << "'" << new_student->unique_id << "'" << endl;
    cout << endl;
    new_student->prime_id = new_student->unique_id;
    cout << endl;
    cout << "Want to issue a book?" << endl
         << "1.Yes" << endl
         << "2.No" << endl;
    cin >> choice;
    if (choice == 1)
    {
        issue_book(new_student, choice);
    }
    else if (choice == 2)
    {
        if (head == NULL)
        {
            head = new_student;
            return;
        }
        students *tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new_student;
        return;
    }
    else
    {
        cout << "INVALID INPUT";
        exit(0);
    }

    if (head == NULL)
    {
        head = new_student;
        return;
    }
    students *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = new_student;
}

void check_info(students *tmp)
{

    int ID, choice;
    cout << "Enter your valid issued ID to check your issued book status" << endl;
    cin >> ID;
    while (1)
    {
        if (tmp->prime_id == ID)
        {
            cout << "Name = " << tmp->student_name << endl;
            cout << "ID = " << tmp->prime_id;
            cout << endl;
            if (tmp->book_ID == 0)
            {
                cout << "You do not have any issued book" << endl;
                cout << "To isuue book press 1" << endl
                     << "to return home page press 0" << endl;
                cin >> choice;
                if (choice == 1)
                {
                    issue_book(tmp, choice);
                }
                else if (choice == 0)
                {
                    return;
                }
                else
                {
                    cout << "INVALID INPUT";
                    exit(0);
                }
            }
            else
            {

                cout << "You already had issued book" << endl;
                cout << "Book name = " << tmp->name_issued_book << endl;
                cout << "Book Id = " << tmp->book_ID << endl;
                cout << "Issued date = " << tmp->day_issued << " " << tmp->month_issued << " " << tmp->year_issued << endl;
                cout << "Number of days, book issued by user = " << tmp->number_days << endl;
                // cout << "If book is returned press 1 and to continue press 0" << endl;
                // cin >> choice;
                // if (choice == 1)
                // {
                //     cout << "Number of days exceed by user(if not press 0) " << endl;
                //     cin >> tmp->exceed_days;
                //     cout << "Fine = " << tmp->exceed_days * 5;
                //     tmp->book_ID = 0;
                //     tmp->name_issued_book = '\0';
                // }
                // else if (choice == 0)
                // {
                //     return;
                // }
                // else
                // {
                //     cout << "INVALID INPUT";
                //     exit(0);
                // }
            }
        }
        else
        {
            tmp = tmp->next;
        }
    }
}
void remove_a_student(students *head)
{
    string name;
    int unique_idno, choice;
    cout << "search by:" << endl;
    cout << "1. name" << endl;
    cout << "2. unique id" << endl;
    cout << "ENTER CHOICE: ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "	ENTER NAME: ";
        cin >> name;
        students *temp = head;
        if (temp->student_name == name)
        {
            head = temp->next;
        }
        else
            while (1)
            {
                if (temp->next->student_name == name)
                {
                    temp->next = temp->next->next;
                    break;
                }
                temp = temp->next;
            }
    }

    else if (choice == 2)
    {
        cout << "	ENTER UNIQUE ID: ";
        cin >> unique_idno;
        students *temp = head;
        if (temp->unique_id == unique_idno)
        {
            head = temp->next;
        }
        else
            while (1)
            {
                if (temp->next->unique_id == unique_idno)
                {
                    temp->next = temp->next->next;
                    break;
                }
                temp = temp->next;
            }
    }
}

void return_book(students *head)
{
    int unique_idno;
    cout << "	ENTER UNIQUE ID: ";
    cin >> unique_idno;
    students *temp = head;
    if (temp->unique_id == unique_idno)
    {
        cout << "Date of RETURNING book (format- DD MM YYYY)(WITH SPACES): ";
        cin >> temp->day_returned >> temp->month_returned >> temp->year_returned;
        cout << " YOUR BOOK HAS BEEN RETURNED";
        return;
    }
    else
        while (1)
        {
            if (temp->unique_id == unique_idno)
                break;
            else
                temp = temp->next;
        }
    cout << "Date of RETURNING book (format- DD MM YYYY)(WITH SPACES): ";
    cin >> temp->day_returned >> temp->month_returned >> temp->year_returned;
    cout << " YOUR BOOK HAS BEEN RETURNED";
    return;
}
//--------------------------------------------------------fine charge----------------------------------------------------
int return_days(int d1, int m1, int y1, int d2, int m2, int y2)
{
    int days = 0, i;

    int montharray[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (m1 == m2)
    {
        days = d2 - d1 + 1;
        days = days + (y2 - y1) * 365;
    }

    else if (m1 < m2)
    {
        for (i = m1; i < m2; i++)
            days = days + montharray[i];

        days = days + d2 - d1 + 1 + (y2 - y1) * 365;
    }

    else if (m1 > m2)
    {
        for (i = m2; i < m1; i++)
            days = days + montharray[i];

        days = days + d1 - d2 + 1;
        days = 365 - days + (y2 - y1 - 1) * 365;
    }

    return days;
}

void fine_charging(students *&stud)
{
    if (stud->unique_id == stud->prime_id)
    {
        int number_of_days = return_days(stud->day_issued, stud->month_issued, stud->year_issued, stud->day_returned, stud->month_returned, stud->year_returned);
        stud->fine_charged = (number_of_days - stud->number_days) * 2;
        if (stud->fine_charged < 0)
            stud->fine_charged = 0;
        return;
    }

    else
        return;
}

// /* ----------------------------- FOR USER---------------------------------------------*/

// map<pair<string, string>, bool> mp;
// vector<string> v;
// vector<pair<string, string>> vp;
// vector<pair<string, string>> vpp;

// class Member
// {
// public:
//     // string BookName, SuggestedBookName, AuthorName;
//     int Fine;
//     string date_borrow;
//     string date_return;
//     multimap<int, pair<string, string>> vs;

//     int DaysInMonth[12];

//     Member()
//     {
//         DaysInMonth[0] = 31;
//         DaysInMonth[1] = 28;
//         DaysInMonth[2] = 31;
//         DaysInMonth[3] = 30;
//         DaysInMonth[4] = 31;
//         DaysInMonth[5] = 30;
//         DaysInMonth[6] = 31;
//         DaysInMonth[7] = 31;
//         DaysInMonth[8] = 30;
//         DaysInMonth[9] = 31;
//         DaysInMonth[10] = 30;
//         DaysInMonth[11] = 31;
//     }

//     friend int SearchByBookName(string, map<pair<string, string>, bool>);
//     friend int SearchByAuthorName(string, map<pair<string, string>, bool>);
//     friend int BorrowBooks(string, map<pair<string, string>, bool>);
//     friend void ReturnBook(string, map<pair<string, string>, bool>);
//     friend pair<int, int> FineCharge(vector<pair<string, string>>, vector<pair<string, string>>);
//     friend void ShowDetail(multimap<int, pair<string, string>>);
// };

// int SearchByBookName(string BookName, map<pair<string, string>, bool> &mp)
// {
//     string s = BookName;
//     auto it = mp.begin();

//     while (it != mp.end())
//     {
//         if (it->first.first == s)
//             return 1;

//         it++;
//     }
//     return -1;
// }

// int SearchByAuthorName(string AuthorName, map<pair<string, string>, bool> &mp)
// {
//     string s = AuthorName;
//     bool flag = false;
//     auto it = mp.begin();

//     while (it != mp.end())
//     {
//         if (it->first.second == s)
//         {
//             v.push_back(it->first.first);
//             flag = true;
//         }
//         it++;
//     }

//     if (flag)
//         return 1;

//     return -1;
// }

// int BorrowBooks(string BookName, map<pair<string, string>, bool> &mp)
// {
//     string s = BookName;
//     bool flag = false;
//     auto it = mp.begin();

//     while (it != mp.end())
//     {
//         if (it->first.first == s and it->second == true)
//         {
//             it->second = false;
//             flag = true;
//         }
//         it++;
//     }

//     if (flag)
//         return 1;

//     return -1;
// }

// void ReturnBook(string bookName, map<pair<string, string>, bool> &mp)
// {
//     string s = bookName;

//     auto it = mp.begin();

//     while (it != mp.end())
//     {
//         if (it->first.first == s)
//             it->second = true;
//         it++;
//     }
// }

// pair<int, int> FineCharge(vector<pair<string, string>> vp, vector<pair<string, string>> vpp)
// {
//     Member o;

//     int diffCurrMonthDays = 0;
//     auto it = vp.begin();

//     while (it != vp.end())
//     {
//         if (it->first == vpp[0].first)
//         {
//             int monthReturn = stoi(vpp[0].second.substr(3, 2));
//             int monthBorrow = stoi(it->second.substr(3, 2));
//             int dayBorrow = stoi(it->second.substr(0, 2));
//             int dayReturn = stoi(vpp[0].second.substr(0, 2));

//             if (monthReturn - monthBorrow <= 0 and dayReturn - dayBorrow < 0)
//                 return {0, -1};

//             if (monthReturn - monthBorrow == 0)
//             {
//                 diffCurrMonthDays += (stoi(vpp[0].second.substr(0, 2)) - stoi(it->second.substr(0, 2)));
//             }

//             else if (monthReturn - monthBorrow >= 1)
//             {
//                 diffCurrMonthDays += o.DaysInMonth[monthBorrow - 1] - stoi(it->second.substr(0, 2));

//                 int cnt = monthReturn - monthBorrow;
//                 int i = 1;

//                 while (cnt > 1)
//                 {
//                     diffCurrMonthDays += o.DaysInMonth[monthBorrow - 1 + i];
//                     i++;
//                     cnt--;
//                 }

//                 diffCurrMonthDays += (stoi(vpp[0].second.substr(0, 2)));
//             }
//         }
//         it++;
//     }

//     if (diffCurrMonthDays >= 15)
//     {
//         o.Fine = (diffCurrMonthDays - 15) * 50;
//     }
//     else
//         o.Fine = 0;

//     return {o.Fine, diffCurrMonthDays};
// }

// void ShowDetail(multimap<int, pair<string, string>> mp1)
// {
//     Member o;
//     cout << "Your Unique ID"
//          << "\t\t"
//          << "Name Of Books currently Borrowed"
//          << "\t\t"
//          << "Date Of Borrowing The Book\n\n";

//     for (auto i : mp1)
//     {
//         cout << "-> " << i.first << "\t\t" << i.second.first;
//         int len = i.second.first.length();
//         for (int i = 0; i < 48 - len; i++)
//             cout << " ";

//         cout << i.second.second << endl;
//     }

//     cout << endl;
// }

// //--------------------------------------------------------books----------------------------------------------------------------------
// class books
// {
// public:
//     string book_name;
//     int book_id;
//     books *next;
//     books()
//     {
//         next = NULL;
//     }
// };

// void add_new_book(books *&head)
// {
//     books *new_book = new books();
//     cout << "ENTER BOOK NAME: ";
//     cin >> new_book->book_name;
//     cout << "ENTER BOOK ID: ";
//     cin >> new_book->book_id;
//     if (head == NULL)
//     {
//         head = new_book;
//         return;
//     }
//     books *tmp = head;
//     while (tmp->next != NULL)
//     {
//         tmp = tmp->next;
//     }
//     tmp->next = new_book;
// }

// void display(books *head)
// {
//     if (head == NULL)
//     {
//         cout << "NO LIST AVAILABLE";
//         return;
//     }
//     books *tmp = head;
//     cout << "NAME"
//          << "             "
//          << "book ID" << endl;
//     while (1)
//     {
//         cout << tmp->book_name << "                 " << tmp->book_id << endl;
//         if (tmp->next == NULL)
//             return;
//         else
//             tmp = tmp->next;
//     }
// }

// void remove_a_book(books *&head)
// {
//     string name;
//     int book_idno, choice;
//     cout << "search by:" << endl;
//     cout << "1. name" << endl;
//     cout << "2. book id" << endl;
//     cout << "ENTER CHOICE: ";
//     cin >> choice;
//     if (choice == 1)
//     {
//         cout << "	ENTER book NAME: ";
//         cin >> name;
//         books *temp = head;
//         if (temp->book_name == name)
//         {
//             head = temp->next;
//         }
//         else
//             while (1)
//             {
//                 if (temp->next->book_name == name)
//                 {
//                     temp->next = temp->next->next;
//                     break;
//                 }
//                 temp = temp->next;
//             }
//     }

//     else if (choice == 2)
//     {
//         cout << "	ENTER book ID: ";
//         cin >> book_idno;
//         books *temp = head;
//         if (temp->book_id == book_idno)
//         {
//             head = temp->next;
//         }
//         else
//             while (1)
//             {
//                 if (temp->next->book_id == book_idno)
//                 {
//                     temp->next = temp->next->next;
//                     break;
//                 }
//                 temp = temp->next;
//             }
//     }
// }
//---------------------------------------------------main display--------------------------------------------------------

void display(students *head)
{
    int i;
    if (head == NULL)
    {
        cout << "NO LIST AVAILABLE";
        return;
    }
    students *tmp = head;
    cout << "NAME"
         << "              "
         << "UNIQUE ID"
         << "          "
         << "BOOK ISSUED"
         << "          "
         << "ISSUE DATE"
         << "          "
         << "RETURN DATE"
         << "          "
         << "FINE CHARGED" << endl;
    while (1)
    {
        cout << tmp->student_name;
        for (i = 0; i < 18 - (tmp->student_name.length()); i++)
            cout << " ";
        cout << tmp->unique_id;
        cout << "                ";
        cout << tmp->name_issued_book;
        for (i = 0; i < 21 - (tmp->name_issued_book.length()); i++)
            cout << " ";
        cout << tmp->day_issued << " " << tmp->month_issued << " " << tmp->year_issued;
        cout << "            ";
        cout << tmp->day_returned << " " << tmp->month_returned << " " << tmp->year_returned;
        cout << "             ";
        fine_charging(tmp);
        cout << tmp->fine_charged << endl;
        if (tmp->next == NULL)
            return;
        else
            tmp = tmp->next;
    }
}

int main()
{
    students *head = NULL;
    // books *headb = NULL;
    int choice1, choice2, choice3, i, n;
    cout << endl;

    cout << "WELCOME TO LIBRARY MANAGEMENT SYSTEM\n\n";

    cout << "LOGIN AS - \n\n"
         << "1.LIBRARIAN\n";
    //  << "2.MEMBER\n\n";
    cout
        << "ENTER YOUR CHOICE : ";
    cin >> choice1;

    while (1)
    {
        if (choice1 == 1)
        {
            cout << endl
                 << endl
                 << endl
                 << endl;
            cout << "ADD OR CHECK INFO - " << endl
                 << "1. STUDENT" << endl
                 << "2. BOOK" << endl;
            cin >> choice3;
            if (choice3 == 1)
            {
                cout << "CHOOSE FROM THE FOLLOWING: " << endl;
                cout << "1. Add  new account\n"
                     << "2. Remove a account\n"
                     << "3. Display member list\n"
                     << "4. Info about student\n"
                     << "5. return a book\n"
                     << "6. issue a book\n"
                     << "7. Exit\n";
                cout << "Enter your choice : ";
                cin >> choice2;
                if (choice2 == 1)
                {
                    cout << "ENTER NUMBER OF STUDENTS TO BE ADDED: ";
                    cin >> n;
                    for (i = 0; i < n; i++)
                        add_new_student(head, i + 1);
                }

                else if (choice2 == 2)
                {
                    remove_a_student(head);
                }

                else if (choice2 == 3)
                {
                    display(head);
                }
                else if (choice2 == 4)
                {
                    check_info(head);
                }

                else if (choice2 == 5)
                {
                    return_book(head);
                }
                else if (choice2 == 6)
                {
                    issue_a_book_for_member(head);
                }
                else if (choice2 == 7)
                {
                    exit(0);
                }
                else
                {
                    cout << "INVALID INNPUT";
                    exit(0);
                }
            }
        }
    }

    //     else if (choice3 == 2)
    //     {

    //         cout << "CHOOSE FROM THE FOLLOWING: " << endl;
    //         cout << "1. Add a new book\n"
    //              << "2. Remove a book\n"
    //              << "3. Display book list\n"
    //              << "4. Exit\n";
    //         cout << "Enter your choice : ";
    //         cin >> choice2;
    //         if (choice2 == 1)
    //         {
    //             cout << "ENTER NUMBER OF BOOKS TO BE ADDED: ";
    //             cin >> n;
    //             for (i = 0; i < n; i++)
    //                 add_new_book(headb);
    //         }

    //         else if (choice2 == 2)
    //         {
    //             remove_a_book(headb);
    //         }

    //         else if (choice2 == 3)
    //         {
    //             display(headb);
    //         }

    //         else if (choice2 == 4)
    //         {
    //             exit(0);
    //         }
    //         else
    //         {
    //             cout << "INVALID INNPUT";
    //             exit(0);
    //         }
    //     }
    //     else
    //     {
    //         cout << "INVALID INPUT";
    //         exit(0);
    //     }
    // }
    //         else if (choice1 == 2)
    //         {
    //             Member obj;

    //             mp.insert({{"Harry Potter", "J.K Rowling"}, true});
    //             mp.insert({{"Fantastic Beasts", "J.K Rowling"}, true});
    //             mp.insert({{"Shadow And Bone", "Leigh Bardugo"}, true});
    //             mp.insert({{"Six Of Crows", "Leigh Bardugo"}, true});
    //             mp.insert({{"Twilight", "Stephenie Meyer"}, true});
    //             mp.insert({{"Lord Of The Rings", "J.R.R Tolkein"}, true});
    //             mp.insert({{"The Hobbit", "J.R.R Tolkein"}, true});
    //             mp.insert({{"IT", "Stephen King"}, true});
    //             mp.insert({{"Goosebumps", "R.L Stine"}, true});
    //             mp.insert({{"The Witcher", "Andrzej Sapkowski"}, true});
    //             mp.insert({{"A Song Of Ice And Fire", "George R.R Martin"}, true});
    //             mp.insert({{"Sherlock", "Arthur Conan Doyle"}, true});
    //             mp.insert({{"After", "Anna Todd"}, true});
    //             mp.insert({{"Bridgerton", "Julia Quinn"}, true});

    //             cout << endl;
    //             cout << endl;
    //             cout << "\t\t\t\t"
    //                  << "WELCOME TO THE LIBRARY'S USER HOMEPAGE!\n\n\n";

    //             while (true)
    //             {
    //                 cout << "Enter Your Choice:\n\n";
    //                 cout << "1. Search By Book Name\n2. Search By Author Name\n3. Suggest a Book Name\n\n";

    //                 int x;
    //                 cin >> x;
    //                 cin.ignore();
    //                 cout << endl;

    //                 if (x == 1)
    //                 {
    //                     cout << "Enter the name of the book you want to search:\n\n";
    //                     string s1;
    //                     getline(cin, s1);
    //                     cout << endl;

    //                     int op = SearchByBookName(s1, mp);

    //                     if (op == 1)
    //                     {
    //                         cout << "Yes, '" << s1 << "' is present in our collection\n\n";
    //                     }

    //                     else
    //                     {
    //                         cout << "Sorry for the inconvenience, There are no is no such book in our Library.\n"
    //                              << endl;
    //                         cout << "We will try to add "
    //                              << "'"
    //                              << s1 << "'"
    //                              << " to our collection.\n\n";
    //                     }
    //                 }

    //                 else if (x == 2)
    //                 {
    //                     cout << "Enter the name of the author:\n\n";
    //                     string s2;
    //                     getline(cin, s2);

    //                     cout << endl;
    //                     int op1 = SearchByAuthorName(s2, mp);

    //                     if (op1 == 1)
    //                     {
    //                         cout << "Yes, books of " << s2 << " are available in our collection\n\n";
    //                     }

    //                     else
    //                     {
    //                         cout << "Sorry for the inconvenience. There are no books of " << s2 << " in our Library.\n";
    //                         cout << endl;
    //                         cout << "We will try to add " << s2 << "'s work to our collection.\n"
    //                              << endl;
    //                     }
    //                 }

    //                 else if (x == 3)
    //                 {
    //                     cout << "Enter the name of book, you would like us to add to our collection:\n\n";
    //                     string book_name;
    //                     getline(cin, book_name);
    //                     cout << endl;

    //                     cout << "Thanks for your suggestion, We will try to add '" << book_name << "' to our collection as soon as possible.\n\n";
    //                 }

    //                 cout << "Enter 9 if you want to Search again or Enter 0 if you want to go to our Main Menu.\n\n";

    //                 int option;
    //                 cin >> option;
    //                 cin.ignore();
    //                 cout << endl;

    //                 if (option == 9)
    //                     continue;
    //                 else if (option == 0)
    //                     break;
    //             }

    //             v.clear();

    //             cout << "\t\t\t\t"
    //                  << "WELCOME TO THE LIBRARY'S USER MAIN PAGE!\n\n\n";

    //             cout << "Enter your Unique Id:\n\n";
    //             int UId;
    //             cin >> UId;
    //             cin.ignore();
    //             cout << endl;

    //             while (true)
    //             {
    //                 cout << "MAIN MENU\n\n";

    //                 cout << "1. Borrow a Book\n2. Return a Book\n3. Show Your Profile\n\n";
    //                 int choice;
    //                 cin >> choice;
    //                 cin.ignore();
    //                 cout << endl;

    //                 if (choice == 1)
    //                 {
    //                     cout << "How do you want to search your book\n\n";
    //                     cout << "1. By Book Name\n2. By Author Name\n\n";
    //                     int select;
    //                     cin >> select;
    //                     cin.ignore();
    //                     cout << endl;

    //                     if (select == 1)
    //                     {
    //                         cout << "Enter, the name of the book\n\n";
    //                         string book;
    //                         getline(cin, book);
    //                         cout << endl;
    //                         int opt = SearchByBookName(book, mp);

    //                         if (opt == 1)
    //                         {
    //                             int ot = BorrowBooks(book, mp);

    //                             if (ot == 1)
    //                             {
    //                                 cout << "Enter the date of borrowing the book.\n\n";
    //                                 getline(cin, obj.date_borrow);
    //                                 cout << endl;

    //                                 vp.push_back({book, obj.date_borrow});

    //                                 obj.vs.insert({UId, {book, obj.date_borrow}});

    //                                 cout << "'" << book << "'"
    //                                      << " has been lent to you.\n\n";
    //                             }
    //                             else
    //                                 cout << "This book is not available for borrowing. Somebody else has already borrowed it.\n\n";
    //                         }
    //                         else
    //                             cout << "Sorry for the inconvenience, there are no is no such book in our Library.\n\n";
    //                     }

    //                     else if (select == 2)
    //                     {
    //                         cout << "Enter, the name of the Author\n\n";
    //                         string author;
    //                         getline(cin, author);
    //                         cout << endl;

    //                         int p1 = SearchByAuthorName(author, mp);

    //                         if (p1 == 1)
    //                         {
    //                             cout << "Available books of " << author << " are:\n\n";
    //                             for (auto i : v)
    //                                 cout << "-> " << i << endl;

    //                             cout << endl;

    //                             cout << "Enter the name of the book to be borrowed.\n\n";
    //                             string book1;
    //                             getline(cin, book1);
    //                             cout << endl;

    //                             int p2 = BorrowBooks(book1, mp);

    //                             if (p2 == 1)
    //                             {
    //                                 cout << "Enter the date of borrowing the book.\n\n";
    //                                 getline(cin, obj.date_borrow);
    //                                 cout << endl;

    //                                 vp.push_back({book1, obj.date_borrow});

    //                                 obj.vs.insert({UId, {book1, obj.date_borrow}});

    //                                 cout << "'" << book1 << "'"
    //                                      << " has been lent to you.\n\n";
    //                             }

    //                             else
    //                                 cout << "This book is not available for borrowing. Somebody else has already borrowed it.\n\n";
    //                         }

    //                         else
    //                             cout << "There is no book of " << author << " present in our collection\n\n";
    //                     }
    //                 }

    //                 else if (choice == 2)
    //                 {
    //                     cout << "Enter the name of book to be returned\n\n";
    //                     string book3;
    //                     getline(cin, book3);

    //                     ReturnBook(book3, mp);

    //                     cout << endl;

    //                     cout << "Enter the date of returning your book.\n\n";
    //                     getline(cin, obj.date_return);
    //                     cout << endl;

    //                     vpp.push_back({book3, obj.date_return});

    //                     auto it = obj.vs.begin();

    //                     while (it != obj.vs.end())
    //                     {
    //                         if (it->first == UId and it->second.first == book3)
    //                         {
    //                             obj.vs.erase(it);
    //                             break;
    //                         }

    //                         it++;
    //                     }

    //                     int fne = FineCharge(vp, vpp).first;
    //                     int late = FineCharge(vp, vpp).second;

    //                     vpp.clear();

    //                     if (fne > 0)
    //                     {
    //                         cout << "Since, you have submitted your book after 15 days. So, you will be fined a fees of Rs 50/- for every late submit day.\n\n";

    //                         cout << "You have submitted your book after " << late << " days.\n\n";

    //                         cout << "Fine Charged is equal to (" << late << " - 15) * 50 = " << fne << "/-" << endl;
    //                         cout << endl;
    //                     }

    //                     else if (fne == 0 and late >= 0)
    //                         cout << "You have successfully submitted the book that you borrowed from the library with no fine as returned your book after " << late << " days.\n\n";

    //                     else
    //                         cout << "Please, Enter a Valid Date!\n\n";
    //                 }

    //                 else if (choice == 3)
    //                 {
    //                     if (!(obj.vs.empty()))
    //                         ShowDetail(obj.vs);
    //                     else
    //                     {
    //                         cout << "Currently, you haven't borrowed any book from our Library!\n";
    //                         cout << "Once, you borrowed any book, your Proflie will automatically get Updated!\n\n";
    //                     }
    //                 }

    //                 else
    //                 {
    //                     cout << "INVALID INPUT!\n\n";
    //                 }

    //                 cout << "Press 1 if you want to continue or Press 0 if you want to quit.\n\n";
    //                 int enter;
    //                 cin >> enter;
    //                 cin.ignore();
    //                 cout << endl;

    //                 if (enter == 1)
    //                     continue;
    //                 else if (enter == 0)
    //                     goto last;
    //             }
    //         }
    //         else
    //         {
    //             cout << "INVALID INPUT";
    //             exit(0);
    //         }
    //     }

    // last:

    //     cout << endl;

    //     cout << "Thanks for visiting our Library!\n\n";

    return 0;
}
