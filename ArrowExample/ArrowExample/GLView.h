//
//  GLView.h
//  ArrowExample
//
//  Created by Dario Lencina on 2/3/13.
//  Copyright (c) 2013 Dario Lencina. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <OpenGLES/EAGL.h>
#import <QuartzCore/QuartzCore.h> 
#import <OpenGLES/ES1/gl.h> 
#import <OpenGLES/ES1/glext.h>

@interface GLView : UIView{
    EAGLContext* m_context;
}
- (void) drawView;
@end
