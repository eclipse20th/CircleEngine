#include "CeWindow.h"
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>
//#include <glad/glad.h>
//#include <Celib_x64/src/CeCommon/OpenGL/CeDraw.h>


int				CeGraphWindow::mWidth		= 800;
int				CeGraphWindow::mHeight		= 600;
bool			CeGraphWindow::isInit		= false;
CeGraphWindow*	CeGraphWindow::mCeWindow	= nullptr;
GLFWwindow*		CeGraphWindow::mGLFWWindow	= nullptr;

CeGraphWindow::CeGraphWindow(int aW, int aH)
{
	mWidth	= aW;
	mHeight = aH;
	mHWND	= initGLWindow();
}


CeGraphWindow::~CeGraphWindow()
{
}

int CeGraphWindow::initWindowAPI()
{
	int result = glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);//�汾���ã���汾�źͺ�С�汾��
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//opengl ��������
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);//�����Ƿ���Ըı��С
	//glfwWindowHint(GLFW_SAMPLES, 4);//�������ز�����û�ã�
	
	if (!result)
		return 0;
	return 1;
}

void CeGraphWindow::terminate()
{
	glfwTerminate();
}

HWND CeGraphWindow::initGLWindow()
{
	mGLFWWindow = glfwCreateWindow(mWidth, mHeight, "GraphicWindow", nullptr, nullptr);
	if (mGLFWWindow == nullptr)//������ڴ���ʧ�ܣ��������ڴ���	
	{
		glfwTerminate();
		return 0;
	}		

	//if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	//{
	//	std::cout << "Failed to initialize GLAD" << std::endl;
	//	return 0;
	//}


	HWND win_hd = glfwGetWin32Window(mGLFWWindow);	//���ͼ�δ��ڵ�window���	
	glfwMakeContextCurrent(mGLFWWindow);//ʹ��ĳ��ͼ�δ���Ϊ��ǰ�����Ĵ���Ĵ���
	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, 800, 600);
	//glfwSetWindowSize(mGLFWWindow,800,600);
	//glfwSetFramebufferSizeCallback(mGLFWWindow, FrameBufferSizeCallback);
	//glfwSetInputMode(mGLFWWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED); //��׽����ڴ����ڣ���������ʾ
	bindOpenGLCallback();
	return win_hd;
}

HWND CeGraphWindow::getWinHandle()
{
	return mHWND;
}
GLFWwindow*  CeGraphWindow::getGLFWWindow()
{
	return mGLFWWindow;
}

CeGraphWindow* CeGraphWindow:: createGLWindow()
{
	mCeWindow = new CeGraphWindow();
	return mCeWindow;
}

CeGraphWindow* CeGraphWindow::getGLWindow()
{
	return mCeWindow;
}

void CeGraphWindow::bindOpenGLCallback()
{
	//���ڴ�С
	glfwSetFramebufferSizeCallback(mGLFWWindow, frameBufferSizeCallback);
}

void CeGraphWindow::resizeWindow(int aWidth, int aHeight)
{
	glfwSetWindowSize(mGLFWWindow, aWidth, aHeight);
	glViewport(0, 0, aWidth, aHeight);
	mWidth = aWidth;
	mHeight = aHeight;
}

void CeGraphWindow::setWindowPosition(int aX, int aY)
{
	//SetWindowPos(mHWND,);
}

void CeGraphWindow::setViewport(const Vec2& aSize)
{
	glViewport(0, 0, aSize.x, aSize.y);
}

void CeGraphWindow::setViewport(int aWidth, int aHeight)
{
	glViewport(0, 0, aWidth, aHeight);
}

void CeGraphWindow::enableTest(EEnalbe aTest)
{
	//#define GL_SCISSOR_TEST                   0x0C11 
	//#define GL_ALPHA_TEST                     0x0BC0
	//#define GL_DEPTH_TEST                     0x0B71
	//#define GL_STENCIL_TEST                   0x0B90
	//����Opengl��һЩ����
	glEnable(aTest);
	
	//glEnable(0x809D);//�������ز�����
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void CeGraphWindow::disableTest(EEnalbe aTest)
{
	glDisable(aTest);
}

void CeGraphWindow::disableDepthWrite()
{
	glDepthMask(GL_FALSE);
}

void CeGraphWindow::enableDepthWrite()
{
	glDepthMask(GL_TRUE);
}

void CeGraphWindow::frameBufferSizeCallback(GLFWwindow *, int aWidth, int aHeight)
{
	//mWidth = aWidth;
	//mHeight = aHeight;
	//glViewport(0, 0, mWidth, mHeight);
}
