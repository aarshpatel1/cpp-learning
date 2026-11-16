
// #include <iostream>
// #include <string>
// using namespace std;

// class Student {
//   private:
//     int id;
//     string name;

//   public:
//     // Parameterized constructor
//     Student(int i, string n) {
//         id = i;
//         name = n;
//     }

//     // Copy constructor
//     Student(const Student &s) {
//         id = s.id;
//         name = s.name;
//     }

//     void display() {
//         cout << "ID: " << id << endl;
//         cout << "Name: " << name << endl;
//     }
// };

// int main() {
//     Student s1(101, "Aarsh");

//     // Copy constructor is called
//     Student s2(s1);
//     Student s3(s1);

//     cout << "Original Object:" << endl;
//     s1.display();

//     cout << "\nCopied Object:" << endl;
//     s2.display();
//     cout << "\nCopied Object:" << endl;
//     s3.display();

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Student {
//   private:
//     int id;
//     static int count; // Static data member

//   public:
//     Student(int i) {
//         id = i;
//         count++;
//     }

//     void display() { cout << "Student ID: " << id << endl; }

//     // Static member function
//     static void showCount() { cout << "Total Students: " << count << endl; }
// };

// // Definition of static data member
// int Student::count = 0;

// int main() {
//     Student s1(101);
//     Student s2(102);
//     Student s3(103);

//     s1.display();
//     s2.display();
//     s3.display();

//     Student::showCount();

//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     vector<int> nums = {4, 1, 2, 1, 2};
// 	// vector<int> nums = {1, 0, 1};
// 	// int index_to_remove = 2;

//     // cout << "capacity: " << nums.capacity() << endl;
//     // for (int i = 0; i < nums.size(); i++) {
//     //     if (i == index_to_remove)
//     //         nums.erase(nums.begin() + index_to_remove);
//     //     cout << nums.size() << endl;
//     // }
//     // cout << "capacity: " << nums.capacity() << endl;

//     for (int i = 0, j = nums.size() - 1; i < nums.size(); i++) {
//         if (nums[i] == nums[j]) {
//             nums.erase(nums.begin() + i);
//             nums.erase(nums.begin() + j);
//         }
//     }
// 	cout << nums[0];

//     return 0;
// }

#include <iostream>
int main() {
    int a = 3.14;
    int b = 22.31;
    float answer = b % a;
    std::cout << answer;
    return 0;
}