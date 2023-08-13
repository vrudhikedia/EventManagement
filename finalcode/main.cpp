//order of functions:
// parking code, ground booking code, hall, hotel, ground, Wedding , birthday, baby shower, , menu


#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// The parking code starts here!!!!
struct park_node
{
    int data;
    int car_no;
    park_node *next;
};
park_node *head_park=NULL;

void parking_default(int val,int numb)
{
    park_node *first;
    first = new park_node;
    first->data=val;
    first->car_no=numb;
    first->next=head_park;
    head_park = first;
}

void parking_display()
{
    park_node *temp = head_park;
    if(head_park==NULL)
    {
        cout<<"\n The parking is empty! ";
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<"\n"<<temp->data;
            cout<<"\t"<<temp->car_no;
            temp=temp->next;
        }
    }
}


void addtopark(int pos, int MAX ,int val, int numb)
{
    park_node *temp=head_park;
    if(pos>MAX||pos<0)
        cout<<"\n There are only 10 parking spaces! ";
    else
    {
            for(int i=1;i<pos;i++)
            {
                temp = temp->next;
            }
            if(temp->data==1)
            {
                cout<<"\n Parking space already occupied! ";
            }
            else
            {
                temp->data = val;
                temp->car_no=numb;
            }
    }
}

void delfrompark(int pos, int MAX ,int val,int numb)
{
    park_node *temp=head_park;
    if(pos>MAX||pos<0)
        cout<<"\n There are only 10 parking spaces! ";
    else
    {
            for(int i=1;i<pos;i++)
            {
                temp = temp->next;
            }
            if(temp->data==0)
            {
                cout<<"\n Parking space already empty! ";
            }
            else if(temp->car_no!=numb)
            {
                cout<<"\n This is not the car that is parked at that position! ";
            }
            else
            {
                temp->data = val;
                temp->car_no=0;
            }
    }
}

void search_car(int num)
{
    park_node *temp=head_park;
    int pos=1;
    if(head_park==NULL)
        cout<<"\n Parking is empty";
    else
    {
        while(temp->car_no!=num)
        {
            temp=temp->next;
            pos++;
        }
        cout<<"\n Your car is at position: "<<pos;
    }
}

void parking()
{
    cout<<"\n The maximum number of parking available is 10. ";
    int MAX = 10;
    for(int i=MAX;i>0;i--)
    {
        parking_default(0,0000);
    }
    parking_display();
    int ch;
    do
    {
       cout<<"\n Enter choice: 1. Add to parking \t 2.Delete from parking \t 3. Display \t 4.Search car by number \t 5. Exit ";
       cin>>ch;
       switch(ch)
       {
       case 1:
        {
            int pos,numb;
            cout<<"\n Enter a position on which you want to park at: ";
            cin>>pos;
            cout<<"\n Enter your 4 digit car number: ";
            cin>>numb;
            addtopark(pos,MAX,1,numb);
            break;
        }
       case 3:
        {
            parking_display();
            break;
        }
       case 2:
        {
           int pos,numb;
            cout<<"\n Enter the position where your car is parked: ";
            cin>>pos;
            cout<<"\n Enter your car number: ";
            cin>>numb;
            delfrompark(pos,MAX,0,numb);
            break;
        }
       case 4:
        {
            int number;
            cout<<"\n Enter your car number: ";
            cin>>number;
            search_car(number);
            break;
        }
       }
    }while(ch!=5);
}

//The parking code ends here!!!!

//the ground code starts here!!!

struct grbook_node
{
    string day;
    string name;
    grbook_node *next;
};

grbook_node* head = NULL;

void gr_default(string day,string name)
{
    grbook_node *first = new grbook_node;
    first->day = day;
    first->name = name;
    first->next = head;
    head = first;
}


void book_day_ground(string day,string name,string arr[7])
{
    grbook_node *temp =head;
    int park_ch;
    int cnt=0;
    for(int i=0;i<7;i++)
    {
        if(arr[i]==day)
            cnt++;
    }
    if(cnt==1)
    {
         while(temp->day!=day)
        {
            temp=temp->next;
        }
        if(temp->name!="Empty")
                cout<<"\n Day is already booked! ";
        else
            {
                temp->name = name;
                cout<<"\n Enter 1.Add Valet Parking \t 2.Exit ";
                cin>>park_ch;
                if(park_ch==1)
                    parking();
            }
    }
    else
        cout<<"\n Please enter the correct day! ";
}

