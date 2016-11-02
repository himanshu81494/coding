#include <bits/stdc++.h>
using namespace std;

#define ll long long 
struct Entry{
  string Name;
  int Age;
  char Gender;
  Entry(string Name, int Age, char Gender){
    this->Name = Name;
    this->Age = Age;
    this->Gender = Gender;
  } 
};
void PrintVector(vector <Entry> e){
  for(int i=0;i<e.size();++i){
    cout<<e[i].Name<<"\t"<<e[i].Age<<"\t"<<e[i].Gender<<endl;
  }cout<<endl;
}
// struct Compare{
//   bool operator() (const Entry &a, const Entry &b){
//     return (a.Age < b.Age);
//   }
// };
// Compare()

// bool operator<(const Entry &a, const Entry &b) {return a.Age > b.Age;}
// NO
bool MyCompare(const Entry &a, const Entry &b) {return a.Age < b.Age;}
// &MyCompare
void fun(){
  vector<Entry> v;
  v.push_back(Entry("Kapil", 20, 'M'));
  v.push_back(Entry("Himanshu", 30, 'M'));
  v.push_back(Entry("Erica", 10, 'F'));
  v.push_back(Entry("Jessica", 40, 'F'));
  sort(v.begin(), v.end(), &MyCompare);
  PrintVector(v);
}
int main(int argc, char const *argv[])
{
  fun();
  return 0;
}
