

#ifndef BJ_AIRPLAY_ITF_H_
#define BJ_AIRPLAY_ITF_H_

#include <stdint.h>
#include <stdarg.h>

#include <jni.h>

#ifdef BJ_AIRPLAY_EXPORTS
#define BJ_AIRPLAY_API
#else
#define BJ_AIRPLAY_API __attribute__((visibility ("default")))
#endif

//BJ_AIRPLAY_FLAGS
#define BJ_AIRPLAY_SUPPORT_ROTATION_FLAG (0x00000001)
#define BJ_AIRPLAY_SUPPORT_URL_FLAG (0x00000002)
#define BJ_AIRPLAY_SUPPORT_MBNAUL_FLAG (0x00000004)
#define BJ_AIRPLAY_DISABLE_MBNAUL_FLAG (0x00000008)
#define BJ_AIRPLAY_SUPPORT_SPSPPSNAUL_FLAG (0x00000010)


typedef enum
{
    BJAir_Resolution_1080P = 0,
    BJAir_Resolution_720P = 1,
    BJAir_Resolution_800x600 = 2,
    BJAir_Resolution_1600x900 = 3,
    BJAir_Resolution_2560x1440 = 4,
    BJAir_Resolution_3840x2160 = 5,
    BJAir_Resolution_Button
}BJAirResolutionType;

typedef enum
{
    BJAir_RepublishType_Normal = 0,
    BJAir_RepublishType_Remove_And_Publish = 1,
    BJAir_RepublishType_Button
}BJAirRepublishType;

typedef struct BJAirPlayAbility
{
    int maxFPS;
    int resolution_type; //ȡֵ��Χ�ο�BJAirResolutionType
}BJAirPlayAbility;

typedef enum {
    BJAir_LOG_CRIT = 1,
    BJAir_LOG_ERROR,
    BJAir_LOG_WARN,
    BJAir_LOG_INFO,
    BJAir_LOG_DEBUG,
    BJAir_LOG_DETAIL,
    BJAir_LOG_MAX,
}BJAirplayLogLevel;