void cancel_ground_booking(string day, string name,string arr[7])
{
    grbook_node *temp =head;
    int cnt=0;
    for(int i=0;i<7;i++)
    {
        if(arr[i]==day)
            cnt++;
    }
    if(cnt==1)
    {
         while(temp->day!=day)
        {
            temp=temp->next;
        }
        if(temp->name!=name)
                cout<<"\n You cannot cancel this booking as the details are not matching ";
        else
            temp->name = "Empty";
    }
    else
        cout<<"\n Please enter the correct day! ";
}

void ground_book_display()
{
    grbook_node *temp = head;
    if(head==NULL)
    {
        cout<<"\n All the days are open for booking! ";
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<"\n"<<temp->day;
            cout<<"         "<<temp->name;
            temp=temp->next;
        }
    }
}

void ground_booking()
{
    int ch;
    string name,day;
    string arr[7] = {"MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY","SUNDAY"};
    for(int i=6;i>=0;i--)
    {
        gr_default(arr[i],"Empty");
    }
    ground_book_display();
    do
    {
        cout<<"\n Enter 1.Booking \t 2.Display \t 3.Cancel Booking \t 4.Exit";
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                cout<<"\n Enter your name: ";
                cin>>name;
                cout<<"\n Enter the day you wanna book: ";
                cin>>day;
                transform(day.begin(),day.end(),day.begin(),::toupper);
                transform(name.begin(),name.end(),name.begin(),::tolower);
                book_day_ground(day,name,arr);
                break;
            }
        case 2:
            {
                ground_book_display();
                break;
            }
        case 3:
            {
                cout<<"\n Enter the day you want to cancel the booking of: ";
                cin>>day;
                transform(day.begin(),day.end(),day.begin(),::toupper);
                cout<<"\n Enter your name:";
                cin>>name;
                transform(name.begin(),name.end(),name.begin(),::tolower);
                cancel_ground_booking(day,name,arr);
                break;
            }
        }
    }while(ch!=4);
}

//the ground code ends here!!!!

//the hall code starts here!!!!

struct node{
    string name;
    string day;
    node *next;
};

node*hall_head=NULL;

void hallbookingbasic(string dae,string na)
{
    node *first;
    first=new node;
    first->name=na;
    first->day=dae;
    first->next=hall_head;
    hall_head=first;
}


void hall_booking(string nam,string da,int pos)
{
    node *temp=hall_head;
    int park;
    if(pos>7||pos<1)
    {
        cout<<"There's no position as that, position out of bounds"<<endl;
    }
    else
    {

        for(int i=1;i<pos;i++)
        {
            temp=temp->next;
        }
        if(temp->name!="Empty")
        {
           cout<<"Sorry we are Booked"<<endl;
        }
        else
        {
            temp->day=da;
            temp->name=nam;
            cout<<"Your Booking has been done at position "<<pos<<" successfully"<<endl;
            cout<<"\n Enter 1.Add Valet Parking \t 2.Exit ";
            cin>>park;
            if(park==1)
                parking();
        }

    }
}
void delete_hallbooking(string nam,string dae,int pos)
{
    node*temp=hall_head;
    if(pos>7||pos<1)
    {
        cout<<"No data available to delete"<<endl;
    }
    else
    {
        for(int i=1;i<pos;i++)
        {
            temp=temp->next;
        }
        if(temp->name==nam)
        {
            temp->name="Empty";
            cout<<"Your booking has been cancelled from position "<<pos<<" sucessfully"<<endl;
        }
        else
        cout<<"You cannot cancel this booking"<<endl;
    }
}

void hall_booking_display()
{
    node *temp=hall_head;
    if(hall_head==NULL)
    {
        cout<<"All days are available for booking"<<endl;
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<temp->day;
            cout<<"\t"<<temp->name<<endl;
            temp=temp->next;
        }
    }
}

