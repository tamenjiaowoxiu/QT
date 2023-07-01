#ifndef CONFIG_H
#define CONFIG_H

/*********** 游戏配置数据 ************/
#define GAME_WIDTH 1320
#define GAME_HEIGHT 820
#define GAME_TITLE "kakaxirun"
#define GAME_RES_PATH "./kakaxi.rcc"
#define GAME_ICON ":/res/xxx.ico" // 图标加载路径
#define GAME_RATE 10 //刷新率 单位毫秒



/*********** 地图配置数据 ************/
#define MAP_PATH ":/res/senlin.png" /*//地图资源位置*/
#define MAP_SCROLL_SPEED 2 //地图滚动速度
#define MAP_FLOOR1 ":/res/tile73.png" //地板第一块
#define MAP_FLOOR2 ":/res/tile72.png" //地板第二块
#define MAP_WALL1 ":/res/tile68.png" //墙第一块
#define MAP_WALL10 ":/res/tile87.png" //墙一下面
#define MAP_WALL20 ":/res/tile88.png" //墙一下面
#define MAP_WALL2 ":/res/tile63.png" //墙第二块
#define MAP_FLOOR3 ":/res/tile42.png" //地板第二层
#define MAP_PLANT ":/res/tile108.png" //平台（可s改变取消的那个bool值导致可以下落）
#define MAP_TRAP ":/res/tile110.png"  //陷阱
#define MAP_WATER1 ":/res/water1.png" //水
#define MAP_WATER2 ":/res/water2.png" //水
#define MAP_WATER3 ":/res/water3.png" //水
#define MAP_WATER4 ":/res/water4.png" //水
#define MAP_WALLIN1 ":/res/tile11.png" //墙内
#define MAP_WALLIN2 ":/res/tile11.png"
#define MAP_KEY ":/res/key.png" //钥匙
#define MAP_HOME ":/res/success.png" //通关房子

/*********** 人物配置数据 ************/
#define HERO_PATH ":/res/kakaxi_right.png" //人物图片
#define HERO_SPEED 25 //人物跳跃速度
#define HERO_SPEED1 5 //人物下落速度

/*********** 手里剑配置数据 ************/
#define BULLET_PATH ":/res/Shoulijian1.png" //手里剑图片
#define BULLET_SPEED 5 //手里剑移动速度
#define BULLET_NUM 100 //手里剑袋中剑的个数
#define BULLET_INTERVAL 50 //发射手里剑时间的间隔（防止自动发射太快）

/*********** 敌人路径 ************/
#define ENEMY_PATH ":/res/enemy_left.png"
#define ENEMY_PATH1 ":/res/enemy_right.png"
#define ENEMY_SPEED 2 //敌人移动速度
#define ENEMY_NUM 20 //敌人总数量
#define ENEMY_INTERVAL 30 //出场时间间隔

/*********** 爆炸配置属性 ************/
#define BOMB_PATH ":/res/water%1.png"
#define BOMB_NUM 5 //爆炸数量
#define BOMB_MAX 5 //爆炸图片最大索引
#define BOMB_INTERVAL 20 //爆炸切图时间间隔

/*********** 音乐 ************/
#define SOUND_BACKGROUND ":/res/bg.wav"
#define SOUND_BOMB ":/res/yuanp(1).mp3"
#endif // CONFIG_H