typedef struct {
	/** ��ʼ����Ͷ������
	*
	*     ��ʼ���񲥷ŻỰ�����û�������Ͷ����URL���Żص����񲥷ŵȳ����ᴥ���ýӿڡ�
	*     @param playerId  ���ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	*     @param ip ������豸��IP��ַ
	*     @param device_model ������豸���豸�ͺţ���iphone6
	*     @param device_name ������豸���豸����
	*     @return    eg:@retval 0:Ӧ�ò㿪ʼ���ųɹ� @retval other:Ӧ�ò㲥��ʧ�ܣ�SDK�ڲ�������ûỰ��
	*     @note   Ӧ����Ҫ��סplayerId����playerId������ά������Ự��������ؽӿڶ�ͨ�����ֶν��й�����
	*/
	int32_t (*OnStartMirrorPlayer)(uint32_t playerId, const char* ip, const char* device_model, const char* device_name);

	/**
	* \brief           Write mirror audio PCM frame to player.
	* \param bitsdep   bitsdep of audio, 16 is default.
	* \param channels  channels of audio, 2 is default.
	* \param sampleRate sampleRate of audio, 44100 is default. .
	* \return          void
	*/
	void (*NotifyMirrorAudioCodecInfo)(uint32_t playerId, int32_t bitsdep, int32_t channels, int32_t sampleRate);

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
	uint32_t(*OnMirrorAudioData)(uint32_t playerId, const uint8_t *p_src, uint32_t size, int64_t ptsValue);

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
	uint32_t(*OnMirrorVideoData)(uint32_t playerId, const uint8_t *p_src, uint32_t size, int64_t ptsValue);

	/** ���񲥷���Ƶ��ת�Ƕ�֪ͨ
	*
	*     ��IPAD/IPHONE���ն�
	*     @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	*     @param angle ��Ƶ��ת�Ƕȣ�����ȡֵ��ΧΪ0,90,180,270�����нǶ�Ϊ˳ʱ�뷽��Ƕȡ�
	*     @return    ��
	*     @note   ��Ӧ���յ����¼��󣬲�������Ҫ���ݸýǶ���������ת��������ȷ��ʾ��Ƶ��
	*/
	void(*OnRotateMirrorVideo)(uint32_t playerId, int angle);

	/** ֹͣ���񲥷�
	*
	*     ֹͣ���񲥷ŻỰ�����û�ֹͣ����Ͷ�����ɾ���Ͷ���л���URL���ŵȳ����ᴥ���ýӿڡ�
	*     @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	*     @return    ��
	*     @note   Ӧ����Ҫ�ͷŸûỰ�����Դ��
	*/
	void(*OnStopMirrorPlayer)(uint32_t playerId);


	/** ��������
	*
	*     ֹͣ���񲥷ŻỰ�����û�ֹͣ����Ͷ�����ɾ���Ͷ���л���URL���ŵȳ����ᴥ���ýӿڡ�
	*     @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	*     @param volumePercent,��������,0:���� 100:�������
	*     @return    ��
	*     @note   Ӧ����Ҫ�ͷŸûỰ�����Դ��
	*/
	void(*SetVolume)(uint32_t playerId, int volumePercent);


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
	int32_t(*OnStartAudioPlayer)(uint32_t playerId, const char* ip, const char* device_model, const char* device_name);

	/** ֪ͨ��Ƶ����ʱ�ķ���ͼƬ
	*
	*     ��Ƶ����ʱ����ǰ���ŵ����ֵķ���ͼƬ��JPEG��ʽ��
	*     @param playerId  ���ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	*     @param p_src JPEGͼƬ����
	*     @param size JPEGͼƬ���ݳ���
	*     @note   Ӧ��Ӧ�ý�ͼƬ�������־û����ļ������г��֡�android��δʵ��
	*/
	void(*RefreshCoverArtFromBuffer)(uint32_t playerId, const uint8_t *p_src, int size);



    /** ֪ͨ��Ƶ����ʱ��album,title,artist
     * \brief         Refresh audio ID3 information on UI.
     * The function may not be necessary.
     *
     * \param album   The audio album.
     * \param title   The audio title.
     * \param artist  The audio artist.
     * \return        void
     */
    void(*RefreshTrackInfo)(uint32_t playerId, const char* album, const char* title, const char* artist);


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
	uint32_t(*OnAudioData)(uint32_t playerId, const uint8_t *p_src, uint32_t size, int64_t ptsValue);


	/** ֹͣ����Ƶ����
	*
	*     ֹͣ���񲥷ŻỰ�����û�ֹͣ����Ͷ�����ɾ���Ͷ���л���URL���ŵȳ����ᴥ���ýӿڡ�
	*     @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	*     @return    ��
	*     @note   Ӧ����Ҫ�ͷŸûỰ�����Դ��
	*/
	void(*OnStopAudioPlayer)(uint32_t playerId);

	/** ֪ͨ���ֲ���ʱ��Ƶ���ݵĸ�ʽ
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @param bitsdep   bitsdep of audio, 16 is default.
	* @param channels  channels of audio, 2 is default.
	* @param sampleRate sampleRate of audio, 44100 is default. .
	* @return          void
	*/
	void(*NotifyAudioCodecInfo)(uint32_t playerId, int32_t bitsdep, int32_t channels, int32_t sampleRate);

	/** ��ʼURL��Ƶ���ŻỰ
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @param url	   Ҫ���ŵ���ƵURL
	* @return    eg:@retval 0:Ӧ�ò㿪ʼ���ųɹ� @retval other:Ӧ�ò㲥��ʧ�ܣ�SDK�ڲ�������ûỰ��
	*/
	int32_t(*OnStartVideoPlayback)(uint32_t playerId, const char* ip, const char *url);

	/** ����URL��Ƶ���ŻỰ
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @return    void
	* @note   Ӧ��Ӧ���ͷŲ������������Դ
	*/
	void(*OnStopVideoPlayback)(uint32_t playerId);

	/** ����URL��Ƶ���ŻỰ
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @return    void
	* @note   Ӧ��Ӧ���ͷŲ������������Դ
	*/
	void(*OnPauseVideoPlayback)(uint32_t playerId);

	/** ��������URL��Ƶ���ŻỰ
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @return    void
	* @note   ��ͣ���������
	*/
	void(*OnResumeVideoPlayback)(uint32_t playerId);

	/** ����URL��Ƶ����Seek
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @param position_sec���������϶���λ�ã���λ��
	* @return    void
	* @note   �������϶����ڼ��벥��
	*/
	void(*OnSeekVideoBySec)(uint32_t playerId, int64_t position_sec);

	/** ��ȡ����������URL��ǰ������λ��
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @return int32_t ��ǰ�����������ŵ���λ�ã���λΪ����
	* @note   ���ص�ǰ�����������ŵ���λ�ã���λΪ����
	*/
	int32_t(*OnGetVideoPositionMSec)(uint32_t playerId);

    /** ��ȡ��������ǰ�Ĳ���״̬
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @return int32_t ȡֵ��Χ�ο�BJAirPlayerStatus
	* @note
	*/
    int32_t(*OnGetVideoPlayerStatus)(uint32_t playerId);

	/** ��ȡURL����ʱ��
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @return int32_t ��ȡURL����ʱ������λΪ����
	* @note
	*/
	int32_t(*OnGetVideoDurationMSec)(uint32_t playerId);

	/**��ʼ����
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @param ip ������豸��IP��ַ
	* @return    eg:@retval 0:Ӧ�ò㿪ʼ���ųɹ� @retval other:Ӧ�ò㲥��ʧ�ܣ�SDK�ڲ�������ûỰ��
	* @note  ios9��ǰϵͳ֧��
	*/
	int32_t(*OnStartPhotoPlayer)(uint32_t playerId, const char* ip);

	/**��ʼ����
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @param picData, ָ��ͼƬ���ݵ�ָ��
	* @param size, ���ݵĴ�С
	* @return void
	* @note ios9��ǰϵͳ֧��
	*/
	void(*OnPlayPhoto)(uint32_t playerId, const uint8_t* picData, int size);

	/**��������
	* @param playerId�����ŻỰID(��ID��SDK�ڲ�ͳһ���䣬ȫ��Ψһ)
	* @return void
	* @note ios9��ǰϵͳ֧��
	*/
	void(*OnStopPhotoPlayer)(uint32_t playerId);

	/**��ʾPIN��
	* @param ip
	* @param pincode
	* @return void
	* @note
	*/
	void(*OnShowPinCode)(const char* ip,const char* pincode);

	/**PIN����֤�ɹ�
	* @param ip
	* @return void
	* @note
	*/
	void(*OnVerifyPinSuccess)(const char* ip);

    /**��ĳ������˷���Ͷ��ʱ��SDK�ص��ýӿڣ���ȡ���֡�ʺͷֱ��ʲ���
	* @param ip
	* @return void
	* @note
	*/
    void(*OnProbePlayerAbility)(const char* ip, BJAirPlayAbility* const ability);

    /**�û��Զ������־�����ӿ�
	* @param level
	* @return void
	* @note
	*/
    void(*LogFun)(unsigned int level, const char *format,  va_list argp);
} BJAirplayFunctionCbs_t;

