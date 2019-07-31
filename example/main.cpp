#include <stdio.h>
#include <stdlib.h>
#include "udp_sender.h"

enum FreespaceType {
  FreespaceType_Free = 0,
  FreespaceType_Curb = 1,
  FreespaceType_Object = 2
};

enum ObjectType {
  ObjectType_Car = 0,
  ObjectType_Person = 1
};

struct freespaceUnit {
  float distance;
  FreespaceType type;
};

struct objectUnit {
  float heading;
  float distanceX;
  float distanceY;
  float length;
  float width;
  float speedX;
  float speedY;
  uint32_t age;
  ObjectType type;
};

struct position {
  uint64_t timestamp;
  float x;
  float y;
  float z;
  float roll;
  float pitch;
  float yaw;
};

struct freespace {
  uint64_t timestamp;
  freespaceUnit free[360];
};

struct object {
  uint64_t timestamp;
  objectUnit object[20];
};

int main(int argc, char const *argv[]) {
  itd_lidar::UdpSender udpSender("192.168.188.135", 8080);
  struct objectUnit oData;
  oData.heading = 100.0;
  oData.distanceX = 2.9;
  oData.distanceY = 1.9;
  oData.length = 1.9;
  oData.width = 1.9;
  oData.speedX = 1.9;
  oData.speedY = 1.9;
  oData.age = 300;
  oData.type = ObjectType_Person;
  udpSender.Send((void*)&oData, sizeof(oData));
  return 0;
}