void bookinghall()
{
    int i,ch,posi;
    string name,day;
    string arr[7]={"SUNDAY","MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY"};
    for(i=6;i>=0;i--)
    {
        hallbookingbasic(arr[i],"Empty");
    }
    cout<<"MENU"<<endl;
    do{
        cout<<"1.Booking \t 2.Cancel Booking \t 3.Display \t 4.Exit"<<endl;
        cout<<"Enter Choice:"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter day:"<<endl;
                cin>>day;
                cout<<"Enter name:"<<endl;
                cin>>name;
                cout<<"Enter the position you have been given(1 for Sunday, 2 for Monday, 3 for Tuesday and so on):"<<endl;
                cin>>posi;
                transform(day.begin(),day.end(),day.begin(),::toupper);
                transform(name.begin(),name.end(),name.begin(),::tolower);
                hall_booking(name,day,posi);
                break;
            case 2:
                cout<<"Enter day of your booking:"<<endl;
                cin>>day;
                cout<<"Enter the name with which you've booked:"<<endl;
                cin>>name;
                cout<<"Enter the position that you were given during booking:"<<endl;
                cin>>posi;
                transform(day.begin(),day.end(),day.begin(),::toupper);
                transform(name.begin(),name.end(),name.begin(),::tolower);
                delete_hallbooking(name,day,posi);
                break;
            case 3:
                hall_booking_display();
                break;
        }
    }while(ch!=4);

}
//the hall code ends here!!!


//the hotel code starts here!!

struct hotel_book_node
{
    string day;
    string name;
    hotel_book_node *next;
};

hotel_book_node* head1 = NULL;

void hotel_default(string day,string name)
{
    hotel_book_node *first = new hotel_book_node;
    first->day = day;
    first->name = name;
    first->next = head1;
    head1 = first;
}


void book_hotelday(string day,string name,string arr[7])
{
    hotel_book_node *temp =head1;
    int park_ch;
    int cnt=0;
    for(int i=0;i<7;i++)
    {
        if(arr[i]==day)
            cnt++;
    }
    if(cnt==1)
    {
         while(temp->day!=day)
        {
            temp=temp->next;
        }
        if(temp->name!="Empty")
                cout<<"\n Day is already booked! ";
        else
            {
                temp->name = name;
                cout<<"\n Enter 1.Add Valet Parking \t 2.Exit ";
                cin>>park_ch;
                if(park_ch==1)
                    parking();
            }
    }
    else
        cout<<"\n Please enter the correct day! ";
}

void cancel_hotel_booking(string day, string name,string arr[7])
{
    hotel_book_node *temp =head1;
    int cnt=0;
    for(int i=0;i<7;i++)
    {
        if(arr[i]==day)
            cnt++;
    }
    if(cnt==1)
    {
         while(temp->day!=day)
        {
            temp=temp->next;
        }
        if(temp->name!=name)
                cout<<"\n You cannot cancel this booking as the details are not matching ";
        else
            temp->name = "Empty";
    }
    else
        cout<<"\n Please enter the correct day! ";
}

void hotel_book_display()
{
    hotel_book_node *temp = head1;
    if(head1==NULL)
    {
        cout<<"\n All the days are open for booking! ";
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<"\n"<<temp->day;
            cout<<"         "<<temp->name;
            temp=temp->next;
        }
    }
}

void hotel_booking()
{
    int ch;
    string name,day;
    string arr[7] = {"MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY","SUNDAY"};
    for(int i=6;i>=0;i--)
    {
        hotel_default(arr[i],"Empty");
    }
    hotel_book_display();
    do
    {
        cout<<"\n Enter 1.Booking \t 2.Display \t 3.Cancel Booking \t 4.Exit";
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                cout<<"\n Enter your name: ";
                cin>>name;
                cout<<"\n Enter the day you wanna book: ";
                cin>>day;
                transform(day.begin(),day.end(),day.begin(),::toupper);
                transform(name.begin(),name.end(),name.begin(),::tolower);
                book_hotelday(day,name,arr);
                break;
            }
        case 2:
            {
                hotel_book_display();
                break;
            }
        case 3:
            {
                cout<<"\n Enter the day you want to cancel the booking of: ";
                cin>>day;
                transform(day.begin(),day.end(),day.begin(),::toupper);
                cout<<"\n Enter your name:";
                cin>>name;
                transform(name.begin(),name.end(),name.begin(),::tolower);
                cancel_hotel_booking(day,name,arr);
                break;
            }
        }
    }while(ch!=4);
}

