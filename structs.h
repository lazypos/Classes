//
//  structs.h
//  redten
//
//  Created by zcw on 15-4-7.
//
// 游戏重要结构体

#ifndef redten_structs_h
#define redten_structs_h
#include <string>
using namespace std;

typedef enum _game_opt{
    opt_unknow = -1,
    opt_add_player, // 玩家加入
    opt_del_player, // 玩家离开
    opt_player_list, // 玩家列表
    opt_player_ready,// 玩家准备
    opt_player_chupai, // 玩家出牌
    opt_player_pass,   // 玩家pass
    opt_player_getout,    // 出牌结束,进入等待状态
    opt_game_start, // 游戏开始
    opt_game_over,  // 游戏结束
    opt_game_connect, // 连上服务器
    opt_game_disconnect, // 与服务器断开连接
}game_opt;

typedef struct _operator_message{
    game_opt    opt;
    string      content;
}optMsg;




#endif
