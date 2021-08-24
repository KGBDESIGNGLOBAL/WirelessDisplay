#pragma once
#include "bj_airplay.h"

class BJAirplayCallbackImp
{
public:

	static int32_t OnStartMirrorPlayer(uint32_t playerId, const char* ip, const char* device_model, const char* device_name);

	/**
	* \brief           Write mirror audio PCM frame to player.
	* \param bitsdep   bitsdep of audio, 16 is default.
	* \param channels  channels of audio, 2 is default.
	* \param sampleRate sampleRate of audio, 44100 is default. .
	* \return          void
	*/
	static void NotifyMirrorAudioCodecInfo(uint32_t playerId, int32_t bitsdep, int32_t channels, int32_t sampleRate);

	/** ֪ͨӦ�þ�����Ƶ����
	*
	*     ����Ͷ�������У�SDK�յ���Ƶ���ݺ����н��룬�����øýӿ�֪ͨӦ�ò��Ѿ������PCM��Ƶ���ݡ�
	*     @param playerId ���ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	*     @param p_src   ָ����Ƶ���ݿ��ָ��
	*     @param size    ��Ƶ���ݿ�ĳ���
	*     @param ptsValue ��Ƶ���ݶ�Ӧ��ʱ���
	*     @return Copied size. (unit: byte)
	*     @note   Ӧ���յ���Ƶ���ݺ�����н��벢���ţ�ͬʱ��Ҫ����ʱ�������Ƶ��ͬ�����ơ�
	*/
	static uint32_t OnMirrorAudioData(uint32_t playerId, const uint8_t *p_src, uint32_t size, int64_t ptsValue);

	/** ֪ͨӦ�þ�����Ƶ����
	*
	*     ����Ͷ�������У�SDK�յ���Ƶ���ݺ����øýӿ�֪ͨӦ�ò��յ���H264��Ƶ���ݡ�
	*     @param playerId ���ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	*     @param p_src ָ����Ƶ���ݿ��ָ��
	*     @param size    ��Ƶ���ݿ�ĳ���
	*     @param ptsValue ��Ƶ���ݶ�Ӧ��ʱ���
	*     @return Copied size. (unit: byte)
	*     @see    NotifyMirrorAudioCodecInfo()  ��Ƶ�Ĳ�������Ϣͨ��NotifyMirrorAudioCodecInfo֪ͨӦ��
	*     @note   Ӧ���յ���Ƶ���ݺ�����н��벢���ţ�ͬʱ��Ҫ����ʱ�������Ƶ��ͬ�����ơ�
	*/
	static uint32_t OnMirrorVideoData(uint32_t playerId, const uint8_t *p_src, uint32_t size, int64_t ptsValue);

	/** ���񲥷���Ƶ��ת�Ƕ�֪ͨ
	*
	*     ��IPAD/IPHONE���ն�
	*     @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	*     @param angle ��Ƶ��ת�Ƕȣ�����ȡֵ��ΧΪ0,90,180,270�����нǶ�Ϊ˳ʱ�뷽��Ƕȡ�
	*     @return    ��
	*     @note   ��Ӧ���յ����¼��󣬲�������Ҫ���ݸýǶ���������ת��������ȷ��ʾ��Ƶ��
	*/
	static void OnRotateMirrorVideo(uint32_t playerId, int angle);

	/** ֹͣ���񲥷�
	*
	*     ֹͣ���񲥷ŻỰ�����û�ֹͣ����Ͷ�����ɾ���Ͷ���л���URL���ŵȳ����ᴥ���ýӿڡ�
	*     @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	*     @return    ��
	*     @note   Ӧ����Ҫ�ͷŸûỰ�����Դ��
	*/
	static void OnStopMirrorPlayer(uint32_t playerId);

	/** ��ʼ����Ƶ����
	*
	*     ��ʼ���񲥷ŻỰ�����û�������Ͷ����URL���Żص����񲥷ŵȳ����ᴥ���ýӿڡ�
	*     @param playerId  ���ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	*     @param ip ������豸��IP��ַ
	*     @param device_model ������豸���豸�ͺţ���iphone6
	*     @param device_name ������豸���豸����
	*     @return    eg:@retval 0:Ӧ�ò㿪ʼ���ųɹ� @retval other:Ӧ�ò㲥��ʧ�ܣ�SDK�ڲ�������ûỰ��
	*     @note   Ӧ����Ҫ��סplayerId����playerId������ά�����ŻỰ��������ؽӿڶ�ͨ�����ֶν��й�����
	*/
	static int OnStartAudioPlayer(uint32_t playerId, const char* ip, const char* device_model, const char* device_name);