//the hotel code ends here!!

void hall()    //hall booking details
{   int hall,hallch;
    cout<<" \n 1. Hall A \n 2. Hall B \n 3. Hall C";
    cout<<"\n Select the hall: \n ";
    cin>>hall;
    switch (hall)
    {
        case 1:
            cout<<"\n Hall A details are as follows:";
            cout<< " \n Price: 10000 Rs per day ";
            cout<< " \n Food offered : Indian, Chinese, Italian";
            cout<<"\n Music facilities: Live DJ";
            cout<<" \n Location : Andheri (W)";
            cout<<"1. Book Hall 2.Exit"<<endl;
            cin>>hallch;
            if(hallch==1)
            {
                bookinghall();
            }
            break;
        case 2:
            cout<<"\n Hall B details are as follows:";
            cout<< " \n Price: 12000 Rs per day ";
            cout<< " \n Food offered : Indian, Chinese, Italian";
            cout<<"\n Music facilities: Live DJ";
            cout<<" \n Location : Bandra (W)";
            cout<<"1. Book Hall 2.Exit"<<endl;
            cin>>hallch;
            if(hallch==1)
            {
                bookinghall();
            }
            break;
        case 3:
            cout<<"\n Hall C details are as follows:";
            cout<< " \n Price: 8000 Rs per day ";
            cout<< " \n Food offered : Indian, Chinese, Italian";
            cout<<"\n Music facilities: Live DJ";
            cout<<" \n Location : Borivali (E)";
            cout<<"1. Book Hall 2.Exit"<<endl;
            cin>>hallch;
            if(hallch==1)
            {
                bookinghall();
            }
            break;

        default:
            cout<< "Invalid input, please refrain to the above three choices";
            break;
    }

}
//----------------------------------------------------------------------------------------
void hotel()  //hotel booking details
{
    int choice,book_ch;
    cout<< " \n 1. Raddison Blue - Press 1 \n 2. Taj Palace - Press 2 \n 3. Trident Oberoi- Press 3 \n";
    cin>> choice;
    switch (choice)
{
    case 1:
        cout<<"\n Raddison Blue's details are as follows:";
        cout<< " \n Price: 10000 Rs per day ";
        cout<< " \n Food offered : Indian, Chinese, Italian";
        cout<<"\n Music facilities: Live DJ";
        cout<<" \n Location : Airport Road, Andheri (E)";
        cout<< " \n Room Facilities: yes";
        cout<< "\n Contact number: 9987878909";
        cout<<"\n 1. Book Hotel \t 2. Exit ";
        cin>>book_ch;
        if(book_ch==1)
        {
            hotel_booking();
        }
        break;
    case 2:
        cout<<"\n Taj Palace's  details are as follows:";
        cout<< " \n Price: 12000 Rs per day ";
        cout<< " \n Food offered : Indian, Chinese, Italian";
        cout<<"\n Music facilities: Live DJ";
        cout<<" \n Location : Bandra (W)";
        cout<< " \n Room Facilities: yes";
        cout<< "\n Contact number: 9987878909";
        cout<<"\n 1. Book Hotel \t 2. Exit ";
        cin>>book_ch;
        if(book_ch==1)
        {
            hotel_booking();
        }
        break;
    case 3:
        cout<<"\n Trident Oberoi's details are as follows:";
        cout<< " \n Price: 8000 Rs per day ";
        cout<< " \n Food offered : Indian, Chinese, Italian";
        cout<<"\n Music facilities: Live DJ";
        cout<<" \n Location : Borivali (E)";
        cout<< " \n Room Facilities: yes";
        cout<< "\n Contact number: 9987878909";
        cout<<"\n 1. Book Hotel \t 2. Exit ";
        cin>>book_ch;
        if(book_ch==1)
        {
            hotel_booking();
        }
        break;

    default:
        cout<< "Invalid input, please refrain to the above three choices";
        break;
}

}
//----------------------------------------------------------------------------------------

