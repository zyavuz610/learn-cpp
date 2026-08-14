/*
The union is only as big as necessary to hold its largest data member. 
The other data members are allocated in the same bytes as part of that largest member. 
The details of that allocation are implementation-defined, 
and it's undefined behavior to read from the member of the union that wasn't most recently written. 
Many compilers implement, as a non-standard language extension, the ability to read inactive members of a union.
*/

#include <iostream>
#include <cstdint>
#include <cstring>

using namespace std;
union Ogrenci{
  char ad[30];          // 30 byte
  double araSinavNot;   // 8 byte
  double finalNot;      // 8 byte
  double ortalamaNot;   // 8 byte
  char harfNot[3];      // 3 byte
};                       // Ogrenci union 30 byte
                    
 
int main()
{
    Ogrenci o;
    strcpy(o.ad,"Ferdi");
    cout<<o.ad<<endl;
    o.araSinavNot = 123.0;
    cout<<showpoint<<o.araSinavNot<<endl;
    cout<<o.ad<<endl;
    return 0;
}


    /*
The purpose of union is to save memory by using the same memory region for 
    storing different objects at different times. That's it.
It is like a room in a hotel. Different people live in it for non-overlapping periods of time. 
    These people never meet, and generally don't know anything about each other. 
    By properly managing the time-sharing of the rooms 
    (i.e. by making sure different people don't get assigned to one room at the same time), 
     a relatively small hotel can provide accomodations to a relatively large number of people, 
     which is what hotels are for.
That's exactly what union does. If you know that several objects in your program hold values 
with non-overlapping value-lifetimes, then you can "merge" these objects into a union and thus save memory. 
Just like a hotel room has at most one "active" tenant at each moment of time, 
a union has at most one "active" member at each moment of program time. 
Only the "active" member can be read. 
By writing into other member you switch the "active" status to that other member.
*/
//===========================================================================
/*

Similarities between Structure and Union

- Both are user-defined data types used to store data of different types as a single unit.
- Their members can be objects of any type, including other structures and unions or arrays. 
    A member can also consist of a bit field.
- Both structures and unions support only assignment = and sizeof operators. 
    The two structures or unions in the assignment must have the same members and member types.
- A structure or a union can be passed by value to functions and returned by value by functions. 
    The argument must have the same type as the function parameter. 
    A structure or union is passed by value just like a scalar variable as a corresponding parameter.
- ‘.’ operator is used for accessing members.
*/