	/** ֪ͨӦ����Ƶ��������
	*
	*     ����ƵͶ�������У�SDK�յ���Ƶ���ݺ����н��룬�����øýӿ�֪ͨӦ�ò��Ѿ������PCM��Ƶ���ݡ�
	*     @param playerId ���ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	*     @param p_src   ָ����Ƶ���ݿ��ָ��
	*     @param size    ��Ƶ���ݿ�ĳ���
	*     @param ptsValue ��Ƶ���ݶ�Ӧ��ʱ���
	*     @return Copied size. (unit: byte)
	*     @note   Ӧ���յ���Ƶ���ݺ�����н��벢���ţ�ͬʱ��Ҫ����ʱ�������Ƶ��ͬ�����ơ�
	*/
	static uint32_t OnAudioData(uint32_t playerId, const uint8_t *p_src, uint32_t size, int64_t ptsValue);

	static void RefreshCoverArtFromBuffer(uint32_t playerId, const uint8_t *p_src, int size);

	static void SetVolume(uint32_t playerId, int volumePercent);

	/** ֹͣ����Ƶ����
	*
	*     ֹͣ���񲥷ŻỰ�����û�ֹͣ����Ͷ�����ɾ���Ͷ���л���URL���ŵȳ����ᴥ���ýӿڡ�
	*     @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	*     @return    ��
	*     @note   Ӧ����Ҫ�ͷŸûỰ�����Դ��
	*/
	static void OnStopAudioPlayer(uint32_t playerId);

	/** ֪ͨ���ֲ���ʱ��Ƶ���ݵĸ�ʽ
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @param bitsdep   bitsdep of audio, 16 is default.
	* @param channels  channels of audio, 2 is default.
	* @param sampleRate sampleRate of audio, 44100 is default. .
	* @return          void
	*/
	static void NotifyAudioCodecInfo(uint32_t playerId, int32_t bitsdep, int32_t channels, int32_t sampleRate);

    static void RefreshTrackInfo(uint32_t playerId, const char* album, const char* title, const char* artist);

	/** ��ʼURL��Ƶ���ŻỰ
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @param url	   Ҫ���ŵ���ƵURL
	* @return    eg:@retval 0:Ӧ�ò㿪ʼ���ųɹ� @retval other:Ӧ�ò㲥��ʧ�ܣ�SDK�ڲ�������ûỰ��
	*/
	static int32_t OnStartVideoPlayback(uint32_t playerId, const char *ip, const char *url);

	/** ����URL��Ƶ���ŻỰ
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @return    void
	* @note   Ӧ��Ӧ���ͷŲ������������Դ
	*/
	static void OnStopVideoPlayback(uint32_t playerId);

	/** ����URL��Ƶ���ŻỰ
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @return    void
	* @note   Ӧ��Ӧ���ͷŲ������������Դ
	*/
	static void OnPauseVideoPlayback(uint32_t playerId);
	static void OnResumeVideoPlayback(uint32_t playerId);
	static void OnSeekVideoBySec(uint32_t playerId, int64_t position);
	static int32_t OnGetVideoPositionMSec(uint32_t playerId);
	static int32_t OnGetVideoDurationMSec(uint32_t playerId);
    static int32_t OnGetVideoPlayerStatus(uint32_t playerId);


    /**��ʼ����
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @param ip ������豸��IP��ַ
	* @return    eg:@retval 0:Ӧ�ò㿪ʼ���ųɹ� @retval other:Ӧ�ò㲥��ʧ�ܣ�SDK�ڲ�������ûỰ��
	* @note  ios9��ǰϵͳ֧��
	*/
	static int32_t OnStartPhotoPlayer(uint32_t playerId, const char* ip);

	/**��ʼ����
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @param picData, ָ��ͼƬ���ݵ�ָ��
	* @param size, ���ݵĴ�С
	* @return void
	* @note ios9��ǰϵͳ֧��
	*/
	static void OnPlayPhoto(uint32_t playerId, const uint8_t* picData, int size);

	/**��������
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @return void
	* @note ios9��ǰϵͳ֧��
	*/
	static void OnStopPhotoPlayer(uint32_t playerId);


    static void OnShowPinCode(const char* ip,const char* pincode);

	/**PIN����֤�ɹ�
	* @param ip
	* @return void
	* @note
	*/
	static void OnVerifyPinSuccess(const char* ip);


    static void OnProbePlayerAbility(const char* ip, BJAirPlayAbility* const ability);
};

