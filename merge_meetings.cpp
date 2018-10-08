// i/p: [(0, 1), (3, 5), (4, 8), (10, 12), (9, 10)]
// o/p: [(0, 1), (3, 8), (9, 12)]

#include <iostream>
#include <vector>
#include <algorithm>

struct Meeting; // define meeting

using it = std::vector<Meeting>::iterator;
using bi = std::back_insert_iterator<std::vector<Meeting>>;

struct Meeting{
  int start_date, end_date;
  Meeting() = default;
  Meeting(int start_date, int end_date): start_date{start_date}, end_date{end_date}{}

  bool operator <(const Meeting &other) const{
    return start_date < other.start_date;
  }

  static void merge(it start, it finish, bi merged_meeting_bi){
    int start_date = start->start_date;
    int end_date = start->end_date;
    while(start < finish){
      start++;
      if(start->start_date > end_date){
        merged_meeting_bi = {start_date, end_date};
        start_date = start->start_date;
        end_date = start->end_date;
      }else{
        end_date = std::max(start->end_date, end_date);
      }
    }
  }
};

int main(){
  std::vector<Meeting> meetings{{0, 1}, {3, 5}, {4, 8}, {10, 12}, {9, 10}};
  std::vector<Meeting> merged_meetings;
  auto bi = std::back_insert_iterator<std::vector<Meeting>>(merged_meetings);
  auto start = meetings.begin();
  auto finish = meetings.end();
  std::sort(start, finish);
  for(const auto &meeting :  meetings){
    std::cout << meeting.start_date << ' '  << meeting.end_date << '\n';
  }
  Meeting::merge(start, finish, bi);

  for(const auto & meeting: merged_meetings){
    std::cout << meeting.start_date << ' '  << meeting.end_date << '\n';
  }
  return 0;
}