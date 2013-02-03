#import <OpenGLES/ES1/gl.h> 
#import <OpenGLES/ES1/glext.h> 
#import "IRenderingEngine.hpp"

class RenderingEngine1 : public IRenderingEngine {
public:
    RenderingEngine1();
    void Initialize(int width, int height);
    void Render() const;
    void UpdateAnimation(float timeStep) {}
    void OnRotate(DeviceOrientation newOrientation) {}
private:
    GLuint m_framebuffer;
    GLuint m_renderbuffer; };

IRenderingEngine * CreateRenderer1()
{
    return new RenderingEngine1();
}

struct Vertex {
    float Position[2];
    float Color[4];
};
// Define the positions and colors of two triangles.

const Vertex Vertices[] = {
    {{-0.5, -0.866}, {1,1,0.5f,1}},
    {{0.5,  -0.866}, {1,1,0.5f,1}},
    {{0,    1     }, {1,1,0.5f,1}},
    {{-0.5, -0.866}, {0.5f,0.5f,0.5f}},
    {{0.5,  -0.866}, {0.5f,0.5f,0.5f}},
    {{0,    -0.4f},  {0.5f,0.5f,0.5f}}
};

RenderingEngine1::RenderingEngine1(){
    glGenRenderbuffersOES(1, &m_renderbuffer);
    glBindRenderbufferOES(GL_RENDERBUFFER_OES, m_renderbuffer);
}

void RenderingEngine1::Initialize(int width, int height)
{
    glGenFramebuffersOES(1, &m_framebuffer);
    glBindFramebufferOES(GL_FRAMEBUFFER_OES, m_framebuffer);
    glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES,GL_COLOR_ATTACHMENT0_OES, GL_RENDERBUFFER_OES, m_renderbuffer);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    // Initialize the projection matrix.
    const float maxX = 2;
    const float maxY = 3;
    glOrthof(-maxX, +maxX, -maxY, +maxY, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void RenderingEngine1::Render() const
{
    glClearColor(0.5f, 0.5f, 0.5f, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(2, GL_FLOAT, sizeof(Vertex), &Vertices[0].Position[0]);
    glColorPointer(4, GL_FLOAT, sizeof(Vertex), &Vertices[0].Color[0]);
    GLsizei vertexCount = sizeof(Vertices) / sizeof(Vertex);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}