/**
* BJAirplay Sdk�ĳ�ʼ���ṹ��
*/
typedef struct
{
	char friendly_name[128];           ///Airplay���ն˵���ʾ���ƣ�����iPhone/IPad���豸��������Airplay���ն˵�����
	int  framerate;                    ///ȡֵ��Χ15-60; >60������Ϊ60  <15������Ϊ15
	int  resolution_type;              ///resolution_type ȡֵ��Χ�ο�BJAirResolutionType
	char password[256];				   ///Ͷ������
	char licenseKey[1024];			   ///License��Ϣ����License�ļ��ж�ȡ
	//char itf_name[32];                 ///�Ӹýӿڻ�ȡMAC��ַ
	char mac_addr[32];                 ///��ʽ:00:26:b9:52:7b:e0
    int airplay_flags;			       ///�ο�BJ_AIRPLAY_FLAGS���壬λ������
	int max_session_nums;              ///���nums ȡֵ��Χ1-9
	int republish_mode;                ///BJAir_RepublishType_Normal:normal repubsh BJAir_RepublishType_Remove_And_Publish:remove service and publish ȡֵ��Χ�ο�:BJAirRepublishType
    int log_level;                     ///��־����,ȡֵ��Χ�ο�BJAirplayLogLevel
    BJAirplayFunctionCbs_t callback;   ///�û��ص��ӿڣ���Ҫ���û�����ʵ��
}AirplayInitPara;

typedef void(*UserDefinePrint)(const char* message);

#ifdef  __cplusplus
extern "C" {
#endif

/** ��ʼ��BJAirplay SDK
*
*     ��ʼ��BJAirplay SDK��
*     @param JNIEnv *env:Ӧ�ô���env,sdk �����envʹ���豸��Ӳ����Ϣ
*     @param initpara ��ʼ���ṹ��
*     @return    eg:@retval 0 BJAirplay SDK��ʼ���ɹ� @retval other: BJAirplay SDK��ʼ��ʧ�ܡ�
*     @note   Ӧ����Ҫ�ͷŸûỰ�����Դ��
*/
BJ_AIRPLAY_API int  InitBJAirplay(JNIEnv *env,AirplayInitPara* initpara);

/** ����BJAirplay ����Ͷ������
*
*     @param password
*     @note   ���øýӿڱ��뱣֤��ǰû���κ�Airplay�Ự����,���򷵻�-1
*     @ret   0:success -1:not support
*/
BJ_AIRPLAY_API int SetAirplayPassword(const char *password);

/** ����BJAirplay �޸�airplay����
*
*     @param name
*/
BJ_AIRPLAY_API void ServiceRename(const char* name);

/** ����BJAirplay republish airplay����
*
*     @param name
*/
BJ_AIRPLAY_API void ServiceRepublish();


/** ǿ���˳�ĳһ·Airplay����
*
*     ǿ���˳�ĳһ·Airplay����
*     @param playerId ���ŻỰID
*     @note   SDK�ڲ��Ὣairplay�Ựǿ�ƽ���
*/
BJ_AIRPLAY_API void  KickOut(uint32_t playerId);

BJ_AIRPLAY_API void UninitBJAirplay();

/** ��̬������־����
*
*     ��̬������־����
*     @param level ȡֵ��Χ�ο�BJAirplayLogLevel
*     @note
*/

BJ_AIRPLAY_API void SetAirplayLogLevel(int level);

#ifdef  __cplusplus
}
#endif

#endif
