#include <iostream>

template <typename T>            // template A
T ShowArray(T arr[], int n);

template <typename T>            // template B
T ShowArray(T * arr[], int n);

struct debts
{
    char name[50];
    double amount;
};

int main()
{
    using namespace std;
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double * pd[3]; 
    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;
    
    cout << "Listing Mr. E's counts of things:\n";
    cout<<ShowArray(things, 6)<<endl;  // uses template A
    cout << "Listing Mr. E's debts:\n";
    cout<<ShowArray(pd, 3)<<endl;      // uses template B (more specialized)
    return 0;
}

template <typename T>
T ShowArray(T arr[], int n)
{
    using namespace std;
    cout << "template A\n";
    T sum=0;
    for (int i = 0; i < n; i++)
        sum=sum+arr[i];
    return sum;
 
}

template <typename T>
T ShowArray(T * arr[], int n)
{
    using namespace std;
    cout << "template B\n";
    T sum=0.0;
    for (int i = 0; i < n; i++)
        sum=sum+*arr[i];
    return sum;
}
