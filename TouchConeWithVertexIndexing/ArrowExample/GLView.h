//
//  GLView.h
//  ArrowExample
//
//  Created by Dario Lencina on 2/3/13.
//  Copyright (c) 2013 Dario Lencina. All rights reserved.
//
#import "IRenderingEngine.hpp"
#import <UIKit/UIKit.h>
#import <OpenGLES/EAGL.h>
#import <QuartzCore/QuartzCore.h> 


@interface GLView : UIView{
    EAGLContext* m_context;
    struct IRenderingEngine* m_renderingEngine;
    float m_timestamp;
}

@end
