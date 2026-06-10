#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
// Ek person ko represent karne ke liye
struct User {
  int id;
  string name;

  User() = default;
  User(int id, const string& name) : id{id}, name(name) {}
};
// isko use kaise karenge?
// User u1(1,"Alice")
// aise use karenge isko.

enum class splitType {
  // ye basically mapping hai number se variables ka
  equal,
  exact,
  percent
  // jis order me likhenge us order me hi numbering hogi.
};

struct expense {
  // koi bhi expense ko uniquely determine karne ke liye uska alag se Id
  // fir kisne pay kiya hai wo
  // aur kitne logo me split karna hai wo.
  int id, groupId, payerId;
  double amount;       // kitna pay kiya hai.
  splitType choice;    // kaise split karna hai.
  string description;  // kis chiz par spend kiya
  map<int, double> splits;

  expense() = default;
  expense(int id, int groupId, int payerId, double amount,
          const string& description, splitType choice)
      : id{id},
        groupId(groupId),
        payerId{payerId},
        amount{amount},
        description{description},
        choice{choice} {}

  // jaise split ho jayega toh ye pata chalega ki kon kisko kitna owe karta hai
  // ek particular expense ke baad ye hame pata chalega splits wale map se.
};

struct Group {
  int id;                  // group ko uniquely identify karna
  string name;             // for ex-> trip,office,etc
  vector<int> memberIds;   // user ke ids store honge isme
  vector<int> expenseIds;  // expense ke Ids store honge

  // we need one function to check whether a person with uid = x exists in this
  // group or not.
  bool inThisGroup(int x) {
    for (auto memberId : memberIds) {
      if (memberId == x) return true;
    }
    return false;
  }
};

struct Transaction{
    int from,to;
    double amount;
};
// We can go without this structure as well but in this way 
// we would be able to code it neatly.


int main() {}