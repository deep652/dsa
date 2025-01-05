#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "complexComparatorDemo.h"

using namespace std;

class Student
{
    public:
    string name;
    int age;
    int marks;
    Student(){}
    Student(string name, int age, int marks):name(name), age(age), marks(marks){}
    friend ostream & operator<<(ostream &os, const Student &s);
};

ostream & operator<<(ostream &os, const Student &s)
{
        cout<< "Student name is "<< s.name<<" and age is "<<s.age<<"Marks is " <<s.marks<<endl;
        return os;
} 

//I want to first check normal sort order of the map if I use age as the key and object as the value

//the below will not work, as comparator will work only on the key, not the value stuff
// class Comp
// {
//     public:
//     bool operator()(const pair<int, Student > &p1, const pair<int, Student> & p2) const
//     {
//         return (p1.second.marks < p2.second.marks);//return true, if you want to place p1 before p2
//     }
// };


class Comp
{
    public:
    bool operator()(const Student &p1, const  Student & p2) const
    {
        return (p1.marks < p2.marks);//return true, if you want to place p1 before p2
    }
};


int main()
{
    map<int, Student> Dict;
    Student s1("Deep", 40, 11);
    Student s2("Vikash", 23, 33);
    Student s3("Monu", 10, 44);
    Student s4("Sonu", 46, 23);

    Dict[s1.age] = s1;
    Dict[s2.age] = s2;
    Dict[s3.age] = s3;
    Dict[s4.age] = s4;

    for(pair<int, Student> x: Dict)
    {
        cout<<"Key is " << x.first<< "\t" << x.second<<endl;
    }
    // output is as below
    // Key is 10	Student name is Monu and age is 10

    // Key is 23	Student name is Vikash and age is 23

    // Key is 40	Student name is Deep and age is 40

    // Key is 46	Student name is Sonu and age is 46

    //Note the above is acending order of age.

    //Now lets sort based on the marks of the student

    map<Student, int, Comp> SpecialDict;

    SpecialDict[s1] = s1.age;
    SpecialDict[s2] = s2.age;
    SpecialDict[s3] = s3.age;
    SpecialDict[s4] = s4.age;

    for(pair<Student, int> x: SpecialDict)
    {
        cout<<"Key is " << x.first<< "\t" << x.second<<endl;
    }

    // Key is Student name is Deep and age is 40Marks is 11
    //     40
    // Key is Student name is Sonu and age is 46Marks is 23
    //     46
    // Key is Student name is Vikash and age is 23Marks is 33
    //     23
    // Key is Student name is Monu and age is 10Marks is 44
    //     10

    // Note, the sorting is done in asc order on marks of the Student :)

    
    return 0;
}