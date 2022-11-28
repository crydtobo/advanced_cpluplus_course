#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <array>
#include <map>

class Date{
  public:

    Date(unsigned int d, unsigned int m, unsigned int year){
      day = d;
      month = m;
      year = year;
    }

    //std::string name{};
    unsigned int day{};
    unsigned int month{};
    unsigned int year{};
};

struct Date2{
  int d,m,y;
  std::string name;
};

using Date3 = std::tuple<int, int, int>;


int main() {
  //std::initializer_list<Date> data {Date(3, 4,1996), Date(12, 4, 2002)};
  std::vector<Date> data {Date{3, 4,1996}, Date{12, 4, 2002}};

  [[__attribute_maybe_unused__]] const auto birthdates = std::vector<Date>{{3, 4,1996}, {3, 12,1996}};

  [[__attribute_maybe_unused__]] const std::map<std::string, Date3> birthMap{
    {"Jan Naj", {3,12,2002}}
  };

  // for(auto start = data.begin(); start != data.end(); start++){
  //   std::cout << "Dzien: " << start->day << "\n";  
  // }

  return 0;
}
