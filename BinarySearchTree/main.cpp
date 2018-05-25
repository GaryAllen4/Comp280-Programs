/*
 * Author: Gary Allen
 * Date: 04/04/2018
 * Assignment: Program #5 - Binary Search Tree
 * File: main.cpp
 * Description: Exceutes the program
 */
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;


int main() {
    //object of the BinarySearchTree class used to call and run methods to execute the program
    BinarySearchTree treeObject;
    //used for letting the program know if the program should end or keep looping around
    bool programRunning = true;
    //used to intake a user provided course
    int courseNum;
    //used to take the user's input for a question
    string answer;
    //used for the user's choice of an option
    int optionum;
    while (programRunning) {
        cout << "Binary Search Tree Option Menu: " << endl;
        cout << "1. Insert Course Number" << endl;
        cout << "2. Delete a Course" << endl;
        cout << "3. Display Courses" << endl;
        cout << "4. End The Program." << endl;
        cout << "" << endl;
        cout << "Select an option number using an integer 1-4." << endl;
        cin >> optionum;
        if (optionum == 1) { //inserts values accepted from the user until they are finished
            //boolean variable used to continue or end the loop
            bool insertingCourse = true;
            while (insertingCourse) {
                cout << "Enter a COURSE NUMBER to insert into the tree." << endl;
                cin >> courseNum;
                treeObject.Insert(courseNum);
                cout << "Would you like to enter another course number?" << endl;
                cin >> answer;

                if (answer == "YES" | answer == "Yes" | answer == "yes") {

                } else {
                    insertingCourse = false;
                }

            }
        } else if (optionum == 2) { //deletes courses from the binary tree until the user is finished
            //boolean variable used to continue or end the loop
            bool deletingCourses = true;
            while (deletingCourses) {
                cout << "Do you want to delete a course number from the current tree?" << endl;
                cin >> answer;
                if (answer == "YES" | answer == "Yes" | answer == "yes") {
                    cout << "Enter a course to delete from the tree." << endl;
                    cin >> courseNum;
                    if (treeObject.IsThere(courseNum)) {
                        treeObject.Delete(courseNum);
                        treeObject.Display();
                    } else {
                        cout << "The course you entered does not currently exist. Use option 1 to insert new courses."
                             << endl;
                        cout << "" << endl;
                    }
                } else {
                    deletingCourses = false;
                }
            }
        } else if (optionum == 3) { //displays the full list of courses entered by the user and the amount of students interested
            cout << "LIST OF COURSES: " << endl;
            treeObject.Display();
            cout << "LIST OF COURSES WITH MORE THAN ONE STUDENT INTERESTED: " << endl;
            treeObject.DeleteAllOnes();//delete courses with just one student interested
            treeObject.Display();
            cout << "" << endl;
        } else if (optionum == 4) { //displays all courses with more than one student interested
            cout << "Would you like to run the program again?" << endl;
            cin >> answer;
            if (answer == "YES" | answer == "Yes" | answer == "yes") {
                main();
            } else {
                break;
            }
        } else  { //give the user a choice to proceed with ending the program or running it again
            cout << "INVALID INPUT!" << endl;
            cout << "" << endl;
        }

    }
}