void ground() //ground details
{
    int choice,book_ch;
    cout<<"\n 1. Ground 1 - more than 1000 people \t 2. Ground 2 - more than 1500 people. ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            cout<<"\n The Ground 1 has the capacity of 1000-1500 people. ";
            cout<<"\n Price: 15000 Rs per day";
            cout<<"\n Food offered : Indian, Chinese, Italian and Live counters ";
            cout<<"\n Music facilities: Live DJ";
            cout<<" \n Location : Juhu JVPD Scheme";
            cout<<"\n 1. Book ground \t 2. Exit ";
            cin>>book_ch;
            if(book_ch==1)
            {
                ground_booking();
            }
            break;
        }
        case 2:
        {
            cout<<"\n The Ground 2 has capacity of 1500-2000 people ";
            cout<<"\n Price : 17000 Rs per day ";
            cout<<"\n Food offered : Indian, Chinese, Italian and Live counters ";
            cout<<"\n Music facilities: Live DJ";
            cout<<" \n Location : Goregaon (W) ";
            cout<<"\n 1. Book ground \t 2. Exit ";
            cin>>book_ch;
            if(book_ch==1)
            {
                ground_booking();
            }
            break;
        }
        default:
        {
            cout<<"\n Invalid input, please refrain to the above two choices";
        }
    }
}



//----------------------------------------------------------------------------------------
void wedding()//wedding function
{   int guests;
    cout<<" \n What are the number of guests expected: \n";
    cin>>guests;
    if ( guests<=200)
    {
        cout<<" \n We recommend booking a Hall for the particular event \t \n";
        hall();
    }
    else if ( guests>200 && guests<1000)
    {
        cout<<" \n We recommend booking a Hotel for the particular event \t \n";
        wedding();
    }
    else
    {
        cout<<" \n We recommend booking a Ground for the particular event \t \n";
        ground();
    }
}


//----------------------------------------------------------------------------------------


void birthday()                 //birthday function
{   int guests;
    cout<<" \n What are the number of guests expected: \n ";
    cin>>guests;
    if ( guests<=200)
    {
        cout<<" \n We recommend booking a Hall for the particular event  \n";
         hall();
    }
    else if ( guests>200 && guests<1000)
    {
        cout<<" \n We recommend booking a Hotel for the particular event  \n";
        hotel();
    }
    else
    {
        cout<<" \n We recommend booking a Ground for the particular event \t \n";
        ground();
    }
}


//----------------------------------------------------------------------------------------



void baby()                 //baby shower function
{   int guests;
    cout<<" What are the number of guests expected:";
    cin>>guests;
    if ( guests<=200)
    {
        cout<<" We recommend booking a Hall for the particular event \t \n";
        hall();
    }
    else if ( guests>200 && guests<1000)
    {
        cout<<" We recommend booking a Hotel for the particular event \t \n";
        wedding();
    }
    else
    {
        cout<<"We recommend booking a Ground for the particular event \t \n";
        ground();
    }
}

//----------------------------------------------------------------------------------------



void menu()
{   int choice;
    cout<< "\n 1. Wedding Event \n 2. Birthday Parties \n 3. Baby Showers";
    cout<< "\n Enter your choice:";

    cin>> choice;
    switch(choice)
    {
        case 1:
            cout<<"\n Welcome to the Wedding Event Management tab" "\n";
            wedding();
            break;
        case 2:
            cout<<" \n Welcome to the Birthday Event Management tab" "\n" ;
            birthday();
            break;
        case 3:
            cout<<" \n Welcome to the Baby Shower Event Management tab \n";
            baby();
            break;
        default:
            cout<<" Invalid Input, please restrain to the first three choices. ";

    }

}



int main()
{   int choice;
    cout<< " EVENT MANAGERS" "\t \n";
    cout<< " Introduction paragraphs about us" "\n  " ;
    do
    {
        cout<<"\n Enter 1.Menu \t 2.Exit ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                menu();
                break;
            }
        }
    }while(choice!=2);



    return 0;

}
