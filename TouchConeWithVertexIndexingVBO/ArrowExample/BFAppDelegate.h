//
//  BFAppDelegate.h
//  ArrowExample
//
//  Created by Dario Lencina on 2/3/13.
//  Copyright (c) 2013 Dario Lencina. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GLView.h"

@class BFViewController;

@interface BFAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (nonatomic, retain) IBOutlet GLView *m_view;

@end
