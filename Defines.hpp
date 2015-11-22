#ifndef DEFINES_HPP
#define DEFINES_HPP

//#define RES_X 1024
//#define RES_Y 768

#define FPS 60.0
#define GRID 60

#define PLAYER_VELOCITY 8
#define SCREEN_PROJECTILES 150		//Max number of projectiles on the screen;

//Network protocol

#define PROTOCOL_N_PEERS 0x01
#define PROTOCOL_MAP_FILE 0x02
#define PROTOCOL_SET_POS_TEAM 0x03
#define PROTOCOL_CHARACTER 0x04
#define PROTOCOL_NEW_USER 0x05
#define PROTOCOL_MY_WEAPON 0x06
#define PROTOCOL_NEW_SHOOT 0x07
#define PROTOCOL_DISCONNECT 0x08
#define PROTOCOL_DELETE_BULLET 0x09
#define PROTOCOL_REVIVE 0x0a
#define PROTOCOL_HIT 0x0b

#endif