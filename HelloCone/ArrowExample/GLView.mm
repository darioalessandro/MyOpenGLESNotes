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
        CAEAGLLayer* eaglLayer = (CAEAGLLayer*) super.layer;
        eaglLayer.opaque = YES;
        EAGLRenderingAPI api = kEAGLRenderingAPIOpenGLES2;
        m_context = [[EAGLContext alloc] initWithAPI:api];
        if (!m_context || FALSE) {
            api = kEAGLRenderingAPIOpenGLES1;
            m_context = [[EAGLContext alloc] initWithAPI:api]; }
        if (!m_context || ![EAGLContext setCurrentContext:m_context]) { 
            return nil;
        }
        if (api == kEAGLRenderingAPIOpenGLES1) {
            m_renderingEngine = CreateRenderer1();
        } else {
            m_renderingEngine = CreateRenderer2();
        }
        [m_context renderbufferStorage:GL_RENDERBUFFER fromDrawable: eaglLayer];
        m_renderingEngine->Initialize(CGRectGetWidth(frame), CGRectGetHeight(frame));
        [self drawView: nil];
        m_timestamp = CACurrentMediaTime();
        CADisplayLink* displayLink= [CADisplayLink displayLinkWithTarget:self
                                                  selector:@selector(drawView:)];
        [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
        
        [[UIDevice currentDevice] beginGeneratingDeviceOrientationNotifications];
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(didRotate:)
                                                     name:UIDeviceOrientationDidChangeNotification
                                                   object:nil];
    }
    return self;
}

+ (Class) layerClass
{
    return [CAEAGLLayer class];
}

- (void) drawView: (CADisplayLink*) displayLink
{
    if (displayLink != nil) {
        float elapsedSeconds = displayLink.timestamp - m_timestamp;
        m_timestamp = displayLink.timestamp;
        m_renderingEngine->UpdateAnimation(elapsedSeconds);
    }
    m_renderingEngine->Render();
    [m_context presentRenderbuffer:GL_RENDERBUFFER];
}

- (void) didRotate: (NSNotification*) notification
{
    UIDeviceOrientation orientation = [[UIDevice currentDevice] orientation];
    m_renderingEngine->OnRotate((DeviceOrientation) orientation);
    [self drawView: nil];
}

- (void) dealloc
{
    if ([EAGLContext currentContext] == m_context)
        [EAGLContext setCurrentContext:nil];
}

@end
