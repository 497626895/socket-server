#ifndef __WINSOCKMATTRANSMISSIONSEVER_H__  
#define __WINSOCKMATTRANSMISSIONSEVER_H__  
#include "opencv2/opencv.hpp"  
#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/imgproc/imgproc.hpp"  
#include "opencv2/core/core.hpp"  
#include <stdio.h>  
#include <Winsock2.h>  
#pragma comment(lib,"WS2_32.lib")  
#define IMG_WIDTH 500  
#define IMG_HEIGHT 350    
#define BUFFER_SIZE IMG_WIDTH*IMG_HEIGHT*3/32  
struct recvbuf
{
	char buf[BUFFER_SIZE];
	int flag;
};
class WinsockMatTransmissionServer
{
public:
	WinsockMatTransmissionServer(void);
	~WinsockMatTransmissionServer(void);
private:
	SOCKET sockConn;
	struct recvbuf data;
public:

	int socketConnect(int PORT);// 打开socket连接  
 
	int receive(cv::Mat& image);// 传输图像 
	void socketDisconnect(void);	// 断开socket连接 
};
#endif 