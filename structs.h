//
//  structs.h
//  redten
//
//  Created by zcw on 15-4-7.
//
//

#ifndef redten_structs_h
#define redten_structs_h

typedef enum _game_opt{
    opt_add_player = 0, // 玩家加入
    opt_del_player, // 玩家离开
    opt_player_list, // 玩家列表
    opt_player_ready,// 玩家准备
    opt_player_chupai, // 玩家出牌
    opt_player_pass,   // 玩家pass
    opt_player_getout,    // 出牌结束,进入等待状态
    opt_game_start, // 游戏开始
    opt_game_over,  // 游戏结束
}game_opt;



#endif
