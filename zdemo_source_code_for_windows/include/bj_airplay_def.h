
#ifndef BJ_AIRPLAY_DEF_H
#define BJ_AIRPLAY_DEF_H

typedef enum
{
	BJ_AIRPLAY_ERROR_SUCCESS = 0,		   ///成功
	BJ_AIRPLAY_ERROR_PORT_BINDERROR,
	BJ_AIRPLAY_ERROR_INIT_FAILED,
	BJ_AIRPLAY_ERROR_INIT_RAOP_FAILED,
	BJ_AIRPLAY_ERROR_BUTTON
}BJAirplayErrorCode;

typedef enum
{
    BJ_PLAYER_STATUS_LOADING = 0,    //���ڼ���
    BJ_PLAYER_STATUS_PLAYING,    //���ڲ���
    BJ_PLAYER_STATUS_PAUSED,     //��ͣ״̬
    BJ_PLAYER_STATUS_ENDED,      //���Ž���
    BJ_PLAYER_STATUS_FAILED,     //����ʧ��
}BJAirPlayerStatus;

#endif
