//
//  GLView.m
//  ArrowExample
//
//  Created by Dario Lencina on 2/3/13.
//  Copyright (c) 2013 Dario Lencina. All rights reserved.
//

#import "GLView.h"

@implementation GLView

- (id) initWithFrame: (CGRect) frame
{
    if (self = [super initWithFrame:frame]) {
        CAEAGLLayer* eaglLayer = (CAEAGLLayer*) super.layer; eaglLayer.opaque = YES;
        m_context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES1];
        if (!m_context || ![EAGLContext setCurrentContext:m_context]) {
            return nil;
        }
        [self initOpenGLESWithLayer:eaglLayer andFrame:frame];
    }

    return self;
}

-(void)initOpenGLESWithLayer:(CAEAGLLayer *)eaglLayer andFrame:(CGRect)frame{
    GLuint framebuffer, renderbuffer; glGenFramebuffersOES(1, &framebuffer); glGenRenderbuffersOES(1, &renderbuffer);
    glBindFramebufferOES(GL_FRAMEBUFFER_OES, framebuffer);
    glBindRenderbufferOES(GL_RENDERBUFFER_OES, renderbuffer);
    [m_context renderbufferStorage:GL_RENDERBUFFER_OES fromDrawable: eaglLayer];
    glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_RENDERBUFFER_OES, renderbuffer);
    glViewport(0, 0, CGRectGetWidth(frame), CGRectGetHeight(frame));
    [self drawView];
}

+ (Class) layerClass
{
    return [CAEAGLLayer class];
}

-(void)drawView{
    glClearColor(0.5f, 0.5f, 0.5f, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    [m_context presentRenderbuffer:GL_RENDERBUFFER_OES];
}

- (void) dealloc
{
    if ([EAGLContext currentContext] == m_context)
        [EAGLContext setCurrentContext:nil];
}

@end
