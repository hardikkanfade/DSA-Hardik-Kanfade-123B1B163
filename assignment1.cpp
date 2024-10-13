#include<iostream>
using namespace std;

// Define a class to represent a student
class student
{   
    public:
    int rollNo; // Roll number of the student
    string name; // Name of the student
    string address; // Address of the student
    float cgpa; // CGPA of the student

    // Function to input student details
    void input(int i)
    {
        cout<<"\nEnter details for student "<<i+1<<endl;
        cout<<"\nEnter the name:";
        cin>>name;
        cout<<"Enter Roll no:";
        cin>>rollNo;
        cout<<"Enter The address of student:";
        cin>>address;
        cout<<"Enter the cgpa of student:";
        cin>>cgpa;
    }

    // Function to print student details
    void printData(int i)
    {
        cout<<"\n\nDetails for student"<<i+1<<endl;
        cout<<"The Roll Number of student is:"<<rollNo;
        cout<<"\nThe Name of the student is :"<<name;
        cout<<"\nThe address of the student is :"<<address;
        cout<<"\nThe cgpa of the student is :"<<cgpa;
    }
};

// Function to perform insertion sort on an array of students based on roll number
void insertionsort(int n,student s[])
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int key= s[i].rollNo;
        while(j>=0 && s[j].rollNo>key)
        {
            s[j+1].rollNo=s[j].rollNo;
            student temp;
            temp = s[j+1];
            s[j+1]=s[j];
            s[j]=temp;
            j=j-1;
        }
        s[j+1].rollNo=key;
    }
}

// Function to perform shell sort on an array of students based on name
void shellsort(int n,student s[])
{
    int gap = n/2;
    while(gap>=1)
    {
        for(int j=gap;j<n;j++)
        {
            for(int i=j-gap;i>=0;i=i-gap)
            {
                if(s[i+gap].name>s[i].name)
                {
                    break;
                }else{
                    student temp = s[i+gap];
                    s[i+gap]= s[i];
                    s[i]=temp;
                }
            }
        }
        gap = gap/2;
    }
}

// Function to perform quick sort on an array of students based on roll number
void sort(student arr[], int F, int L) {
    if (F < L) {
        int pivot = arr[F].rollNo;
        int i = F+1;
        int j = L;
        while (i<=j) {
            while (arr[i].rollNo<=pivot) 
            i++;
            while (arr[j].rollNo>=pivot) 
            j--;
            if (i <= j) {
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[j], arr[F]);
        sort(arr, F, j - 1);
        sort(arr, j + 1, L);
    }
}

// Function to print student details
void print(int n,student s[])
{
    for(int i=0;i<n;i++)
        {
            s[i].printData(i);
        }
}

int main()
{
    int n;
    cout<<"Enter total Number of students:";
    cin>>n;
    student s[n]; // Create an array of students

    // Input student details
    for(int i=0;i<n;i++)
    { 
        s[i].input(i);
    }

    int flop = 0 ; // Variable to control the loop
    while(flop>=0)
    {
        int choice;
        cout<<"\n\n\n1.Sort by roll number using insertion sort\n2.sort by names alphavetically by shell sort\n3.print\n4.close the program"<<endl;
        cout<<"Enter you choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            cout<<"\n\nPerforming insertion sort on roll numnber:"<<endl;
            insertionsort(n,s);
            break;

            case 2:
            cout<<"\n\nPerforming  shell sort on names:"<<endl;
            shellsort(n,s);
            break;

            case 3:
            print(n,s);
            break;

            case 4:
            flop = -1 ;
            break;

            default:
            cout<<"Enter a valid number";
            break;
        }
    }
       return 0;
}
