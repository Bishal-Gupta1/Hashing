#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<stdio.h>
#include<conio.h>

#define MAX 5
using namespace std;
enum status_of_record{EMPTY,DELETED,OCCUPIED};
typedef struct employee_details
{
    int ID;
    string name;
    int age;
}E_D;
typedef struct Employee_Record
{
    E_D data;
    enum status_of_record status;
}record;
class Hash_function
{
    public:
int Division_Method(int key)     //Hashing Technique
    {
        return (key%MAX);
    }
};
Hash_function H;
void insert_data(E_D,record [] );
void display(record []);
void del(int,record[]);
int search_data(int,record []);

main()
{
    int i,key,choice;
    E_D E1;                            // This structure will store the data of Employee.
    record r_table[MAX];
    for(i=0;i<MAX;i++)               //This structure will create a array of details of employee (table).  it will provide status of each index.
    {
        r_table[i].status=EMPTY;
    }
    cout<<"\t\t\t\tHASHING OPERATIONS.\n";
    do
    {
        cout<<"\n\t\t1.Insert Data\n\t\t2.Delete Data\n\t\t3.Search Data\n\t\t4.Display Record\n\t\t5.EXIT";
        cout<<"\nEnter Your Choice\t";
        cin>>choice;
        system("cls");
        switch(choice)
        {
        case 1:

            do{
              cout<<"\nEnter Name Of Employee\t";
              fflush(stdin);
              getline(cin,E1.name);
              cout<<"Enter ID Employee\t";
              cin>>E1.ID;
              cout<<"Enter Age of Employee\t";
              cin>>E1.age;
              insert_data(E1,r_table);
               cout<<" press 1 to continue or 0 to exit.\t";
               cin>>i;
            }while(i!=0);
          system("cls");

              break;
        case 2:
             cout<<"Enter The Key to be Deleted:\t";
             cin>>key;
             del(key,r_table);
             break;
        case 3:
              cout<<"Enter a ID To be Searched:\t";
              cin>>key;
              i=search_data(key,r_table);
              if(i==-1)
                cout<<"\nKey Not Found"<<endl;
              else
                cout<<"\nKey Found at Index:"<<i<<endl;
              break;
        case 4:
            display(r_table);
            cout<<endl<<"\t\t Press any Key to Continue";
            getch();
            system("cls");
            break;
               }
    }while(choice!=5);
}
void del(int key,record r_table[])
{
    int loc=search_data(key,r_table);
    if(loc==-1)
        cout<<"Record Not Found";
        else
        r_table[loc].status=DELETED;
}
int search_data(int key,record r_table[])
{
    int i,h,loc;
    h=H.Division_Method(key);
    loc=h;
    for(i=0;i<MAX;i++)
    {
        if(r_table[loc].status==EMPTY)
            return -1;
        if(r_table[loc].data.ID==key)
            return loc;
        loc=(h+i)%MAX;
    }
}
void display(record r_table[])
{
  ofstream outf("Employ_Details.txt");
   printf("\nData are as follows:\n\n");
   outf<<"Data are as follows:\n";
    cout<<setw(12)<<"STATUS"<<setw(15)<<"ID"<<setw(20)<<"NAME"<<setw(15)<<"Age";
    cout<<endl<<setw(12)<<"--------"<<setw(15)<<"----"<<setw(20)<<"------"<<setw(15)<<"----"<<endl;
    outf<<setw(12)<<"STATUS"<<setw(15)<<"ID"<<setw(20)<<"NAME"<<setw(15)<<"Age";
    outf<<endl<<setw(12)<<"--------"<<setw(15)<<"----"<<setw(20)<<"------"<<setw(15)<<"----"<<endl;
    for(int i=0;i<MAX;i++)
    {
        cout<<"["<<i<<"]:";
        outf<<"["<<i<<"]  ";

        if(r_table[i].status==OCCUPIED)
        {
            cout<<"OCCUPIED"<<setw(15)<<r_table[i].data.ID<<setw(20)<<r_table[i].data.name<<setw(15)<<r_table[i].data.age<<endl;
            outf<<"OCCUPIED"<<setw(15)<<r_table[i].data.ID<<setw(20)<<r_table[i].data.name<<setw(15)<<r_table[i].data.age<<endl;

        }
        else if(r_table[i].status==DELETED)
            {
            cout<<"DELETED "<<endl;
            outf<<"DELETED "<<endl;
            }
        else
           {
            cout<<"EMPTY   "<<endl;
            outf<<"EMPTY   "<<endl;
           }
    }
    outf.close();
}

void insert_data(E_D E1,record r_table[] )
{

   int h,loc;
    int key=E1.ID;
    h=H.Division_Method(key);
    loc=h;
    for(int i=1;i<=MAX;i++)
    {
        if(r_table[loc].status==EMPTY || r_table[loc].status==DELETED)
        {
            r_table[loc].data=E1;
            r_table[loc].status=OCCUPIED;

            cout<<"\nSuccessfully Inserted.\n";
            return;
        }
        if(r_table[loc].data.ID==key)
        {
            cout<<"\nRecord is already in Table.\n";
            return;
        }
        loc=(h+i)%MAX;
    }
}

