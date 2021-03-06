// filename: room.h
#ifndef ROOM_H
#define ROOM_H

// #include "date.h"

#include <string>
#include <iostream>
using namespace std;
class Room {
 public:
   /**
    * constructor 构造函数
    * @param room_number    房间的编号(默认为" Unkonwn")
    * @param room_type 房间类型(默认为"standard room)
    * @param status    状态(0代表空)
    */
  Room (string room_number = "Unkonwn",
        string room_type = "standard room",
        bool status = false)
   :room_number(room_number), room_type(room_type), status(status){};

  void show(void) {
    cout << "room's room_number: "<< room_number << "\ntype: " << room_type
      << "\nThe room is " << (status ? "full" : "empty")<< endl;
  }

  /**
   * 入住酒店
   * @return 1代表不能入住
   */
  int check_in(){
    if(!status){
      cout << "The guests succeddfully checked in the room " << room_number << endl;
      status = true;
      return 0;
    }else{
      cout << "The room is full, you can't chick into this room" << endl;
      return 1;
    }
  }
  /**
   * 退房
   * @return 1 代表非法操作
   */
  int check_out(){
    if (status) {
      cout << "The gusest successfully checked out" << endl;
      status = false;
      return 0;
    } else {
      cout << "The room is empty, you can't do this" << endl;
      return 1;
    }
  }
  // friend ofstream &operator<<(ofstream & out, Room &a){
  //   out << a.room_number << "," << a.room_type
  //     << "," << (a.status ? "full" :"empty") << endl;
  //   return out;
  // }
  string get_room_number(){return room_number;}
  string get_room_type(){return room_type;}
  string get_status(){return (status ? "full" : "empty");}

 private:
  string room_number;
  string room_type;
  bool status;
};


#endif
