//
//  parse_pack.hpp
//  HuaJiao
//
//  Created by LowBoy on 2017/8/12.
//  Copyright © 2017年 @LowBoyTeam. All rights reserved.
//

#ifndef parse_pack_hpp
#define parse_pack_hpp

#include <stdio.h>

#include "protocol/ChatRoom.pb.h"
#include "protocol/CommunicationData.pb.h"


void HandleBinaryMessage(const void* data, int size);
void parse_service_resp(const qihoo::protocol::messages::Message& message);
void parse_new_message_notify(const qihoo::protocol::messages::Message& message);
void parse_hand_shake_pack(const void* data, int size);
void parse_longin_response_pack(const void* data, int size);
void parse_message_pack(const void* data, int size);
void parse_chat_room_message(const std::string& data, qihoo::protocol::chatroom::ChatRoomPacket *message);
void parse_address_book_message(const void* data, int size, qihoo::protocol::messages::Message *message);
void parse_chat_room_new_message(const void* data, int size, qihoo::protocol::chatroom::ChatRoomNewMsg *message);
void parse_json_message(const std::string& message);
#endif /* parse_pack_hpp */
