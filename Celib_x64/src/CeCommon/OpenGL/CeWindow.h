#pragma once 
#include <windows.h>
#include <iostream>
#include "../Common.h"

using namespace CircleEngine;
struct GLFWwindow;
typedef void(*CeWindowResiseCallback)(GLFWwindow*, int, int);

//#define GL_DEPTH_TEST                     0x0B71
//#define GL_DEPTH_WRITEMASK                0x0B72
//#define GL_DEPTH_CLEAR_VALUE              0x0B73
//#define GL_DEPTH_FUNC                     0x0B74
//#define GL_ACCUM_CLEAR_VALUE              0x0B80
//#define GL_STENCIL_TEST                   0x0B90
//#define GL_BLEND                          0x0BE2
enum EEnalbe
{
	EEB_DepthTest = 0x0B71,
	EEB_StencilTest = 0x0B90,
	EEB_Blend = 0x0BE2
};

/**
 * @breif CircleEngineͼ�δ�����
 * @detail 
 */
class CeGraphWindow 
{
public:
	//����
	CeGraphWindow(int aW = 800, int aH = 600);
	~CeGraphWindow();
public:

	/** @breif ����һ��ͼ�δ��� */
	static CeGraphWindow* createGLWindow();

	static int initWindowAPI();

	static void terminate();
public:

	/** @breif ���ͼ�δ���windows��� */
	HWND getWinHandle();

	/** @breif ���GLFW����ָ��*/
	static GLFWwindow* getGLFWWindow();	

	/** @breif ���CircleEngine��װ��ͼ�δ���ָ��*/
	static CeGraphWindow* getGLWindow();

public:
	//�������Է���

	/** @breif �޸Ĵ��ڴ�С*/
	static void resizeWindow(int aWidth, int aHeight);
	/** @breif ���ô���λ��*/
	static void setWindowPosition(int aX, int aY);
	/** @breif ��ô�������*/
	inline static Vec2 getWindowSize() { return Vec2(mWidth, mHeight); }

	static void setViewport(const Vec2& aSize);
	static void setViewport(int aWidth, int aHeight);

public:
	//��Ⱦ����

	/** @breif ������Ⱦ���ԣ���ȡ�ģ��ȣ�*/
	static void enableTest(EEnalbe aTest);

	/** @breif �ر���Ⱦ����*/
	static void disableTest(EEnalbe aTest);

	/** @breif û�йر���Ȳ��Ե��ǽ������ֵд��*/
	static void disableDepthWrite();
	static void enableDepthWrite();

public:
	//�¼�	

private:

	static void bindOpenGLCallback();

	static void frameBufferSizeCallback(GLFWwindow*, int, int);

	HWND initGLWindow();
private:
	//����
	HWND mHWND;
	static GLFWwindow * mGLFWWindow;	
	static CeGraphWindow* mCeWindow;
	static int mWidth;
	static int mHeight;
	static bool isInit;
};

